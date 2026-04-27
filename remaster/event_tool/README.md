# TIC Event Script Tools

Disassembler for FINAL FANTASY TACTICS: The Ivalice Chronicles event scripts.

Built on [Gibbed's](https://github.com/gibbed/Gibbed.IvaliceChronicles) opcode research (MIT license), with WotL decompiled source annotations and [FFHacktics](https://ffhacktics.com/wiki/Event_Instructions) community name cross-references.

## Quick Start

### 1. Extract event scripts from the game

You need [FF16Tools](https://github.com/Nenkai/FF16Tools) to extract `.e` script files from the game's PAC archives.

```
FF16Tools.CLI.exe unpack-all ^
  -i "<game_dir>\data\enhanced\0005.pac" ^
  -g fft ^
  -o event_scripts ^
  --filter "script/enhanced"
```

This extracts ~560 enhanced event scripts to `event_scripts/script/enhanced/`.

> **Classic scripts** are also in the same PAC under `script/classic/`. Use `--filter "script/classic"` to extract those. Classic = PSX/WotL format, Enhanced = TIC (adds bytes to 3 opcodes).

### 2. Disassemble

**Single file:**
```
python tic_event_disasm.py path/to/event010.e --offset
```

**Batch (all scripts + stats):**
```
python tic_event_disasm.py path/to/script/enhanced/ --stats
```

**Batch with .asm output:**
```
python tic_event_disasm.py path/to/script/enhanced/ -o disassembled/
```

### Options

| Flag | Description |
|------|-------------|
| `-m classic/enhanced` | Script mode (default: `enhanced`) |
| `-o DIR` | Write `.asm` files to DIR |
| `--offset` | Show byte offsets in output |
| `--stats` | Show batch statistics and opcode frequency |

## File Format

Event scripts are flat byte streams: `[1-byte opcode][N bytes of operands]...`

Each opcode has a fixed operand size defined in `opcode_table.json`. Enhanced mode expands 3 opcodes vs classic:

| Opcode | Classic | Enhanced | Delta |
|--------|---------|----------|-------|
| `0x10` DisplayMessage | 14 bytes | 17 bytes | +3 |
| `0x51` ChangeDialog | 5 bytes | 7 bytes | +2 |
| `0xEB` UnknownEB | 6 bytes | 10 bytes | +4 |

## TIC-Exclusive Opcodes

These opcodes exist only in TIC (not in PSX/WotL):

| Opcode | Name | Operands |
|--------|------|----------|
| `0xAD` | ChangePostEffectDepthLUT | U32, S32 |
| `0xAE` | ChangePostEffectLUT | U32, S32 |
| `0xC5` | ChangeDepthOfField | U32, S32 |
| `0xCB` | ChangePostEffectGlare | U32, S32 |
| `0xE7` | DisplayCaption | U32 |

## Credits

- **Gibbed** — Opcode enum, operand types, byte sizes ([Gibbed.IvaliceChronicles](https://github.com/gibbed/Gibbed.IvaliceChronicles))
- **FFHacktics community** — Canonical opcode names and documentation
- **WotL iOS decompilation** — Function-level source annotations for opcode naming
