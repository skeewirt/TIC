# TIC Event System — Resource Index

> Quick-reference for all known addresses, tables, and functions.  
> View this file at the start of any session to avoid re-research.  
> Last updated: 2026-04-27

---

## IDA Database

| Item | Path / Value |
|------|-------------|
| **Binary** | `FFT_enhanced.exe` v1.0.0.0 (Steam) |
| **IDB** | `FFT_enhanced.i64` (IDA Pro 9.3) |
| **Symbol source** | Dicene's WotL cross-reference (`reference/Dicenes_Names/`) |
| **iOS symbols** | `https://debugging.games/_files/iOS/[iOS] FINAL FANTASY TACTICS - THE WAR OF THE LIONS [v1.0.0].7z` |

---

## Event Functions (Decompilation Targets)

| Address | Name | Status | Purpose |
|---------|------|--------|---------|
| `0x140225744` | `event_call` | 🔴 TODO | **Primary dispatcher** — executes event bytecode |
| `0x1402F1E6C` | `set_event_table` | 🔴 TODO | Populates opcode dispatch table → gives us every instruction |
| `0x14022470C` | `ask_event` | 🔴 TODO | Conditional lookup — selects which event to run |
| `0x1402E578C` | `event_init_memory` | 🔴 TODO | Initializes VM state (registers, stack, buffers) |
| `0x14F112B7D` | `event_init_system` | 🔴 TODO | Full event system boot |
| `0x14CFDE278` | `event_status_set` | 🔴 TODO | Sets event execution state flags |
| `0x14021F2E0` | `read_eventflag` | 🔴 TODO | Reads persistent event flags (story progress) |
| `0x14021F360` | `write_eventflag` | 🔴 TODO | Writes persistent event flags |
| `0x14025DA78` | `get_stop_event` | 🔴 TODO | Checks for event termination condition |
| `0x14D8F1344` | `loadEventAnimation` | 🔴 TODO | Loads animation data for event choreography |
| `0x14F7496D0` | `reset_status_forevent2` | 🔴 TODO | Resets unit status for event re-entry |
| `0x14033EDEC` | `wld_event` | 🔴 TODO | World-map event handler |

## Message / Dialogue Functions

| Address | Name | Status | Purpose |
|---------|------|--------|---------|
| `0x14020BDE8` | `drawmessagepolygons` | 🔴 TODO | Renders speech bubble geometry |
| `0x1402D3138` | `Wdrawmessagepolygons` | 🔴 TODO | World-map message renderer |
| `0x1402DA28C` | `makemessagepacket` | 🔴 TODO | Constructs dialogue display data packet |
| `0x14D0F0640` | `makemessagestructure` | 🔴 TODO | Builds message struct from event bytecode |
| `0x14CDB69E1` | `serchmessagepointer` | 🔴 TODO | Finds message text pointer (PSX-era typo) |
| `0x14037CDA0` | `InitCamera` | 🔴 TODO | Camera system initialization |

---

## Global Variables

### Event VM State

| Address | Name | Type | Purpose |
|---------|------|------|---------|
| `0x140D34448` | `gBEventMode` | byte/int | Current event execution mode |
| `0x140D36D50` | `eventlinkdata` | struct | Event chaining/branching links |
| `0x140D37460` | **`eventbuffer`** | byte[] | **Live event bytecode buffer** |
| `0x140D39C60` | **`eventwork`** | struct | **VM working memory** (registers/stack) |
| `0x140D3A3BC` | `jumpeventno` | int | Target event number for jumps |
| `0x140D3A430` | **`eventot`** | func_ptr[] | **Battle event opcode table** |
| `0x140D3A4A8` | `eventshakef` | bool | Screen shake flag |
| `0x140D3A570` | `messagepacket` | struct | Active dialogue packet |
| `0x140D43130` | `event_inf` | struct | Event metadata |
| `0x140D6A2B0` | `event_buf_maybe` | byte[] | Secondary event buffer |

### Event Control

| Address | Name | Type | Purpose |
|---------|------|------|---------|
| `0x141843A08` | **`weventot`** | func_ptr[] | **World event opcode table** |
| `0x1418502D8` | `gEventOrBattle` | int | Mode flag: event vs battle |
| `0x141850518` | `pEventUnitLookup` | ptr[] | Unit pointers for event choreography |
| `0x142FE5F24` | `ProcessingMiniEvent` | bool | Mini-event flag |
| `0x142FF1C3C` | `QueuedCurrentEvent` | int | Currently queued event ID |
| `0x142FF38EC` | `NextEvent` | int | Next event to execute |
| `0x1437665D0` | `EventControl` | struct | Master event control structure |
| `0x143801 1B8` | `EventStatus` | struct | Event execution status |
| `0x143CD39F0` | `pEventControl` | ptr | Pointer to EventControl |

