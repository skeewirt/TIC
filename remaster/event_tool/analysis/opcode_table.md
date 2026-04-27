# Event Opcode Table

> Maps every event instruction: opcode byte → handler function → parameters → behavior.  
> Source: decompiled `j___minievent` (`0x140224170`) and `sub_14022473C` event routing.

---

## Architecture Discovery

The event system uses a **two-level dispatch**:

### Level 1: Event Type Routing (`sub_14022473C`)

The outer router takes an event type (cases 1–18) and dispatches to `j___Run_minievent`:

| Case | Event Type | Mini-Event IDs Used | Description |
|------|-----------|-------------------|-------------|
| 1 | Battle Start | 7, 41, 6, 20, 21, 28, 49 | Pre-battle, with sub-types for continuation/etc |
| 2 | Battle Setup | 0, 15, 16, 48, 60 | Unit setup, with sub-variants |
| 3 | Post-Battle | 1, 8 | Post-battle event |
| 4 | Battle Outcome | 11, 12, 13, 45, 46, 47 | Win/loss/draw branching |
| 5 | Task Create | — | Creates event task via `j_task_create` |
| 6 | Direct Run | (passthrough) | Direct mini-event execution |
| 7 | World/Sound | 10, 44 | World map BGM + sound module integration |
| 8 | Story Progress | — | Main story progression (flag 39), calls `BeginRunningEvent` |
| 9 | Battle End | 22, 23, 26, 27, 32 | Post-battle variants |
| 10 | World Field | 29 | World field value write |
| 11 | Map Load | 30 | Map loading |
| 12 | (unnamed) | 31 | |
| 13 | (unnamed) | 33 | |
| 14 | Dynamic | 51+ | Dynamic ID from v7 |
| 15 | Item Event | 38, 39 | Item acquisition/poaching |
| 16 | (unnamed) | 40 | |
| 17 | Enhanced | 50 | Enhanced event (TIC additions, world map events) |
| 18 | (unnamed) | 58 | |

### Level 2: Mini-Event Lookup (`j___minievent` / `0x140224170`)

The inner function maps mini-event IDs to actual event script data:

- Uses lookup table at `0x1407D6CA0` (16-byte entries, up to 31 entries)
- Matches against `dword_14077CD0C` (current scenario/context ID)
- Reads event data pointers from the table entries
- Maps unit IDs via table at `qword_140D3A3F0` (per-unit byte lookup)
- Returns a packed value: `event_type | (map_id << 8) | (unit_id << 16)`

### Key Data Structures

| Address | Name | Format | Purpose |
|---------|------|--------|---------|
| `0x1407D6CA0` | Mini-event lookup table | 16-byte entries (WORD id + PTR data) | Maps scenario IDs to event data pointers |
| `0x140D3A3F0` | Unit event mapping | Byte array | Maps unit IDs to event roles |
| `0x141844568` | Map ID table | WORD array (82 entries, `< 0x52`) | Maps event context to map IDs (masked to 9 bits) |
| `0x14077D210` | Event command register | 128-bit packed | Current event command being processed |
| `0x142FCCF38` | Event state register | 128-bit packed | Current event execution state |
| `0x142FCCF30` | Active event type | DWORD | Currently executing event type |

---

## Event Flags (Story Progress)

From `read_eventflag` / `write_eventflag` decompilation:

| Flag ID | Purpose | Known Values |
|---------|---------|-------------|
| 39 | **Main story progress** | 400 = game over, 401–403 = end states, 410–425 = chapter markers |
| 44 | Item/poach accumulator | Incremented on item events |
| 508 | Game state check | Used by event_call gate |
| 509 | Special state flag | Checked for alt-path events |
| 510 | Special state flag 2 | Checked for end-state variants |

---

## Status

- [x] Two-level dispatch architecture mapped
- [x] 18 event type cases documented
- [x] Mini-event lookup table located (`0x1407D6CA0`)
- [x] Event flag system identified (flag 39 = story progress)
- [ ] Individual opcode handlers within mini-events (requires `__minievent` at `0x14CF15D60`)
- [ ] Complete event flag map
- [ ] Enhanced event table (`NEXTable_enhancedbattleevent`) structure
