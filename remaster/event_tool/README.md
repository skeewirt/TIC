# TIC Event Script Tools

Disassembler for FINAL FANTASY TACTICS: The Ivalice Chronicles event scripts.

Built on [Gibbed's](https://github.com/gibbed/Gibbed.IvaliceChronicles) opcode research (MIT license), with WotL decompiled source annotations and [FFHacktics](https://ffhacktics.com/wiki/Event_Instructions) community name cross-references.

## Quick Start

### 1. Extract game data

You need [FF16Tools](https://github.com/Nenkai/FF16Tools) to extract files from the game's PAC archives.

**Event scripts** (`.e` files):
```
FF16Tools.CLI.exe unpack-all ^
  -i "<game_dir>\data\enhanced\0005.pac" ^
  -g fft ^
  -o event_scripts ^
  --filter "script/enhanced"
```

**Text data** (`.pzd` files for dialogue):
```
FF16Tools.CLI.exe nxd-convert-all ^
  -i "<game_dir>\data\enhanced\0001.pac" ^
  -g fft ^
  -o nxd_text ^
  --filter "text/"
```

> **Classic scripts** are also in `0005.pac` under `script/classic/`. Classic = PSX/WotL format, Enhanced = TIC (adds bytes to 3 opcodes).

### 2. Build the message map

```
python build_message_map.py path/to/nxd_text -o message_map.json
```

This parses all PZD scenario/battle/unit text files and produces a JSON mapping of ~14,000 message IDs to dialogue strings. The disassembler uses this for inline text annotations.

### 3. Disassemble

**Single file with dialogue:**
```
python tic_event_disasm.py path/to/event002.e --offset --messages message_map.json
```

Output:
```
@0163  DisplayMessage  16, 9, 300000, ...  ; "<center>O Father, abandon not Your wayward children..."
@0200  DisplayMessage  16, 18, 300001, ...  ; "Lady Ovelia, it is time."
@049D  DisplayMessage  16, 145, 300007, ...  ; "Mayhap bowed heads would less offend."
```

**Batch (all scripts + stats):**
```
python tic_event_disasm.py path/to/script/enhanced/ --stats
```

**Batch with .asm output:**
```
python tic_event_disasm.py path/to/script/enhanced/ -o disassembled/ --messages message_map.json
```

### Options

#### tic_event_disasm.py

| Flag | Description |
|------|-------------|
| `-m classic/enhanced` | Script mode (default: `enhanced`) |
| `-o DIR` | Write `.asm` files to DIR |
| `--offset` | Show byte offsets in output |
| `--stats` | Show batch statistics and opcode frequency |
| `--messages FILE` | Load a JSON message map for dialogue resolution |

#### build_message_map.py

| Flag | Description |
|------|-------------|
| `input` | PZD directory tree (searches recursively) |
| `-o FILE` | Output JSON path (default: `message_map.json`) |

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