### Message System

| Address | Name | Type | Purpose |
|---------|------|------|---------|
| `0x143CD37D8` | `pEventMessageResourceManager` | ptr | Message resource manager |
| `0x143CD3810` | `pEventIdDatabase` | ptr | Event ID database |
| `0x143CD3818` | `pMessageFrameManager` | ptr | Message frame/bubble manager |
| `0x143CD3828` | `pMessageGroupManager` | ptr | Message group manager |
| `0x143CD3840` | `pMessageBufferManager` | ptr | Message text buffer manager |
| `0x143D13C50` | `aLastConverseMessage` | str | Last conversation text |
| `0x143D14880` | `aLastDismissMessage` | str | Last dismiss/farewell text |

---

## NXD Tables (Event-Related)

| Global | Address | Table Name | Purpose |
|--------|---------|------------|---------|
| `NEXTable_eventid` | `0x143CD3DF8` | eventid | Event ID → script mapping |
| `NEXTable_scenarioid` | `0x143CD3FE0` | scenarioid | Scenario/chapter conditionals |
| `NEXTable_enhancedbattleevent` | `0x143CD42E8` | enhancedbattleevent | **TIC-only** battle events |
| `NEXTable_enhancedworldevent` | `0x143CD4348` | enhancedworldevent | **TIC-only** world events |
| `NEXTable_seadevent` | `0x143CD3F90` | seadevent | SEAD audio events |
| `NEXTable_speaker` | `0x143CD3E98` | speaker | Speaker portrait/name data |
| `NEXTable_spellmessage` | `0x143CD3DD0` | spellmessage | Spell incantation text |
| `NEXTable_caption` | `0x143CD3E78` | caption | Caption/subtitle display |
| `NEXTable_scionfiles` | `0x143CD3FD8` | scionfiles | Cutscene script files |
| `NEXTable_scionlabels` | `0x143CD3FD0` | scionlabels | Cutscene script labels |
| `NEXTable_bgmtransition` | `0x143CD3FC0` | bgmtransition | BGM transition rules |
| `NEXTable_map` | `0x143CD39C0` | map | Map data |
| `NEXTable_entryno` | `0x143CD3E08` | entryno | ENTD entry numbers |
| `NEXTable_entryarea` | `0x143CD3D10` | entryarea | ENTD entry areas |
| `NEXTable_gameprogress` | `0x143CD3ED8` | gameprogress | Story progress tracking |
| `NEXTable_sortieconfirm` | `0x143CD3E10` | sortieconfirm | Battle confirmation |

---

## Architecture Notes

- **Two opcode tables**: `eventot` (battle) and `weventot` (world) — mirrors PSX BATTLE.BIN/WORLD.BIN split
- **"Scion" system**: `scionfiles`/`scionlabels` may be FF16 engine's cutscene format layered above raw bytecode
- **TIC additions**: `enhancedbattleevent` and `enhancedworldevent` are remaster-only content
- **Event bytecode loads into `eventbuffer`** at `0x140D37460` — intercept this to dump scripts
- **`set_event_table`** populates `eventot`/`weventot` — decompiling this reveals every opcode handler

## File Locations

| What | Path |
|------|------|
| Roadmap | `remaster/event_tool/ROADMAP.md` |
| Starting points | `remaster/event_tool/STARTING_POINTS.md` |
| This index | `remaster/event_tool/RESOURCE_INDEX.md` |
| Phase 0 recon | `remaster/event_tool/PHASE0_RECON.md` |
| Dicene's names | `reference/Dicenes_Names/audit_report.txt` |
| Dicene's globals | `reference/Dicenes_Names/fft 1.2.0 global names.txt` |
| Formula reference | `remaster/formulas/FORMULA_REFERENCE.md` |
| Formula cheatsheet | `remaster/formulas/FORMULA_CHEATSHEET.md` |
| Ability layout | `remaster/tables/Ability.layout.md` |
| Decompiled formulas | `reference/decompiled_setskillresult.c` |
| SetupSkillDispatch | `reference/decompiled_sub_140300610_large_uses_100.c` |
