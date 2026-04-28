# PZD File Format Reference

> **PZD** = **P**an**Z**er **D**ialogue — the binary format used by TIC (The Ivalice Chronicles) to store 
> event dialogue text, voice acting references, and message metadata.  
> Part of the Panzer engine serialization framework (`DevEnv.Panzer.Models.Binary.Pzd`).  
> Last updated: 2026-04-27

---

## Overview

| Property | Value |
|----------|-------|
| **Magic** | `PZDF` (0x46445A50 LE) |
| **Version** | 2 |
| **Extension** | `.en.pzd` (language-tagged) |
| **Location** | `0002.en.pac` → `nxd/text/scenario/scenario####.en.pzd` |
| **Total files** | 346 scenario files |
| **Total dialogue lines** | ~4,026 |
| **Lines with voice acting** | ~3,987 (99%) |
| **Encoding** | ASCII/UTF-8 (null-terminated strings) |
| **Endianness** | Little-endian |

## File Layout

```
┌──────────────────────────────────────┐
│ Header (8 bytes)                     │
│   0x00: Magic "PZDF"                │
│   0x04: Version (u32 = 2)           │
├──────────────────────────────────────┤
│ Reserved (24 bytes, all zeros)       │
│   0x08 - 0x1F                        │
├──────────────────────────────────────┤
│ Content Descriptor (8 bytes)         │
│   0x20: content_data_offset (u32)    │  → points to first message record
│   0x24: message_count (u32)          │  → number of dialogue entries
│   0x28 - 0x2F: reserved (zeros)      │
├──────────────────────────────────────┤
│ Message Records (variable)           │
│   message_count × 24 bytes each      │  → see Message Record Format
├──────────────────────────────────────┤
│ Sub-record / Continuation Data       │
│   (variable, message metadata)       │
├──────────────────────────────────────┤
│ String Pool                          │
│   Null-terminated text strings       │  → dialogue text + voice paths
│   Interleaved: text → voice → text   │
├──────────────────────────────────────┤
│ BVLD Validation Block                │
│   .NET type metadata strings         │  → PzdFile, PzdFileHeader, 
│   "BVLD" magic + validation data     │     PzdTextContent, NxdUnionKey32
└──────────────────────────────────────┘
```

## Message Record Format (24 bytes)

Each message record is 6 × u32 (24 bytes):

| Offset | Type | Field | Description |
|--------|------|-------|-------------|
| +0x00 | u32 | `message_key` | NXD Union Key — links this message to the NXD scenario/event system |
| +0x04 | u32 | `text_offset` | Offset to dialogue text (relative to record start position) |
| +0x08 | u32 | `entry_size` | Size of this entry's data block (typically 0x18 = 24) |
| +0x0C | u32 | `voice_key` | Secondary key/hash for voice file lookup |
| +0x10 | u32 | `voice_offset` | Offset to voice path string (relative to record start position) |
| +0x14 | u32 | `padding` | Always 0 |

> [!IMPORTANT]
> **Offsets are RELATIVE** to the record's own file position, not to the file start or any section base.
> Example: if a record is at file offset `0x30` and `text_offset = 0x60`, the text string is at file offset `0x30 + 0x60 = 0x90`.

## String Pool

The string pool contains interleaved dialogue text and voice file paths, each null-terminated:

```
[dialogue_text_1\0][voice_path_1\0][dialogue_text_2\0][voice_path_2\0]...
```

- **Dialogue text**: Plain ASCII/UTF-8. May contain:
  - `<center>` — centered text display
  - `<stoplip>` — stop lip-sync animation
  - Stage directions in parentheses: `(attacking with sword exert)`
  - Multi-part messages with `_s01`, `_s02` voice variants
  
- **Voice paths**: Always in the format:  
  `sound/voice/scenario/scenario####/vo_scenario####_NNN_SSS.sab`
  - `####` = scenario ID (e.g., 0010, 0620, 1700)
  - `NNN` = message number (001, 002, etc.)
  - `SSS` = sub-part (000 = main, s01/s02 = continuation)

