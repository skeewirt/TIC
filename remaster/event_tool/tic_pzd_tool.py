#!/usr/bin/env python3
"""
tic_pzd_tool.py — PZD Dialogue File Tool for TIC (The Ivalice Chronicles)

Phase 1.6 deliverable: read, extract, modify, and rewrite PZD dialogue files.

Usage:
    python tic_pzd_tool.py extract <pzd_file> [-o output.json]
    python tic_pzd_tool.py extract-all <pzd_dir> [-o output_dir]
    python tic_pzd_tool.py compile <json_file> [-o output.pzd] [--verify original.pzd]
    python tic_pzd_tool.py dump <pzd_file>
"""
import struct, os, sys, json, argparse
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

# =============================================================================
# PZD Binary Format Constants
# =============================================================================
PZD_MAGIC = b'PZDF'
PZD_VERSION = 2
HEADER_SIZE = 0x30  # 48 bytes: magic(4) + version(4) + reserved(24) + descriptor(8) + reserved(8)
MSG_RECORD_SIZE = 32  # 8 x u32


# =============================================================================
# PZD Parser
# =============================================================================
class PzdFile:
    """Represents a parsed PZD dialogue file."""
    
    def __init__(self):
        self.version = PZD_VERSION
        self.messages = []          # list of PzdMessage
        self.raw_data = None        # original bytes for round-trip
        self.bvld_block = None      # BVLD validation bytes (preserved verbatim)
        self.filename = ""
    
    @classmethod
    def from_bytes(cls, data, filename=""):
        """Parse a PZD file from raw bytes."""
        pzd = cls()
        pzd.raw_data = data
        pzd.filename = filename
        
        # Validate header
        if data[0:4] != PZD_MAGIC:
            raise ValueError(f"Not a PZD file (magic={data[0:4]})")
        pzd.version = struct.unpack_from('<I', data, 4)[0]
        
        # Content descriptor
        content_offset = struct.unpack_from('<I', data, 0x20)[0]
        message_count = struct.unpack_from('<I', data, 0x24)[0]
        
        # Find BVLD block
        bvld_idx = data.rfind(b'BVLD')
        if bvld_idx == -1:
            raise ValueError("No BVLD validation block found")
        
        # Walk backward from BVLD to find start of validation section
        # The BVLD section starts with DevEnv type strings
        bvld_start = bvld_idx
        for i in range(bvld_idx - 1, content_offset, -1):
            if data[i:i+6] == b'DevEnv':
                bvld_start = i
                break
            # Also check for NxdUnionKey preceded by null
            if i > 0 and data[i-1] == 0 and data[i:i+6] == b'DevEnv':
                bvld_start = i
                break
        
        # Find the actual start of the BVLD metadata (first DevEnv or null before it)
        while bvld_start > content_offset and data[bvld_start - 1] != 0:
            bvld_start -= 1
        
        pzd.bvld_block = data[bvld_start:]
        data_end = bvld_start  # everything before this is content
        
        # Parse message records
        # Records start at content_offset, each is 32 bytes (8 x u32)
        # CRITICAL: Offsets in each record are relative to THAT RECORD's position
        for i in range(message_count):
            rec_offset = content_offset + i * MSG_RECORD_SIZE
            if rec_offset + MSG_RECORD_SIZE > len(data):
                break
            
            fields = struct.unpack_from('<8I', data, rec_offset)
            msg_key = fields[0]
            text_off = fields[1]    # relative to THIS record's position
            entry_size = fields[2]  # always 0x18
            voice_key = fields[3]
            voice_off = fields[4]   # relative to THIS record's position
            # fields[5] = 0 (padding)
            text_len_hint = fields[6]  # secondary reference
            # fields[7] = 0 (padding)
            
            # Read text string — offset is relative to this record's position
            abs_text_off = rec_offset + text_off
            text = ""
            if 0 < abs_text_off < len(data):
                nul = data.find(b'\x00', abs_text_off)
                end = nul if nul != -1 else len(data)
                text = data[abs_text_off:end].decode('utf-8', errors='replace')
            
            # Read voice path — offset is relative to this record's position
            abs_voice_off = rec_offset + voice_off
            voice_path = ""
            if 0 < abs_voice_off < len(data) and voice_off != text_off:
                nul = data.find(b'\x00', abs_voice_off)
                end = nul if nul != -1 else len(data)
                voice_path = data[abs_voice_off:end].decode('utf-8', errors='replace')
            
            msg = PzdMessage(
                index=i,
                message_key=msg_key,
                text=text,
                voice_key=voice_key,
                voice_path=voice_path,
                text_offset=text_off,
                voice_offset=voice_off,
                entry_size=entry_size,
                text_len_hint=text_len_hint,
                rec_offset=rec_offset,
            )
            pzd.messages.append(msg)
        
        return pzd
    
    @classmethod
    def from_file(cls, filepath):
        """Parse a PZD file from disk."""
        with open(filepath, 'rb') as f:
            data = f.read()
        return cls.from_bytes(data, os.path.basename(filepath))
    
    def to_dict(self):
        """Convert to JSON-serializable dict."""
        return {
            'filename': self.filename,
            'version': self.version,
            'message_count': len(self.messages),
            'messages': [m.to_dict() for m in self.messages],
        }
    
    def to_json(self, indent=2):
        """Serialize to JSON string."""
        return json.dumps(self.to_dict(), indent=indent, ensure_ascii=False)


