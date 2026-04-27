"""
TIC Event Disassembler v0.3 
Fixed NXD record layout understanding:

Each event sub-entry has:
  - 7-word (28-byte) header: [field0, PTR1, field2, field3, field4, PTR2, field6]
  - N bytes of raw instruction data (no embedded pointers!)
  - Instructions are flat u32 stream: [opcode, param1, param2, ..., opcode, param1, ...]

PTR1 -> instruction definition table (0xBBD4-0x2E65A range)
PTR2 -> metadata table (0x2EC88-0x2F1EC range)

The instruction data after the header IS the actual opcode stream,
with each opcode followed by its parameter count of u32 values.
"""
import struct
import json
import sys
import os

sys.stdout.reconfigure(encoding='utf-8', errors='replace')

# Load opcode table
with open(r'C:\Projects\TIC\remaster\event_tool\opcode_table.json', 'r') as f:
    raw_table = json.load(f)
OPCODES = {}
for key, val in raw_table.items():
    OPCODES[int(key, 16)] = (val['name'], val['params'])

def disassemble_stream(data, start, length, event_id, sub_id):
    """Disassemble a pure u32 instruction stream."""
    lines = []
    lines.append(f"# Event {event_id}, Sub {sub_id}")
    lines.append(f"# Offset: 0x{start:X}, {length} bytes")
    
    if length < 4:
        lines.append("  (empty)")
        return '\n'.join(lines)
    
    pos = 0
    instr_num = 0
    while pos < length - 3:
        val = struct.unpack_from('<I', data, start + pos)[0]
        
        if val in OPCODES:
            name, param_count = OPCODES[val]
            params = []
            for p in range(param_count):
                ppos = pos + 4 + p * 4
                if ppos + 4 <= length:
                    pval = struct.unpack_from('<I', data, start + ppos)[0]
                    params.append(pval)
                else:
                    params.append(None)
            
            param_strs = []
            for p in params:
                if p is None:
                    param_strs.append('?')
                elif p > 0xFFFF:
                    param_strs.append(f'0x{p:X}')
                else:
                    param_strs.append(str(p))
            
            lines.append(f"  {instr_num:3d}  {name}({', '.join(param_strs)})")
            pos += 4 + param_count * 4
            instr_num += 1
        else:
            # Unknown value - output as data
            if val > 0xFFFF:
                lines.append(f"  {instr_num:3d}  .data 0x{val:08X}")
            elif val > 0:
                lines.append(f"  {instr_num:3d}  .data {val}")
            else:
                lines.append(f"  {instr_num:3d}  .zero")
            pos += 4
            instr_num += 1
    
    return '\n'.join(lines)

# Parse the NXD
path = r'C:\Projects\TIC\reference\nxd_extract\nxd\enhancedbattleevent.nxd'
with open(path, 'rb') as f:
    nxd = f.read()

# Extract all event targets
data_section = 0x2428C
targets = []
rec_off = data_section
while rec_off + 20 <= len(nxd) - 100:
    zero, _, flags, group, sub = struct.unpack_from('<iIIII', nxd, rec_off)
    ptr_pos = rec_off + 4
    neg_off = struct.unpack_from('<i', nxd, ptr_pos)[0]
    target = ptr_pos + neg_off
    if target < 0x30 or target > 0x2428C:
        break
    targets.append((group, sub, target))
    rec_off += 20

# Sort targets by offset for boundary detection
target_offsets = sorted(set(t[2] for t in targets))
offset_to_next = {}
for i, off in enumerate(target_offsets):
    if i + 1 < len(target_offsets):
        offset_to_next[off] = target_offsets[i + 1]
    else:
        offset_to_next[off] = 0x2428C

# Disassemble all events
print(f"Total event records: {len(targets)}")
output_dir = r'C:\Projects\TIC\remaster\event_tool\disassembled'
os.makedirs(output_dir, exist_ok=True)

all_results = []
stats = {'total': 0, 'with_instructions': 0, 'total_instructions': 0}

for group, sub, target in targets:
    next_off = offset_to_next.get(target, target + 40)
    total_bytes = next_off - target
    header_bytes = 28
    data_start = target + header_bytes
    data_length = total_bytes - header_bytes
    
    if data_length < 4:
        continue
    
    result = disassemble_stream(nxd, data_start, data_length, group, sub)
    all_results.append(result)
    stats['total'] += 1
    
    # Count actual instructions
    instr_count = sum(1 for line in result.split('\n') if line.strip() and not line.startswith('#') and '.zero' not in line)
    if instr_count > 0:
        stats['with_instructions'] += 1
        stats['total_instructions'] += instr_count

# Write output
out_path = os.path.join(output_dir, 'enhanced_battle_events.txt')
with open(out_path, 'w', encoding='utf-8') as f:
    f.write("# ==========================================\n")
    f.write("# TIC Enhanced Battle Event Disassembly v0.3\n")
    f.write("# ==========================================\n")
    f.write(f"# Source: enhancedbattleevent.nxd ({len(nxd)} bytes)\n")
    f.write(f"# Total event records: {stats['total']}\n")
    f.write(f"# Records with instructions: {stats['with_instructions']}\n")
    f.write(f"# Total instructions: {stats['total_instructions']}\n\n")
    f.write('\n\n'.join(all_results))

print(f"Records: {stats['total']}")
print(f"With instructions: {stats['with_instructions']}")
print(f"Total instructions: {stats['total_instructions']}")
print(f"Wrote to: {out_path}")

# Print first 10 non-trivial events
print("\n=== Sample output ===\n")
shown = 0
for r in all_results:
    lines = [l for l in r.split('\n') if l.strip() and not l.startswith('#')]
    meaningful = [l for l in lines if '.zero' not in l and '.data' not in l]
    if len(meaningful) >= 2:
        print(r)
        print()
        shown += 1
        if shown >= 10:
            break
