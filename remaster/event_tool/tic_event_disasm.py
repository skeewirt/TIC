"""
TIC Event Disassembler v0.2
Properly handles the NXD instruction record layout.

NXD Layout discovery:
- Each event starts with a 7-word (28-byte) header containing NXD pointers
- After the header, each instruction is a variable-length record
- Opcodes appear TWICE in each record (duplicate for validation)
- Parameters are between and after the opcode pair

Record layout (approximate):
  Header: [field, PTR, field, field, field, PTR, field]  (28 bytes)
  Then instruction data as a flat u32 stream with the opcode pattern

Strategy: Scan for opcode values in the u32 stream, skip NXD pointers (>0x10000)
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

def disassemble_stream(nxd, start, end, event_id, sub_id):
    """Disassemble a u32 stream, skipping NXD pointers and finding opcodes."""
    lines = []
    lines.append(f"# Event {event_id}, Sub {sub_id}")
    lines.append(f"# Offset: 0x{start:X} - 0x{end:X} ({end - start} bytes)")
    
    # Skip 7-word header
    pos = start + 28
    instr_count = 0
    
    while pos < end - 4:
        val = struct.unpack_from('<I', nxd, pos)[0]
        
        # Skip NXD internal pointers
        if val > 0x10000:
            pos += 4
            continue
        
        # Check for opcode
        if val in OPCODES:
            name, param_count = OPCODES[val]
            
            # Collect parameters: read the next non-pointer u32 values
            params = []
            scan = pos + 4
            while len(params) < param_count + 5 and scan < end:
                pval = struct.unpack_from('<I', nxd, scan)[0]
                if pval > 0x10000:  # skip pointer
                    scan += 4
                    continue
                # Check if this is the duplicate opcode
                if pval == val and len(params) > 0:
                    scan += 4
                    continue
                params.append(pval)
                scan += 4
            
            param_str = ', '.join(str(p) for p in params[:param_count])
            extra = params[param_count:param_count+2]
            lines.append(f"  {instr_count:3d}  {name}({param_str})")
            instr_count += 1
            pos = scan
        else:
            pos += 4
    
    if instr_count == 0:
        return None
    return '\n'.join(lines)

# Parse enhancedbattleevent.nxd
path = r'C:\Projects\TIC\reference\nxd_extract\nxd\enhancedbattleevent.nxd'
with open(path, 'rb') as f:
    nxd = f.read()

# Parse data section records to get event targets
targets = []
data_section = 0x2428C
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

print(f"Total event records: {len(targets)}")

# Group by event group and find boundaries
from collections import defaultdict
events = defaultdict(list)
for group, sub, target in targets:
    events[group].append((sub, target))

# Sort each group by target offset
for g in events:
    events[g].sort(key=lambda x: x[1])

# Disassemble first 15 event groups
output_dir = r'C:\Projects\TIC\remaster\event_tool\disassembled'
os.makedirs(output_dir, exist_ok=True)

all_results = []
for group_id in sorted(events.keys())[:15]:
    subs = events[group_id]
    for i, (sub_id, start) in enumerate(subs):
        if i + 1 < len(subs):
            end = subs[i+1][1]
        else:
            # Find next group's first offset
            next_starts = [s[1] for g, s in [(g, events[g][0]) for g in sorted(events.keys()) if g > group_id]]
            end = next_starts[0] if next_starts else min(start + 500, 0x2428C)
        
        result = disassemble_stream(nxd, start, end, group_id, sub_id)
        if result:
            all_results.append(result)

# Write output
out_path = os.path.join(output_dir, 'enhanced_battle_events.txt')
with open(out_path, 'w', encoding='utf-8') as f:
    f.write("# ====================================\n")
    f.write("# TIC Enhanced Battle Event Disassembly\n")
    f.write("# ====================================\n")
    f.write(f"# Source: enhancedbattleevent.nxd\n")
    f.write(f"# Event groups: {len(events)}\n")
    f.write(f"# Total records: {len(targets)}\n")
    f.write(f"# Disassembler: tic-event-disasm v0.2\n\n")
    f.write('\n\n'.join(all_results))

print(f"Wrote {len(all_results)} events to {out_path}")
print()

# Print first 8 to console
for r in all_results[:8]:
    print(r)
    print()
