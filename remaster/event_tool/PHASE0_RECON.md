# Phase 0 — Initial Recon Results

> **Date**: 2026-04-27  
> **Source**: Dicene's named globals + WotL symbol cross-reference

---

## Critical Event Functions (WotL-Verified Names)

| Address | Function Name | WotL Match | Role |
|---------|--------------|------------|------|
| `0x140225744` | **`event_call`** | `event_call` | **THE EVENT DISPATCHER** — calls/executes an event script |
| `0x14022470C` | `ask_event` | `ask_event` | Queries which event to run (conditional lookup) |
| `0x1402F1E6C` | `set_event_table` | `set_event_table` | Configures the event opcode dispatch table |
| `0x1402E578C` | `event_init_memory` | `event_init_memory` | Initializes event VM memory/state |
| `0x14F112B7D` | `event_init_system` | `event_init_system` | Full event system initialization |
| `0x14CFDE278` | `event_status_set` | `event_status_set` | Sets event execution state flags |
| `0x14021F2E0` | `read_eventflag` | `read_eventflag` | Reads persistent event flags (flow control) |
| `0x14021F360` | `write_eventflag` | `write_eventflag` | Writes persistent event flags |
| `0x14025DA78` | `get_stop_event` | `get_stop_event` | Checks for event termination |
| `0x14D8F1344` | `loadEventAnimation` | `loadeventanimation` | Loads animation data for event sequences |
| `0x14F7496D0` | `reset_status_forevent2` | `reset_status_forevent2` | Resets unit status for event re-entry |
| `0x14033EDEC` | `wld_event` | `wld_event` | World map event handler |

## Message / Dialogue Functions

| Address | Function Name | Role |
|---------|--------------|------|
| `0x14020BDE8` | `drawmessagepolygons` | Renders speech bubble geometry |
| `0x1402D3138` | `Wdrawmessagepolygons` | World-map variant of message renderer |
| `0x1402DA28C` | `makemessagepacket` | Constructs dialogue display data |
| `0x14D0F0640` | `makemessagestructure` | Builds message struct from event data |
| `0x14CDB69E1` | `serchmessagepointer` | Finds message text pointer (note: "serch" = original typo from PSX era) |
| `0x14037CDA0` | `InitCamera` | Camera system initialization |

## Critical Global Variables

| Address | Name | Purpose |
|---------|------|---------|
| `0x140D34448` | **`gBEventMode`** | Current event execution mode flag |
| `0x140D36D50` | `eventlinkdata` | Links between events (branching/chaining) |
| `0x140D37460` | **`eventbuffer`** | **The event bytecode buffer** — where scripts are loaded |
| `0x140D39C60` | **`eventwork`** | Event VM working memory (registers/stack) |
| `0x140D3A3BC` | `jumpeventno` | Target event number for jumps/transitions |
| `0x140D3A430` | `eventot` | Event opcode table (battle events) |
| `0x140D3A4A8` | `eventshakef` | Screen shake flag during events |
| `0x140D3A570` | `messagepacket` | Active dialogue packet data |
| `0x140D43130` | `event_inf` | Event info/metadata structure |
| `0x140D6A2B0` | `event_buf_maybe` | Secondary event buffer |
| `0x141843A08` | `weventot` | World event opcode table |
| `0x1418502D8` | `gEventOrBattle` | Mode flag: event vs battle execution |
| `0x141850518` | `pEventUnitLookup` | Unit pointer array for event choreography |
| `0x142FE5F24` | `ProcessingMiniEvent` | Flag for mini-event execution |
| `0x142FF1C3C` | `QueuedCurrentEvent` | Currently queued event ID |
| `0x142FF38EC` | `NextEvent` | Next event to execute |
| `0x1437665D0` | `EventControl` | Master event control structure |
| `0x143CD39F0` | `pEventControl` | Pointer to EventControl |
| `0x14380 11B8` | `EventStatus` | Event execution status |

## NXD Tables for Event System

| Global | Address | Purpose |
|--------|---------|---------|
| `NEXTable_eventid` | `0x143CD3DF8` | Event ID lookup table |
| `NEXTable_scenarioid` | `0x143CD3FE0` | Scenario/chapter conditional table |
| `NEXTable_seadevent` | `0x143CD3F90` | "SEAD" event table (sound/audio events?) |
| `NEXTable_enhancedbattleevent` | `0x143CD42E8` | **TIC-specific battle events** (not in WotL) |
| `NEXTable_enhancedworldevent` | `0x143CD4348` | **TIC-specific world events** (not in WotL) |
| `NEXTable_speaker` | `0x143CD3E98` | Speaker portrait/name data |
| `NEXTable_spellmessage` | `0x143CD3DD0` | Spell incantation text |
| `NEXTable_caption` | `0x143CD3E78` | Caption/subtitle display |
| `NEXTable_scionfiles` | `0x143CD3FD8` | Cutscene script file references |
| `NEXTable_scionlabels` | `0x143CD3FD0` | Cutscene script label/offset table |
| `NEXTable_bgmtransition` | `0x143CD3FC0` | BGM transition rules |
| `NEXTable_map` | `0x143CD39C0` | Map data table |

---

## Architecture Insights

### Two Opcode Tables
- **`eventot`** (`0x140D3A430`) — battle event opcodes
- **`weventot`** (`0x141843A08`) — world event opcodes

This matches the PSX architecture where BATTLE.BIN and WORLD.BIN had separate event handlers. TIC preserves this separation.

### TIC-Specific Tables
`NEXTable_enhancedbattleevent` and `NEXTable_enhancedworldevent` are **not from WotL**. These are TIC additions — likely the new event content (Balthier recruitment, new sidequests, etc.). These tables tell us where TIC-specific event data lives.

### Scion System
`NEXTable_scionfiles` and `NEXTable_scionlabels` reference a "Scion" system. This may be TIC's cutscene scripting format — a higher-level system above the raw event bytecode. "Scion" could be the FF16 engine's native cutscene framework that replaced the PSX event VM.

### Event Buffers
`eventbuffer` (`0x140D37460`) is where event scripts are loaded into memory. This is the buffer we need to intercept to dump live event bytecode.

---

## Priority Decompilation Targets

1. **`event_call` (`0x140225744`)** — The dispatcher. Decompile this first.
2. **`set_event_table` (`0x1402F1E6C`)** — Populates the opcode table. This gives us every opcode.
3. **`ask_event` (`0x14022470C`)** — The conditional lookup. Shows how events are selected.
4. **`event_init_memory` (`0x1402E578C`)** — Shows the VM state structure.
5. **`eventot` (`0x140D3A430`)** — Read the opcode table data directly.
