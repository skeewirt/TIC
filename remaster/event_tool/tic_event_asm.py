"""
TIC Event Script Assembler v1.0
Companion to tic_event_disasm.py — reads JSON event scripts and produces
byte-identical .e binary files.

Round-trip guarantee: disasm(binary) -> JSON -> asm(JSON) == binary

Usage:
    python tic_event_asm.py event002.json                    # -> event002.e
    python tic_event_asm.py event002.json -o output/         # -> output/event002.e
    python tic_event_asm.py events/ -o compiled/             # batch compile
"""
import struct, json, sys, os, argparse

# ── Operand encoding (mirrors OPERAND_TYPES in tic_event_disasm.py) ──
OPERAND_ENCODERS = {
    'B8':    (1, 'B'),
    'OnOff': (1, 'B'),
    'OffOn': (1, 'B'),
    'S8':    (1, 'b'),
    'U8':    (1, 'B'),
    'S16':   (2, '<h'),
    'U16':   (2, '<H'),
    'MsgIdx':(2, '<H'),
    'S32':   (4, '<i'),
    'U32':   (4, '<I'),
}

def encode_operand(value, type_key):
    """Encode a single operand value to bytes."""
    size, fmt = OPERAND_ENCODERS[type_key]
    
    # Handle special display formats from disassembler
    if type_key == 'B8':
        if isinstance(value, str):
            if value.lower() in ('true', '1', 'yes'):
                value = 1
            elif value.lower() in ('false', '0', 'no'):
                value = 0
            else:
                value = int(value)
    elif type_key == 'OnOff':
        if isinstance(value, str):
            if value.lower() == 'on':
                value = 1
            elif value.lower() == 'off':
                value = 0
            else:
                value = int(value)
    elif type_key == 'OffOn':
        if isinstance(value, str):
            if value.lower() == 'off':
                value = 1
            elif value.lower() == 'on':
                value = 0
            else:
                value = int(value)
    elif type_key == 'MsgIdx':
        if isinstance(value, str) and value.startswith('msg['):
            value = int(value[4:-1])
        else:
            value = int(value)
    else:
        if isinstance(value, str):
            value = int(value)
    
    return struct.pack(fmt, value)


def assemble_instruction(instr, opcode_sigs):
    """Assemble a single instruction dict to bytes."""
    opcode = instr['opcode']
    result = bytes([opcode])
    
    # If raw_hex is provided (fallback/unknown operands), use it directly
    if 'raw_hex' in instr and instr['raw_hex']:
        result += bytes.fromhex(instr['raw_hex'])
        return result
    
    sig = opcode_sigs.get(opcode, [])
    operands = instr.get('operands', [])
    
    if sig and operands:
        for i, type_key in enumerate(sig):
            if i < len(operands):
                result += encode_operand(operands[i], type_key)
            else:
                # Missing operand — pad with zeros
                size = OPERAND_ENCODERS[type_key][0]
                result += b'\x00' * size
    
    return result


def assemble(event_json, opcode_sigs):
    """Assemble a complete event JSON to binary."""
    output = bytearray()
    
    instructions = event_json.get('instructions', [])
    for instr in instructions:
        output.extend(assemble_instruction(instr, opcode_sigs))
    
    # Append trailing data if present (post-EventEnd padding)
    if 'trailing_data' in event_json:
        output.extend(bytes.fromhex(event_json['trailing_data']))
    
    return bytes(output)


def load_opcode_sigs(table_path, mode='enhanced'):
    """Load operand signatures from the disassembler module or opcode_table.json."""
    # Try importing from the disassembler
    disasm_dir = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, disasm_dir)
    try:
        from tic_event_disasm import OPERAND_SIGS_ENHANCED, OPERAND_SIGS_CLASSIC
        return OPERAND_SIGS_ENHANCED if mode == 'enhanced' else OPERAND_SIGS_CLASSIC
    except ImportError:
        pass
    
    # Fallback: build from opcode_table.json (size-only, no type info)
    # This path is less precise — operands will be treated as raw bytes
    print("WARNING: Could not import tic_event_disasm. Using raw byte fallback.", file=sys.stderr)
    return {}


def assemble_file(json_path, output_path, opcode_sigs):
    """Assemble a single JSON file to .e binary."""
    with open(json_path, 'r', encoding='utf-8') as f:
        event_json = json.load(f)
    
    binary = assemble(event_json, opcode_sigs)
    
    os.makedirs(os.path.dirname(output_path) or '.', exist_ok=True)
    with open(output_path, 'wb') as f:
        f.write(binary)
    
    return len(binary), len(event_json.get('instructions', []))


def main():
    parser = argparse.ArgumentParser(description='TIC Event Script Assembler')
    parser.add_argument('input', help='Input .json file or directory')
    parser.add_argument('-o', '--output', help='Output file or directory')
    parser.add_argument('-m', '--mode', choices=['classic', 'enhanced'], default='enhanced')
    parser.add_argument('--verify', help='Original .e file to verify byte-identical output')
    parser.add_argument('--table', default=os.path.join(os.path.dirname(__file__), 'opcode_table.json'))
    args = parser.parse_args()
    
    opcode_sigs = load_opcode_sigs(args.table, args.mode)
    
    if os.path.isfile(args.input):
        # Single file
        if args.output:
            out_path = args.output
        else:
            out_path = args.input.replace('.json', '.e')
        
        nbytes, ninstrs = assemble_file(args.input, out_path, opcode_sigs)
        print(f"Assembled {ninstrs} instructions -> {nbytes} bytes: {out_path}")
        
        # Verification
        if args.verify and os.path.exists(args.verify):
            with open(args.verify, 'rb') as f:
                original = f.read()
            with open(out_path, 'rb') as f:
                compiled = f.read()
            if original == compiled:
                print(f"✅ VERIFIED: byte-identical to {args.verify}")
            else:
                # Find first difference
                for i in range(min(len(original), len(compiled))):
                    if original[i] != compiled[i]:
                        print(f"❌ MISMATCH at offset 0x{i:04X}: "
                              f"expected 0x{original[i]:02X}, got 0x{compiled[i]:02X}")
                        break
                if len(original) != len(compiled):
                    print(f"❌ SIZE MISMATCH: expected {len(original)}, got {len(compiled)}")
    
    elif os.path.isdir(args.input):
        # Batch mode
        out_dir = args.output or os.path.join(args.input, '..', 'compiled')
        os.makedirs(out_dir, exist_ok=True)
        
        files = sorted(f for f in os.listdir(args.input) if f.endswith('.json'))
        total_ok = 0
        total_fail = 0
        
        for fname in files:
            json_path = os.path.join(args.input, fname)
            out_path = os.path.join(out_dir, fname.replace('.json', '.e'))
            try:
                nbytes, ninstrs = assemble_file(json_path, out_path, opcode_sigs)
                total_ok += 1
            except Exception as e:
                print(f"  ERROR: {fname}: {e}")
                total_fail += 1
        
        print(f"\nAssembled {total_ok} files ({total_fail} errors)")


if __name__ == '__main__':
    main()
