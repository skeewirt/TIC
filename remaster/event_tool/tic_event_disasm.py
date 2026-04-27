"""
TIC Event Script Disassembler v1.0
Based on Gibbed.IvaliceChronicles.ScriptFormats (MIT license)

Supports Classic and Enhanced modes with typed operand decoding.
"""
import struct, json, sys, os, argparse
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

# ── Operand type definitions (from Gibbed's OperandType.cs) ──
# Each type: (name, byte_size, struct_format, display_func)
OPERAND_TYPES = {
    'B8':  ('bool',  1, 'B', lambda v: 'true' if v else 'false'),
    'OnOff': ('onoff', 1, 'B', lambda v: 'on' if v else 'off'),
    'OffOn': ('offon', 1, 'B', lambda v: 'off' if v else 'on'),
    'S8':  ('s8',  1, 'b', lambda v: str(v)),
    'U8':  ('u8',  1, 'B', lambda v: str(v)),
    'S16': ('s16', 2, '<h', lambda v: str(v)),
    'U16': ('u16', 2, '<H', lambda v: str(v)),
    'MsgIdx': ('msg', 2, '<H', lambda v: f'msg[{v}]'),
    'S32': ('s32', 4, '<i', lambda v: str(v)),
    'U32': ('u32', 4, '<I', lambda v: str(v)),
}

def read_operand(data, offset, type_key):
    """Read a single typed operand from data at offset. Returns (value_str, bytes_consumed)."""
    t = OPERAND_TYPES[type_key]
    size = t[1]
    if offset + size > len(data):
        return ('??', 0)
    fmt = t[2]
    val = struct.unpack_from(fmt, data, offset)[0]
    return (t[3](val), size)

