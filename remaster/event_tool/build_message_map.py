"""
TIC PZD Message Map Builder

Parses PZD (Panzer Data Format) text files extracted from the game's PAC archives
and builds a JSON mapping of global message IDs to dialogue text.

PZD files use an NXD-like row index format with a rotating 7-column layout.
Message IDs are stored as u32 fields followed by field-relative text pointers.

Usage:
    python build_message_map.py <pzd_directory> [-o output.json]

The default PZD directory is the extracted nxd/text tree from the game data.
Output is a JSON file mapping message ID strings to dialogue text strings.
"""
import struct, sys, os, json, argparse
sys.stdout.reconfigure(encoding='utf-8', errors='replace')


def get_full_text(data, off):
    """Read null-terminated UTF-8 text, walking backwards to find string start."""
    if off < 0 or off >= len(data):
        return None
    start = off
    while start > 0 and data[start - 1] != 0:
        start -= 1
    end = data.find(b'\x00', start)
    if end <= start or end - start > 10000:
        return None
    try:
        return data[start:end].decode('utf-8', errors='replace')
    except:
        return None


def parse_pzd(path):
    """
    Extract {message_id: dialogue_text} from a single PZD file.

    Strategy: scan the data region for the repeating 7-column pattern where
    a u32 in the message ID range (60k-500k) is followed by a field-relative
    text pointer and a speaker ID.
    """
    with open(path, 'rb') as f:
        data = f.read()

    if len(data) < 0x28 or data[:4] != b'PZDF':
        return {}

    messages = {}

    # Scan every aligned u32 in the data region for message ID candidates
    for off in range(0x30, len(data) - 12, 4):
        val = struct.unpack_from('<I', data, off)[0]

        # Message IDs fall in the 60k-500k range
        if val < 60000 or val > 500000:
            continue

        # Next field should be a relative text pointer
        text_ptr_off = off + 4
        text_ptr_val = struct.unpack_from('<I', data, text_ptr_off)[0]
        text_abs = text_ptr_off + text_ptr_val

        # Validate: pointer should land within the file
        if text_abs <= 0 or text_abs >= len(data):
            continue

        text = get_full_text(data, text_abs)
        if not text or len(text) == 0:
            continue

        # Skip voice/sound paths
        if text.startswith('sound/') or text.startswith('scenario/'):
            continue

        # Accept this message
        if val not in messages:
            messages[val] = text

    return messages


def main():
    parser = argparse.ArgumentParser(
        description='Build message ID -> dialogue text map from PZD files')
    parser.add_argument('input', nargs='?',
                        help='PZD directory tree (searches recursively for .pzd files)')
    parser.add_argument('-o', '--output', default='message_map.json',
                        help='Output JSON file (default: message_map.json)')
    args = parser.parse_args()

    if not args.input:
        # Default: look for extracted PZD files relative to this script
        default = os.path.join(os.path.dirname(__file__),
                               '..', '..', 'reference', 'nxd_extract_en', 'nxd', 'text')
        if os.path.isdir(default):
            args.input = default
        else:
            parser.error('No PZD directory specified and default path not found.\n'
                         'Extract PZD files first with FF16Tools, then pass the path.')

    # Recursively find and parse all PZD files
    all_messages = {}
    file_count = 0

    for dirpath, _, filenames in os.walk(args.input):
        for fname in sorted(filenames):
            if not fname.endswith('.pzd'):
                continue
            path = os.path.join(dirpath, fname)
            msgs = parse_pzd(path)
            if msgs:
                all_messages.update(msgs)
                file_count += 1

    # Save
    with open(args.output, 'w', encoding='utf-8') as f:
        json.dump({str(k): v for k, v in sorted(all_messages.items())},
                  f, indent=2, ensure_ascii=False)

    print(f'Parsed {file_count} PZD files')
    print(f'Extracted {len(all_messages)} message entries')
    print(f'Saved to {args.output}')


if __name__ == '__main__':
    main()