## BVLD Validation Block

The file ends with a BVLD (Binary VaLiDation) block containing .NET type strings:

| Type String | Purpose |
|-------------|---------|
| `DevEnv.Nex.NexSerialization.Nxd.NxdUnionKey32` | Key type for NXD cross-references |
| `DevEnv.Panzer.Models.Binary.Pzd.PzdFile` | Root file type |
| `DevEnv.Panzer.Models.Binary.Pzd.PzdFileHeader` | Header type |
| `DevEnv.Panzer.Models.Binary.Pzd.PzdTextContent` | Text content entry type |

The BVLD block ends with: `BVLD` magic (4 bytes) + version u32 + validation hash.

## Connection to Event Scripts

Event scripts reference PZD messages via the `DisplayMessage` opcode:

```
DisplayMessage(0x10, daytime, message_id, speaker_id, 0x00, portrait, x, y, arrow_pos, open_type)
```

The `message_id` parameter maps to the message_key in the PZD record, which the engine resolves via the NXD `scenarioid` table to find the correct PZD file and message entry.

## File Size Distribution

| Range | Count | Description |
|-------|-------|-------------|
| < 300 bytes | 2 | Empty/minimal (no text, header only) |
| 300–500 bytes | 3 | Single message |
| 500–2,000 bytes | 47 | Short scenes (1–5 lines) |
| 2,000–5,000 bytes | 138 | Medium scenes (5–20 lines) |
| 5,000–10,000 bytes | 143 | Long scenes (20–50 lines) |
| > 10,000 bytes | 13 | Major cutscenes (50+ lines) |

## Known Limitations

1. **Multi-part messages**: Some dialogue lines span multiple voice files (`_s01`, `_s02`). The exact mechanism for linking sub-parts to the same text block needs further investigation.

2. **Binary noise region**: Between the message records and the string pool, there's a region of structured binary data (message metadata/indices) whose exact format is not yet fully decoded. The current parser skips this and scans for text strings directly.

3. **Message ordering**: Messages appear in the string pool in the order they're spoken in the event, but the message records may use a different ordering based on NXD keys.

4. **Write path**: Not yet implemented. Modifying text requires:
   - Updating string lengths in the message records
   - Rebuilding the string pool with new text
   - Adjusting all relative offsets
   - Regenerating the BVLD validation block

## Example: scenario0476.en.pzd (Minimal)

A 1-message file (416 bytes): a chocobo saying "Kw...kweh...?"

```
0000: 50 5A 44 46 02 00 00 00  — PZDF, version 2
0008: [24 bytes of zeros]       — reserved
0020: 30 00 00 00              — content starts at 0x30
0024: 01 00 00 00              — 1 message
0028: [8 bytes of zeros]        — reserved
0030: EE 95 04 00              — message_key = 0x495EE
0034: 60 00 00 00              — text at 0x30+0x60 = 0x90
0038: 18 00 00 00              — entry_size = 24
003C: 88 C7 2D 00              — voice_key = 0x2DC788
0040: 6E 00 00 00              — voice at 0x30+0x6E = 0x9E
0044: 00 00 00 00              — padding
...
0090: "Kw...kweh...?\0"
009E: "sound/voice/scenario/scenario0476/vo_scenario0476_013_000.sab\0"
...
BVLD validation block
```

## Example: scenario0010.en.pzd (Prologue)

28 messages (3,994 bytes): Orbonne Monastery opening scene.

Notable lines:
- `<center>O Father, abandon not Your wayward children of Ivalice...` (Ovelia's prayer)
- `Lady Ovelia, it is time.` (Agrias)
- `Still in here, are you? It's been the better part of an hour!` (Gaffgarion)
- `What is it, Ramza? You above getting paid to do a job?` (Gaffgarion)
- `I'm a knight no longer. Just another sellsword.` (Ramza)
- `To battle!` (Gaffgarion)