# ── Operand signatures (from Gibbed's Operands.cs) ──
# Maps opcode byte -> list of operand type keys
# 'None' = no operands, 'Invalid' = not a valid opcode, 'Strange' = should exist but missing handler
OPERAND_SIGS_CLASSIC = {
    0x10: ['U8','U8','MsgIdx','U8','U8','U8','S16','S16','S16','U8'],  # DisplayMessage
    0x11: ['U16','U16','U8'],        # AnimationRequest
    0x12: ['U16'],                   # WaitAnimationEnd
    0x13: ['U8','U8'],               # JumpMap
    0x16: [],                        # WaitTask
    0x18: ['U16','U8','U8','U8','U8'], # ChangeEffect
    0x19: ['S16','S16','S16','S16','S16','S16','S16','S16'], # MoveCamera
    0x1A: ['U8','U8','U8','U8','U8'], # MoveAmbient
    0x1B: ['S16','S16','S16','S16','S16','S16','S16'], # MoveLight
    0x1C: ['U8'],                    # ChangeFrameRate
    0x1D: [],                        # CameraFusionStart
    0x1E: [],                        # CameraFusionEnd
    0x1F: ['U8','U8','U8','U8','U8'], # Focus
    0x21: ['U16'],                   # PlaySound
    0x22: ['U8','S8','U8'],          # PlayMusic
    0x27: [],                        # RewriteMap
    0x28: ['U8','U8','U8','U8','U8','U8','U8','U8'], # MoveToPanel
    0x29: ['U8','U8'],               # WaitCharacterMove
    0x2A: [],                        # BlockStart
    0x2B: [],                        # BlockEnd
    0x2C: ['U8','U8','U8','U8','U8','U8','U8'], # Direction2_0
    0x2D: ['U8','U8','U8','U8','U8','U8'], # Direction
    0x2E: ['U8','U8','U8','U8','U8','U8','U8','U8'], # FadeGradation
    0x31: ['U8','U8','U8','U8','U8'], # ChangeGradation
    0x32: ['U8','U8','U8','U8','U8','U8','U8'], # SetCharacterColor
    0x33: ['U8','U8','U8','U8','U8'], # ChangeMapClut
    0x37: ['U16'],                   # Unknown37
    0x38: ['U16'],                   # FocusSpeed
    0x39: [],                        # WaitCharacterMoveWotL
    0x3A: [],                        # WaitFileRead
    0x3B: ['U8','U8','S16','S16','S16','U8','U8','S16'], # MoveSprite
    0x3C: ['U8','U8'],               # ChangeWeather
    0x3D: ['U8','U8'],               # DisappearUnit
    0x3E: ['U8','U8','U8','U8','U8','U8','U8','S16'], # SetChangePaletteData
    0x3F: ['U8','U8','U8','U8'],     # ChangeMapD
    0x40: ['U8','U8','U8','U8','U8'], # ChangeMapSTP
    0x41: ['U8','U8','U8','U8'],     # StartShake
    0x42: [],                        # StopShake
    0x43: ['U8'],                    # CallFunction
    0x44: ['U8','U8'],               # Draw
    0x45: ['U8','U8','U8'],          # LoadAnimation
    0x46: ['U8','U8'],               # DeactivateAnimation
    0x47: ['U8','U8','U8','U8','U8','U8','U8','U8'], # ActivateAnimation
    0x48: [],                        # WaitLoadAnimation
    0x49: [],                        # ActivateAnimationStart
    0x4A: [],                        # ActivateAnimationEnd
    0x4B: [],                        # WaitActivateAnimation
    0x4C: ['U8','U8'],               # JumpMap2
    0x4D: ['U8'],                    # Reveal
    0x4E: ['U8','U8','U8'],          # SetAnimationShadow
    0x4F: ['U8'],                    # SetDaytime
    0x50: ['U8'],                    # SetFace
    0x51: ['U8','S16','U16'],        # ChangeDialog (classic)
    0x53: ['U8','U8','U8','U8','U8','U8','U8'], # Direction2_1
    0x54: ['U8','U8'],               # StartModelAnimation
    0x55: ['U8','U8'],               # StartVRAMAnimation
    0x56: [],                        # WaitModelAnimation
    0x57: [],                        # WaitVRAMAnimation
    0x58: ['U8','U8','U8'],          # LoadEventCharacter
    0x59: ['U8'],                    # ActivateEventCharacter
    0x5A: ['U8'],                    # DeactivateEventCharacter
    0x5B: ['U8'],                    # DisposeEventCharacter
    0x5C: ['U16','U8'],              # ActivateCompressedAnimation
    0x5D: ['U8'],                    # DeactivateCompressedAnimation
    0x5E: ['U8'],                    # DisposeMusic
    0x5F: ['U8','U8','U8','U8','U8','U8'], # SetAnimationPosition
    0x60: ['U8','U8'],               # FadeMusic
    0x63: ['U8'],                    # SetMoveCameraFlags
    0x64: ['U8','U8'],               # WaitDirection
    0x65: [],                        # WaitDirectionAll
    0x66: [],                        # SetPresentClutDataAsDefault
    0x68: ['U16','U8'],              # SetAnimationHorizontalFlip
    0x69: ['U8','U8','U8','U8','U8','U8','U8','U8'], # Direction4
    0x6A: ['U8','S8','S8','U8','U8'], # FadeSoundEffect
    0x6B: ['U8','S8','S8','U8','U8'], # PlaySoundEffect
    0x6C: ['U16'],                   # SetAnimationColorChangeOff
    0x6D: ['U16'],                   # SetAnimationColorChangeOn
    0x6E: ['U8','U8','S16','S16','S16','U8','U8','S16'], # MoveSprite2
    0x6F: ['U8','U8'],               # WaitMoveSprite
    0x70: ['U8','U8','U8','U8'],     # JumpToPanel
    0x71: ['U16'],                   # RaiseAnimationPriority
    0x72: [],                        # ForceStop
    0x73: ['U16','U16','U16','U16','U16','U16','U16'], # Unknown73
    0x76: ['U8','U8','U8','U8','U8','U8'], # StartWipe
    0x77: [],                        # StopWipe
    0x78: ['U8','U8'],               # DisplayConditions
    0x79: ['U16','U16'],             # WalkToAnim
    0x7A: ['U8','U8'],               # EraseUnit
    0x7B: ['U16'],                   # Unknown7B
    0x7C: [],                        # StopAllEffects
    0x7D: ['U8'],                    # DisplayChapter
    0x7E: ['U16','U16'],             # WaitEventFlag
    0x7F: ['U8','U8','U8','U8'],     # SetEventCharacterClut
    0x80: ['U8','U8','U8'],          # RequestStandardAnimation
    0x81: ['U16','OffOn'],           # SetAnimationSound
    0x82: [],                        # Unknown82
    0x83: ['U8','U8','U8','S16'],    # ChangeStats
    0x84: ['U8'],                    # PlayJingle
    0x85: ['U8'],                    # ChangeTreasureFindDay
    0x86: ['U8','U8','U8'],          # EquipWeapon
    0x87: ['U16','U16'],             # UseGun
    0x88: [],                        # RestartMapPaletteAnimation
    0x89: [],                        # StopMapPaletteAnimation
    0x8A: [],                        # WaitEffectLoad
    0x8B: [],                        # PlayEffect
    0x8C: ['U16','U8','U16','OffOn'], # SetAnimationFlipDirection
    0x8E: [],                        # WaitDisplayChapter
    0x8F: ['U8'],                    # Unknown8F
    0x90: ['U8','U8','U8'],          # WaitActivePanel
    0x91: ['U8','U8','U8'],          # DisplayMapTitle
    0x92: ['U16','U8','U16'],        # InflictStatus
    0x93: ['U16'],                   # Unknown93
    0x94: ['U16'],                   # TeleportOut
    0x96: [],                        # AppendMapState
    0x97: ['U16'],                   # SetAnimationBrightColor
    0x98: ['U16'],                   # TeleportIn
    0x99: ['U16'],                   # BlueRemoveUnit
    0xA0: [],                        # LessThanEquals
    0xA1: [],                        # GreaterThanEquals
    0xA2: [],                        # Equals
    0xA3: [],                        # NotEquals
    0xA4: [],                        # LessThan
    0xA5: [],                        # GreaterThan
    0xA6: ['U32'],                   # UnknownA6
    0xA7: ['U32'],                   # UnknownA7
    0xA8: ['U16','U32'],             # UnknownA8
    0xA9: ['U16','U32'],             # UnknownA9
    0xAA: ['B8'],                    # UnknownAA
    0xAB: ['U32'],                   # UnknownAB
    0xAC: ['U32'],                   # UnknownAC
    0xAD: ['U32','S32'],             # ChangePostEffectDepthLUT (TIC only)
    0xAE: ['U32','S32'],             # ChangePostEffectLUT (TIC only)
    0xAF: ['U32'],                   # UnknownAF
    0xB0: ['U16','U16'],             # Add
    0xB1: ['U16','U16'],             # AddVar
    0xB2: ['U16','U16'],             # Sub
    0xB3: ['U16','U16'],             # SubVar
    0xB4: ['U16','U16'],             # Mul
    0xB5: ['U16','U16'],             # MulVar
    0xB6: ['U16','U16'],             # Div
    0xB7: ['U16','U16'],             # DivVar
    0xB8: ['U16','U16'],             # Mod
    0xB9: ['U16','U16'],             # ModVar
    0xBA: ['U16','U16'],             # And
    0xBB: ['U16','U16'],             # AndVar
    0xBC: ['U16','U16'],             # Or
    0xBD: ['U16','U16'],             # OrVar
    0xBE: ['U16'],                   # Zero
    0xC5: ['U32','S32'],             # ChangeDepthOfField (TIC only)
    0xCB: ['U32','S32'],             # ChangePostEffectGlare (TIC only)
    0xD0: ['U8'],                    # SeekCodeForwardIfZero
    0xD1: ['U8'],                    # SeekCodeForward
    0xD2: ['U8'],                    # SeekCodeForwardTarget
    0xD3: ['U8'],                    # SeekCodeBackward
    0xD4: ['U8'],                    # Terminate
    0xD5: ['U8'],                    # SeekCodeBackwardTarget
    0xD8: ['U8'],                    # UnknownD8
    0xD9: ['U8'],                    # UnknownD9
    0xDB: [],                        # EventEnd
    0xDC: [],                        # UnknownDC
    0xE3: [],                        # EventEnd2
    0xE5: ['U16'],                   # WaitForInstruction
    0xE7: ['U32'],                   # DisplayCaption (TIC only)
    0xE8: ['U8'],                    # UnknownE8
    0xE9: ['U32','U32'],             # UnknownE9
    0xEA: ['U32','B8'],              # UnknownEA
    0xEB: ['U16','U16','U16'],       # UnknownEB (classic)
    0xEC: [],                        # UnknownEC
    0xED: ['U32','U16'],             # UnknownED (TIC only)
    0xEE: ['U32'],                   # UnknownEE
    0xEF: [],                        # UnknownEF
    0xF0: [],                        # UnknownF0
    0xF1: ['U16'],                   # Wait
    0xF2: [],                        # Pad
}

