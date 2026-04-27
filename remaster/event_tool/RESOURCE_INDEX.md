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
| `0x140225744` | `event_call` | ✅ TIC+WotL | **Main event loop** — pad, maps, weather, music, anims (605 lines) |
| `0x1402F1E6C` | `set_event_table` | ✅ TIC+WotL | Battle targeting setup (NOT an opcode table despite the name) |
| `0x14022470C` | `ask_event` | ✅ TIC+WotL | Conditional lookup — selects which event to run |
| `0x1402E578C` | `event_init_memory` | ✅ TIC+WotL | Initializes VM state (registers, stack, buffers) |
| `0x14F112B7D` | `event_init_system` | ⚠️ TIC obfuscated, ✅ WotL | Full event system boot |
| `0x14CFDE278` | `event_status_set` | ⚠️ TIC obfuscated, ✅ WotL | Sets event execution state flags |
| `0x14021F2E0` | `read_eventflag` | ✅ TIC+WotL | Reads persistent event flags (story progress) |
| `0x14021F360` | `write_eventflag` | ✅ TIC+WotL | Writes persistent event flags |
| `0x14025DA78` | `get_stop_event` | ✅ TIC+WotL | Checks for event termination condition |
| `0x14D8F1344` | `loadEventAnimation` | ⚠️ TIC obfuscated, ✅ WotL | Loads animation data for event choreography |
| `0x14F7496D0` | `reset_status_forevent2` | ⚠️ TIC obfuscated, ✅ WotL | Resets unit status for event re-entry |
| `0x14033EDEC` | `wld_event` | ✅ TIC+WotL | World-map event handler |

## Message / Dialogue Functions

| Address | Name | Status | Purpose |
|---------|------|--------|---------|
| `0x14020BDE8` | `drawmessagepolygons` | ✅ TIC+WotL | Renders speech bubble geometry |
| `0x1402D3138` | `Wdrawmessagepolygons` | ✅ TIC+WotL | World-map message renderer |
| `0x1402DA28C` | `makemessagepacket` | ✅ TIC+WotL | Constructs dialogue display data packet |
| `0x14D0F0640` | `makemessagestructure` | ⚠️ TIC obfuscated, ✅ WotL | Builds message struct from event bytecode |
| `0x14CDB69E1` | `serchmessagepointer` | ⚠️ TIC obfuscated, ✅ WotL | Finds message text pointer (PSX-era typo) |
| `0x14037CDA0` | `InitCamera` | ✅ TIC+WotL | Camera system initialization |

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
| `0x140D3A430` | **`eventot`** | runtime buf | **Event output/state data** (NOT an opcode table — zeroed at rest, populated from palette data during BeginRunningEvent) |
| `0x140D3A4A8` | `eventshakef` | bool | Screen shake flag |
| `0x140D3A570` | `messagepacket` | struct | Active dialogue packet |
| `0x140D43130` | `event_inf` | struct | Event metadata |
| `0x140D6A2B0` | `event_buf_maybe` | byte[] | Secondary event buffer |

### Event Control

| Address | Name | Type | Purpose |
|---------|------|------|---------|
| `0x141843A08` | **`weventot`** | runtime buf | **World event state data** (zeroed at rest) |
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

- **`eventot`/`weventot` are NOT opcode tables** — they are runtime state buffers (palette/display data), zeroed at rest
- **The actual opcode VM** is `event_maincommon()` — a 2,508-line function (17KB) that processes event bytecode. Fully decompiled from WotL.
- **Opcodes dispatch via `phaserec`** — an array of 10-word records mapping phase IDs to handler functions
- **"Scion" system**: `scionfiles`/`scionlabels` may be FF16 engine's cutscene format layered above raw bytecode
- **TIC additions**: `enhancedbattleevent` and `enhancedworldevent` are remaster-only content
- **Event bytecode loads into `eventbuffer`** at `0x140D37460` — intercept this to dump scripts
- **`set_event_table`** sets up battle targeting per unit, NOT opcode registration

## File Locations

| What | Path |
|------|------|
| **This index** | `remaster/event_tool/RESOURCE_INDEX.md` |
| Roadmap | `remaster/event_tool/ROADMAP.md` |
| Starting points | `remaster/event_tool/STARTING_POINTS.md` |
| Phase 0 recon | `remaster/event_tool/PHASE0_RECON.md` |
| **TIC decompiled funcs** | `remaster/event_tool/decompiled/*.c` (local, gitignored) |
| **WotL decompiled funcs** | `remaster/event_tool/decompiled/wotl/*.c` (366 files, local, gitignored) |
| **WotL symbol reference** | `remaster/event_tool/WOTL_SYMBOLS.md` |
| **WotL iOS binary** | `reference/wotl_ios/FFT_iPhone_armv7.bin` + `.i64` |
| **Opcode table analysis** | `remaster/event_tool/analysis/opcode_table.md` |
| **VM state analysis** | `remaster/event_tool/analysis/vm_state.md` |
| **Conditionals analysis** | `remaster/event_tool/analysis/event_conditionals.md` |
| **Message system analysis** | `remaster/event_tool/analysis/message_system.md` |
| IDA decompile script | `reference/scripts/decompile_event_system.py` |
| Dicene's names | `reference/Dicenes_Names/audit_report.txt` |
| Dicene's globals | `reference/Dicenes_Names/fft 1.2.0 global names.txt` |
| Formula reference | `remaster/formulas/FORMULA_REFERENCE.md` |
| Formula cheatsheet | `remaster/formulas/FORMULA_CHEATSHEET.md` |
| Ability layout | `remaster/tables/Ability.layout.md` |
| Decompiled formulas | `reference/decompiled_setskillresult.c` |
| SetupSkillDispatch | `reference/decompiled_sub_140300610_large_uses_100.c` |
