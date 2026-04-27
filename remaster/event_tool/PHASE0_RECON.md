# Phase 0 — Architecture Summary

> Updated: 2026-04-27  
> Status: Event routing mapped. Core VM is in encrypted .xtext section.

---

## What We Know

### Event Execution Flow

```
Game loop
  → ask_event (0x14022470C) — conditional lookup, selects event type
    → sub_14022473C — central routing (18 event type cases)
      → j___Run_minievent → thunk to sub_14C580CFA (.xtext, ENCRYPTED)
        → THE ACTUAL BYTECODE VM (cannot decompile statically)
      → BeginRunningEvent (0x140222354) — initializes event state
        → copies palette/display data into eventot
        → reads eventflags for story state
```

### The .xtext Problem

The core event VM body lives at `0x14C580CFA` in the `.xtext` segment. This segment is **encrypted at rest** (likely Arxan/Denuvo runtime protection). The bytes are scrambled on disk and only decrypted in-memory when the function is called.

**This means**: We cannot decompile the bytecode interpreter from the static binary. We need either:
1. A **runtime memory dump** with the game running (Cheat Engine, x64dbg attach)
2. The **unpacked/decrypted binary** (community may have one)
3. The **WotL/iOS binary** (no encryption, same event VM logic)

### What eventot/weventot Actually Are

Despite the name, these are NOT opcode dispatch tables. They are:
- `eventot` (0x140D3A430): Event display/state data (zeroed at rest, populated from palette data at 0x14077E490 during BeginRunningEvent)
- `weventot` (0x141843A08): World event state data (also zeroed at rest)

### Functions We CAN Decompile (in .text/.reloc)

| Function | Size | What it does |
|----------|------|-------------|
| `sub_14022473C` (ask_event inner) | 2412 | Routes 18 event types → Run_minievent |
| `event_call` | 69 | Gate check via eventflags |
| `event_call_inner` | 58 | Flag 508 + flag 39 range check |
| `BeginRunningEvent` | 240 | Event state init, palette copy |
| `j___minievent` | 542 | Mini-event lookup, scenario matching |
| `read_eventflag` | 124 | Reads persistent story flags |
| `write_eventflag` | 128 | Writes persistent story flags |
| `event_init_memory` | 165 | VM memory region setup |
| `ask_event` (outer) | 793 | Unit/condition checks before routing |
| `get_stop_event` | 397 | Termination condition check |
| `wld_event` | 1346 | World map event handler |
| `set_event_table` | 1227 | Battle targeting setup (misnamed) |

### Functions We CANNOT Decompile (.xtext encrypted)

| Function | Address | What it likely does |
|----------|---------|-------------------|
| `__Run_minievent` | 0x14CF2C805 | Event VM executor |
| `__minievent` | 0x14CF15D60 | Core bytecode interpreter |
| `ChangeToNextEventState` | 0x14CF38140 | State machine transitions |
| `event_status_set` | 0x14CFDE278 | Execution state flags |
| `event_init_system` | 0x14F112B7D | System initialization |
| `loadEventAnimation` | 0x14D8F1344 | Animation loading |
| `makemessagestructure` | 0x14D0F0640 | Message struct building |
| `serchmessagepointer` | 0x14CDB69E1 | Text pointer lookup |
| `reset_status_forevent2` | 0x14F7496D0 | Status reset |

---

## Next Steps (Priority Order)

### Option A: Runtime Dump (Recommended)
1. Launch game in Steam
2. Attach x64dbg or Cheat Engine
3. Set breakpoint at `sub_14C580CFA` (the VM entry)
4. Trigger any story event in-game
5. Dump the decrypted function from memory
6. Import into IDA for decompilation

### Option B: WotL Reference
1. Download the iOS WotL binary (has debug symbols, no encryption)
2. Find the equivalent `__Run_minievent` function
3. Decompile it — the logic should be identical to TIC's version
4. Map TIC's encrypted addresses to WotL's known functions

### Option C: PSX Reference via heretic/libfft
1. Study adamrt/heretic's event opcode parser
2. The PSX event VM opcodes are documented
3. TIC likely uses the same opcode IDs even if the handler code differs
4. Use PSX opcode knowledge to test hypotheses against runtime behavior