# Enhanced mode overrides (TIC-specific expansions)
OPERAND_SIGS_ENHANCED = dict(OPERAND_SIGS_CLASSIC)
OPERAND_SIGS_ENHANCED[0x10] = ['U8','U8','U32','U8','U8','U8','S16','S16','S16','U8','U8']  # DisplayMessage +3
OPERAND_SIGS_ENHANCED[0x51] = ['U8','S32','U16']  # ChangeDialog +2
OPERAND_SIGS_ENHANCED[0xEB] = ['S32','S32','U16']  # UnknownEB +4


# ── Load opcode names ──
def load_opcode_names(table_path):
    with open(table_path) as f:
        table = json.load(f)
    names = {}
    sizes_classic = {}
    sizes_enhanced = {}
    for key, val in table.items():
        op = int(key, 16)
        names[op] = val['name']
        sizes_classic[op] = val.get('operand_bytes_classic', 0)
        sizes_enhanced[op] = val.get('operand_bytes_enhanced', 0)
    return names, sizes_classic, sizes_enhanced


# ── Disassembler ──
def disassemble(data, mode='enhanced', names=None, sizes=None, sigs=None, messages=None):
    """Disassemble a byte stream into instructions."""
    instructions = []
    off = 0
    
    while off < len(data):
        opbyte = data[off]
        name = names.get(opbyte, f'UNKNOWN_0x{opbyte:02X}')
        size = sizes.get(opbyte, 0)
        
        # Past EventEnd, remaining bytes are garbage/padding
        if opbyte not in sizes:
            instructions.append({
                'offset': off, 'opcode': opbyte, 'name': name,
                'operands': [], 'raw': bytes([opbyte]), 'error': 'unknown opcode'
            })
            off += 1
            continue
        
        if off + 1 + size > len(data):
            instructions.append({
                'offset': off, 'opcode': opbyte, 'name': name,
                'operands': [], 'raw': data[off:], 'error': 'truncated'
            })
            break
        
        raw = data[off:off+1+size]
        operand_data = data[off+1:off+1+size]
        
        # Decode typed operands if signature is available
        operands = []
        sig = sigs.get(opbyte)
        if sig is not None and len(sig) > 0:
            op_off = 0
            for type_key in sig:
                if op_off >= len(operand_data):
                    break
                val_str, consumed = read_operand(operand_data, op_off, type_key)
                # Special: message index resolution
                if type_key == 'MsgIdx' and messages:
                    idx = struct.unpack_from('<H', operand_data, op_off)[0]
                    if idx < len(messages):
                        val_str = f'msg[{idx}]="{messages[idx][:60]}"'
                operands.append(val_str)
                op_off += consumed
        elif size > 0:
            # Fallback: raw hex
            operands = [' '.join(f'{b:02X}' for b in operand_data)]
        
        instructions.append({
            'offset': off, 'opcode': opbyte, 'name': name,
            'operands': operands, 'raw': raw, 'error': None
        })
        off += 1 + size
    
    return instructions


