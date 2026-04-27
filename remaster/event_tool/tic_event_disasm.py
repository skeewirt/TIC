"""
Disassemble extracted .e event scripts using Gibbed's byte-packed format.
Each file is raw bytecode: [1-byte opcode][N bytes operands][next opcode]...
"""
import struct, json, sys, os
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

with open(r'C:\Projects\TIC\remaster\event_tool\opcode_table.json') as f:
    table = json.load(f)

# Build lookup: opcode -> (name, enhanced_byte_size)
sizes = {}
names = {}
for key, val in table.items():
    op = int(key, 16)
    sizes[op] = val.get('operand_bytes_enhanced', val.get('operand_bytes_classic', 0))
    names[op] = val['name']

def disassemble(data, label=""):
    lines = []
    off = 0
    instr_count = 0
    errors = 0
    while off < len(data):
        opbyte = data[off]
        name = names.get(opbyte, f'UNKNOWN_0x{opbyte:02X}')
        size = sizes.get(opbyte, 0)
        
        if off + 1 + size > len(data):
            lines.append(f"  @{off:04X}  [{opbyte:02X}] {name} (TRUNCATED - need {size} bytes, {len(data)-off-1} remain)")
            errors += 1
            break
        
        operands = data[off+1:off+1+size]
        
        # Format operands based on type
        if size == 0:
            lines.append(f"  @{off:04X}  {name}")
        else:
            op_parts = []
            for b in operands:
                op_parts.append(f'{b:02X}')
            lines.append(f"  @{off:04X}  {name:<35s}  {' '.join(op_parts)}")
        
        off += 1 + size
        instr_count += 1
    
    return lines, instr_count, errors

# Test with event010.e (small, likely the Orbonne Monastery intro)
test_files = ['event010.e', 'event002.e', 'event100.e']
script_dir = r'C:\Projects\TIC\reference\event_scripts\script\classic'

for fname in test_files:
    fpath = os.path.join(script_dir, fname)
    if not os.path.exists(fpath):
        print(f"\n{fname}: NOT FOUND")
        continue
    
    with open(fpath, 'rb') as f:
        data = f.read()
    
    print(f"\n{'='*60}")
    print(f"  {fname} ({len(data)} bytes)")
    print(f"{'='*60}")
    
    # Check if file starts with Pad bytes (0xF2)
    pad_byte = 0xF2
    if len(data) >= 4 and all(b == pad_byte for b in data[:4]):
        print("  (Starts with 4x Pad bytes - FFTPack format header)")
    
    # Show first 16 bytes as hex
    print(f"  First 16 bytes: {' '.join(f'{b:02X}' for b in data[:16])}")
    
    lines, count, errs = disassemble(data)
    print(f"  Instructions: {count}, Errors: {errs}")
    print()
    for line in lines[:40]:
        print(line)
    if len(lines) > 40:
        print(f"  ... ({len(lines) - 40} more instructions)")
