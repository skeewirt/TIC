# Phase 0 — Event System Recon (Complete)

> Completed: 2026-04-27  
> Status: ✅ Architecture fully mapped. Ready for Phase 1.

---

## Approach

TIC's event system code is split across two PE sections:
- **`.reloc`** (addresses `0x1401xxxxx`–`0x1403xxxxx`): Clean, decompilable. Contains the event routing layer.
- **`.xtext`** (addresses `0x14Cxxxxxx`+): **Arxan-obfuscated**. Contains the core VM, opcode handlers, and message system internals.

The `.xtext` code is NOT encrypted — it's readable machine code — but it's protected by Arxan anti-tamper (opaque predicates, control flow flattening, interlocked exchanges). Hex-Rays produces garbage for these functions.

**Solution**: We downloaded the **WotL iOS binary** from debugging.games. Same codebase, full debug symbols, zero protection. All 366 event-related functions decompiled cleanly.

---

## Deliverables

### Decompiled Code (local, gitignored)

| Directory | Files | Lines | Source |
|-----------|-------|-------|--------|
| `decompiled/` | ~30 | ~1,900 | TIC binary (clean `.reloc` functions) |
| `decompiled/wotl/` | **366** | **22,286** | WotL iOS binary (complete event system) |

### Key Files in `decompiled/wotl/`

| File | Lines | What It Is |
|------|-------|-----------|
| `__ZL16event_maincommonv.c` | **2,508** | The complete bytecode VM / opcode interpreter |
| `__Z10event_callPmm.c` | 605 | Main event loop (input, maps, weather, music, animations) |
| `__ZL13ask_eventmainiiiP7SVECTORiP3ACT.c` | 504 | Event routing hub — 17 event type cases |
| `__ZL9minieventv.c` | 50 | Mini-event launcher (reads phaserec table) |
| `__ZL16check_eventstartv.c` | ~150 | Event start condition checks |
| `__Z15request_commandi.c` | ~80 | Opcode command request handler |
| `__Z16event_status_settt.c` | ~50 | Event status flag management |
| `__Z14read_eventflagi.c` | ~20 | Story progress flag reader |
| `__Z15write_eventflagii.c` | ~15 | Story progress flag writer |

### Documents (on GitHub)

| File | Purpose |
|------|---------|
| `RESOURCE_INDEX.md` | All TIC addresses, globals, NXD tables |
| `WOTL_SYMBOLS.md` | 53 demangled WotL symbol reference |
| `PHASE0_RECON.md` | This file — architecture summary |
| `ROADMAP.md` | 4-phase strategic plan |
| `analysis/opcode_table.md` | Two-level dispatch architecture |

---

## Architecture

### Event Execution Pipeline

```
Game Loop
  → event_call()               # Main event tick (605 lines)
    ├─ pad input, map flags, weather, music, animations
    ├─ overlay management (job menu, equip, card save)
    └─ task scheduling via asmTaskEntry()

Battle Start
  → ask_event(type, sub, unit, svector, flag)
    → ask_eventmain()           # Routes 17 event types to phase IDs
      → drive_minievent(phase)  # Creates task with minievent()
        → minievent()           # Reads phaserec[phase], creates handler task
          → event_maincommon()  # THE VM: 2,508 lines, processes bytecodes
```

### Event Types (from ask_eventmain)

| Case | Phase IDs | Named Purpose |
|------|----------|---------------|
| 1 | 7, 41, 6, 20, 21, 28, 49 | PHASE_MENUEND (post-menu actions) |
| 2 | 0, 15, 16, 48 | Unit setup |
| 3 | 1, 8 | Post-battle |
| 4 | 11, 12, 13, 45, 46, 47 | Battle outcome (win/lose/draw) |
| 5 | — | Spell event (task_create with hook_spel) |
| 6 | 8 | Direct mini-event |
| 7 | 10, 44 | World/sound event |
| 8 | — | Story progression (flag 39 gated) |
| 9 | 22, 23, 26, 27, 32 | Battle end variants |
| 10 | 29 | PHASE_STTSMES (status message) |
| 11 | 30 | Map load |
| 12 | 31 | (unnamed) |
| 13 | 33 | (unnamed) |
| 14 | 51+ | Dynamic from sub-type |
| 15 | 38, 39 | Item acquisition/poaching |
| 16 | 40 | (unnamed) |
| 17 | 50 | Enhanced world events |

### Key Data Structures

| Name | Type | Purpose |
|------|------|---------|
| `phaserec` | Array of 10-word records | Maps phase IDs → handler functions + parameters |
| `combase` / `comtest` | Struct | Unit command record base |
| `eventot` | Runtime buffer | Event output/state (NOT an opcode table) |
| `eventbuffer` | Byte array | Live event script bytecode |
| `eventwork` | Struct | VM working memory |
| `eventlinkdata` | Array | Event chaining/branching data |

### Event Flags (Story Progress)

| Flag | Purpose |
|------|---------|
| 39 | Main story progress (0=none, 400=game over, 401-403=end states, 410-425=chapters) |
| 42 | Tutorial pad write |
| 44 | Item accumulator |
| 50 | Sub-progress |
| 51 | Map/GNS state |
| 81 | Card access state |
| 508 | Event active flag |
| 509 | Special state (net error, brave story) |
| 510 | Alt-path variant |

---

## Next Steps (Phase 1)

1. **Parse `event_maincommon`** (2,508 lines) — extract every opcode: the switch/case on instruction bytes, parameter formats, handler logic
2. **Cross-reference with PSX documentation** — FFHacktics has the original opcode IDs; confirm they match WotL/TIC
3. **Locate event script data** — find the bytecode blobs in TIC's file format that load into `eventbuffer`
4. **Build a bytecode parser** — read blobs, disassemble to human-readable instructions
5. **Prototype event editor UI** — display parsed events, allow editing, repack

---

## Reproduction Notes

### IDA Lock Files
Every `idat.exe` run creates `.id0`/`.id1`/`.id2`/`.nam`/`.til` alongside the `.i64`. Delete these before the next run or IDA refuses to open the database.

### WotL Binary
Downloaded from `debugging.games`. FAT Mach-O with two ARM slices. We use slice 1 (ARMv7, sub=9, offset `0x473000`, 4.6MB). Extracted to `reference/wotl_ios/FFT_iPhone_armv7.bin`. IDB at `.bin.i64`.

### Decompile Scripts
All in `reference/scripts/`:
- `decompile_event_system.py` — TIC batch 1 (18 functions)
- `decompile_event_batch2.py` — TIC batch 2 
- `decompile_xtext_functions.py` — TIC .xtext force-create
- `decompile_wotl_events.py` — WotL batch 1 (53 functions)
- `decompile_wotl_batch2.py` — WotL batch 2 (313 functions)