def format_instruction(instr, show_offset=True):
    """Format an instruction for display."""
    parts = []
    if show_offset:
        parts.append(f'@{instr["offset"]:04X}')
    
    name = instr['name']
    if instr['error']:
        parts.append(f'{name} ; ERROR: {instr["error"]}')
    elif instr['operands']:
        parts.append(f'{name:<35s}  {", ".join(instr["operands"])}')
    else:
        parts.append(name)
    
    return '  '.join(parts)


def disassemble_file(filepath, mode='enhanced', names=None, sizes=None, sigs=None, messages=None):
    """Disassemble a single .e file."""
    with open(filepath, 'rb') as f:
        data = f.read()
    
    instrs = disassemble(data, mode, names, sizes, sigs, messages)
    
    # Find EventEnd to separate code from padding
    code_end = len(instrs)
    for i, instr in enumerate(instrs):
        if instr['name'] in ('_EventEnd', '_EventEnd2'):
            code_end = i + 1
            break
    
    return instrs, code_end, data


def main():
    parser = argparse.ArgumentParser(description='TIC Event Script Disassembler')
    parser.add_argument('input', nargs='?', help='Input .e file or directory')
    parser.add_argument('-m', '--mode', choices=['classic', 'enhanced'], default='enhanced')
    parser.add_argument('-o', '--output', help='Output directory for batch mode')
    parser.add_argument('--offset', action='store_true', help='Show byte offsets')
    parser.add_argument('--stats', action='store_true', help='Show statistics only')
    parser.add_argument('--table', default=os.path.join(os.path.dirname(__file__), 'opcode_table.json'))
    args = parser.parse_args()
    
    # Defaults
    if not args.input:
        args.input = os.path.join(os.path.dirname(__file__), 
            '..', '..', 'reference', 'event_scripts', 'script', 'enhanced')
        args.stats = True
    
    names, sizes_classic, sizes_enhanced = load_opcode_names(args.table)
    sizes = sizes_enhanced if args.mode == 'enhanced' else sizes_classic
    sigs = OPERAND_SIGS_ENHANCED if args.mode == 'enhanced' else OPERAND_SIGS_CLASSIC
    
    if os.path.isfile(args.input):
        # Single file mode
        instrs, code_end, data = disassemble_file(args.input, args.mode, names, sizes, sigs)
        fname = os.path.basename(args.input)
        print(f"; {fname} ({len(data)} bytes, {code_end} instructions)")
        print(f"; Mode: {args.mode}")
        print()
        for instr in instrs[:code_end]:
            print(format_instruction(instr, args.offset))
        # Show post-EventEnd data count
        post = len(instrs) - code_end
        if post > 0:
            print(f"\n; ({post} bytes of post-EventEnd padding/data)")
    
    elif os.path.isdir(args.input):
        # Batch mode
        files = sorted([f for f in os.listdir(args.input) if f.endswith('.e')])
        total_instrs = 0
        total_errors = 0
        total_files = 0
        opcode_freq = {}
        
        for fname in files:
            fpath = os.path.join(args.input, fname)
            instrs, code_end, data = disassemble_file(fpath, args.mode, names, sizes, sigs)
            errors = sum(1 for i in instrs[:code_end] if i['error'])
            total_instrs += code_end
            total_errors += errors
            total_files += 1
            
            for instr in instrs[:code_end]:
                opcode_freq[instr['opcode']] = opcode_freq.get(instr['opcode'], 0) + 1
            
            if args.output:
                out_path = os.path.join(args.output, fname.replace('.e', '.asm'))
                os.makedirs(args.output, exist_ok=True)
                with open(out_path, 'w', encoding='utf-8') as f:
                    f.write(f"; {fname} ({len(data)} bytes, {code_end} instructions)\n")
                    f.write(f"; Mode: {args.mode}\n\n")
                    for instr in instrs[:code_end]:
                        f.write(format_instruction(instr, True) + '\n')
            
            if not args.stats:
                print(f"{fname}: {code_end} instructions, {errors} errors")
        
        print(f"\n{'='*60}")
        print(f"  Batch Summary ({args.mode} mode)")
        print(f"{'='*60}")
        print(f"  Files:        {total_files}")
        print(f"  Instructions: {total_instrs}")
        print(f"  Errors:       {total_errors}")
        print(f"\n  Top 20 opcodes:")
        for op, count in sorted(opcode_freq.items(), key=lambda x: -x[1])[:20]:
            print(f"    0x{op:02X}  {names.get(op, '???'):<35s}  {count:>6d}")


if __name__ == '__main__':
    main()
