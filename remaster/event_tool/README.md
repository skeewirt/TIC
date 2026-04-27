# TIC Event Script Tools

Complete CLI toolkit for **disassembling, editing, compiling, and packaging** event scripts from FINAL FANTASY TACTICS: The Ivalice Chronicles.

**560/560 event scripts round-trip byte-identical.** Zero unknown opcodes.

Built on [Gibbed's](https://github.com/gibbed/Gibbed.IvaliceChronicles) opcode research (MIT license), with binary verification via IDA decompilation of `ProcessEventInstructions` and [FFHacktics](https://ffhacktics.com/wiki/Event_Instructions) community name cross-references.

---

## Tools

| Tool | Purpose |
|------|---------|
| `tic_event_disasm.py` | Disassemble `.e` binary → human-readable text or JSON |
| `tic_event_asm.py` | Assemble JSON → byte-identical `.e` binary |
| `tic_event_tools.py diff` | Instruction-level diff between two event scripts |
| `tic_event_tools.py list` | Catalog all events with dialogue counts and previews |
| `tic_event_tools.py pack` | Package compiled events for Reloaded-II modloader |
| `build_message_map.py` | Extract dialogue text from PZD scenario files |
| `opcode_table.json` | Complete opcode definitions (243 opcodes, all named) |

---

## Quick Start

### Prerequisites

- Python 3.10+
- [FF16Tools](https://github.com/Nenkai/FF16Tools) (for extracting game data from PAC archives)

### 1. Extract game data

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

Parses all PZD scenario/battle/unit text files → JSON mapping of ~14,000 message IDs to dialogue strings.

### 3. Disassemble

**Human-readable text:**
```
python tic_event_disasm.py event002.e --offset --messages message_map.json
```
```
@0163  DisplayMessage  16, 9, 300000, ...  ; "<center>O Father, abandon not Your wayward children..."
@0200  DisplayMessage  16, 18, 300001, ...  ; "Lady Ovelia, it is time."
```

**JSON (for editing and round-trip compilation):**
```
python tic_event_disasm.py event002.e --json --messages message_map.json -o event002.json
```
```json
{
  "version": "1.0",
  "mode": "enhanced",
  "instruction_count": 475,
  "instructions": [
    {
      "opcode": 16,
      "name": "DisplayMessage",
      "operands": ["16", "9", "300000", "12", "0", "0", "0", "-45", "0", "10", "0"],
      "comment": "<center>O Father, abandon not Your wayward children of Ivalice..."
    }
  ]
}
```

### 4. Edit

Modify the JSON. Change dialogue IDs, camera angles, unit positions, branching — any instruction.

### 5. Compile

```
python tic_event_asm.py event002.json -o event002.e --verify original/event002.e
```
```
Assembled 475 instructions -> 2955 bytes: event002.e
✅ VERIFIED: byte-identical to original/event002.e
```

### 6. Package for modloader

```
python tic_event_tools.py pack event002.json -o MyEventMod/ --mod-name "fftivc.events.custom"
```
```
✅ Packaged 1 event(s) into: MyEventMod/
   Scripts:    MyEventMod/FFTIVC/data/enhanced/script/
   ModConfig:  MyEventMod/ModConfig.json

   To install: drag the 'MyEventMod' folder into Reloaded-II
```

---

## Utilities

### diff — Compare two event scripts

```
python tic_event_tools.py diff event106.e event108.e
```
```
--- event106.e  (6140 bytes, 20 instructions)
+++ event108.e  (6140 bytes, 20 instructions)

  #  0  - @0000  MoveCamera  1176, -508, 504, 382, 2800, 0, 2656, 1
  #  0  + @0000  MoveCamera  1176, -28, 56, 526, 3584, 0, 4096, 1

  6 instruction(s) changed, 0 bytes
```

### list — Catalog all events

```
python tic_event_tools.py list --messages message_map.json
```
```
Event          Bytes Instrs  Msgs First Dialogue
────────────── ────── ────── ───── ──────────────────────────────────────────────
event002.e       2955    475    19 <center>O Father, abandon not Your wayward childre
event004.e        906    147     5 They bear the crest of the Black Lion... Duke Golt
event005.e        416     71     3 Kill them all! Leave no man standing!
```

**JSON catalog:**
```
python tic_event_tools.py list --format json -o event_catalog.json
```

---

## CLI Reference

### tic_event_disasm.py

| Flag | Description |
|------|-------------|
| `input` | `.e` file or directory of `.e` files |
| `-m classic/enhanced` | Script mode (default: `enhanced`) |
| `-o PATH` | Output file (single) or directory (batch) |
| `--json` | Output JSON format (for round-trip with `tic_event_asm.py`) |
| `--offset` | Show byte offsets in text output |
| `--stats` | Show batch statistics and opcode frequency |
| `--messages FILE` | Load message map for inline dialogue text |

### tic_event_asm.py

| Flag | Description |
|------|-------------|
| `input` | `.json` file or directory of `.json` files |
| `-o PATH` | Output file or directory |
| `-m classic/enhanced` | Script mode (default: `enhanced`) |
| `--verify FILE` | Compare output against original `.e` for byte-identity |

### tic_event_tools.py

| Subcommand | Flags | Description |
|------------|-------|-------------|
| `diff A B` | `--messages`, `--context` | Instruction-level diff |
| `list` | `--scripts DIR`, `--format text/json`, `-o`, `--messages` | Event catalog |
| `pack INPUT` | `-o DIR`, `--mod-name` | Reloaded-II mod packaging |

---

## File Format

Event scripts are flat byte streams: `[1-byte opcode][N bytes of operands]...`

Each opcode has a fixed operand size defined in `opcode_table.json`. Enhanced mode expands 3 opcodes vs. classic:

| Opcode | Classic | Enhanced | Delta |
|--------|---------|----------|-------|
| `0x10` DisplayMessage | 14 bytes | 17 bytes | +3 |
| `0x51` ChangeDialog | 5 bytes | 7 bytes | +2 |
| `0xEB` MessageChain | 6 bytes | 10 bytes | +4 |

## TIC-Exclusive Opcodes

These 8 opcodes exist only in TIC (not in PSX/WotL), verified via IDA decompilation:

| Opcode | Name | Operands | Purpose |
|--------|------|----------|---------|
| `0xA8` | SetSpriteRenderParam | U16, U32 | Writes to animation struct field 343 |
| `0xAB` | DisplayBattleMessage | U32 | Spawns UI task for battle dialog (TIC enhanced mode) |
| `0xAD` | ChangePostEffectDepthLUT | U32, S32 | Depth-based post-processing LUT |
| `0xAE` | ChangePostEffectLUT | U32, S32 | General post-processing LUT |
| `0xC5` | ChangeDepthOfField | U32, S32 | Depth of field parameters |
| `0xCB` | ChangePostEffectGlare | U32, S32 | Glare/bloom post-processing |
| `0xE7` | DisplayCaption | U32 | On-screen caption text display |
| `0xED` | SetCharacterAlpha | U32, U16 | Unit transparency/fade |

## Modloader Integration

The [FFTIVC Mod Loader](https://github.com/Nenkai/fftivc.utility.modloader) (Reloaded-II) handles runtime file replacement:

```
YourMod/
├── FFTIVC/
│   └── data/
│       └── enhanced/
│           └── script/
│               ├── event002.e    ← compiled event scripts
│               └── event093.e
└── ModConfig.json
```

The `pack` command generates this structure automatically. At runtime, the modloader intercepts file loads and serves modded scripts from the mod folder.

For **NXD table changes** (adding new events, editing ENTD unit data), the modloader supports cell-level NXD merging — multiple mods can edit the same table without conflicts.

## Project Documentation

| Document | Description |
|----------|-------------|
| [ROADMAP.md](ROADMAP.md) | Full project roadmap (Phase 0–3) |
| [RESOURCE_INDEX.md](RESOURCE_INDEX.md) | Quick-reference for all addresses, tables, and functions |
| [STARTING_POINTS.md](STARTING_POINTS.md) | Community intel and prior art |
| [WOTL_SYMBOLS.md](WOTL_SYMBOLS.md) | WotL iOS debug symbol reference |
| [analysis/](analysis/) | Deep-dive analysis documents (opcode table, VM state, conditionals, messages) |

## Credits

- **Gibbed** — Opcode enum, operand types, byte sizes ([Gibbed.IvaliceChronicles](https://github.com/gibbed/Gibbed.IvaliceChronicles))
- **FFHacktics community** — Canonical opcode names and documentation
- **Nenkai** — Modloader, FF16Tools, FaithFramework, NXD format documentation
- **Dicene** — WotL IDB cross-reference, iOS debug symbols
- **WotL iOS decompilation** — Function-level source annotations for opcode naming