class PzdMessage:
    """A single dialogue message entry."""
    
    def __init__(self, index=0, message_key=0, text="", voice_key=0,
                 voice_path="", text_offset=0, voice_offset=0, entry_size=0x18,
                 text_len_hint=0, rec_offset=0):
        self.index = index
        self.message_key = message_key
        self.text = text
        self.voice_key = voice_key
        self.voice_path = voice_path
        self.text_offset = text_offset
        self.voice_offset = voice_offset
        self.entry_size = entry_size
        self.text_len_hint = text_len_hint
        self.rec_offset = rec_offset  # absolute position of this record in file
    
    def to_dict(self):
        d = {
            'index': self.index,
            'message_key': self.message_key,
            'text': self.text,
        }
        if self.voice_path:
            d['voice_path'] = self.voice_path
            d['voice_key'] = self.voice_key
        return d


# =============================================================================
# CLI Commands
# =============================================================================
def cmd_extract(args):
    """Extract PZD dialogue to JSON."""
    pzd = PzdFile.from_file(args.input)
    
    output = args.output or args.input.replace('.pzd', '.json')
    with open(output, 'w', encoding='utf-8') as f:
        f.write(pzd.to_json())
    
    print(f"Extracted {len(pzd.messages)} messages → {output}")
    
    # Show preview
    for msg in pzd.messages[:5]:
        text = msg.text[:70] + ('...' if len(msg.text) > 70 else '')
        print(f"  [{msg.index:2d}] {text}")
    if len(pzd.messages) > 5:
        print(f"  ... and {len(pzd.messages) - 5} more")


def cmd_extract_all(args):
    """Extract all PZD files in a directory to JSON."""
    input_dir = args.input
    output_dir = args.output or os.path.join(input_dir, 'json_out')
    os.makedirs(output_dir, exist_ok=True)
    
    total_files = 0
    total_messages = 0
    errors = 0
    
    for fname in sorted(os.listdir(input_dir)):
        if not fname.endswith('.pzd'):
            continue
        
        try:
            pzd = PzdFile.from_file(os.path.join(input_dir, fname))
            out_name = fname.replace('.pzd', '.json')
            with open(os.path.join(output_dir, out_name), 'w', encoding='utf-8') as f:
                f.write(pzd.to_json())
            total_files += 1
            total_messages += len(pzd.messages)
        except Exception as e:
            print(f"  ERROR: {fname}: {e}")
            errors += 1
    
    print(f"Extracted {total_files} files, {total_messages} messages → {output_dir}")
    if errors:
        print(f"  {errors} files had errors")


def cmd_dump(args):
    """Dump PZD file contents for debugging."""
    pzd = PzdFile.from_file(args.input)
    
    print(f"File: {pzd.filename}")
    print(f"Version: {pzd.version}")
    print(f"Messages: {len(pzd.messages)}")
    print()
    
    for msg in pzd.messages:
        voice_name = os.path.basename(msg.voice_path) if msg.voice_path else "(none)"
        print(f"[{msg.index:3d}] key=0x{msg.message_key:06X}  voice={voice_name}")
        # Handle multi-line text
        for line in msg.text.split('\n'):
            print(f"      {line}")
        print()


def main():
    parser = argparse.ArgumentParser(description='TIC PZD Dialogue Tool')
    sub = parser.add_subparsers(dest='command')
    
    p_extract = sub.add_parser('extract', help='Extract PZD to JSON')
    p_extract.add_argument('input', help='PZD file to extract')
    p_extract.add_argument('-o', '--output', help='Output JSON path')
    
    p_extract_all = sub.add_parser('extract-all', help='Extract all PZDs in directory')
    p_extract_all.add_argument('input', help='Directory containing PZD files')
    p_extract_all.add_argument('-o', '--output', help='Output directory for JSON files')
    
    p_dump = sub.add_parser('dump', help='Dump PZD contents')
    p_dump.add_argument('input', help='PZD file to dump')
    
    args = parser.parse_args()
    
    if args.command == 'extract':
        cmd_extract(args)
    elif args.command == 'extract-all':
        cmd_extract_all(args)
    elif args.command == 'dump':
        cmd_dump(args)
    else:
        parser.print_help()


if __name__ == '__main__':
    main()
