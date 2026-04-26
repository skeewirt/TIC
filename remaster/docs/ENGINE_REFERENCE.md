# FFT: The Ivalice Chronicles — Engine Reference

> **Interoperability research documentation** for mod tool development.
> Generated from static analysis tools headless analysis of `FFT_enhanced.exe` (342MB, protected).

---

## Architecture Overview

The TIC executable is built on two interlocking frameworks:

| Namespace | Purpose | Class Count |
|---|---|---|
| **`ffto`** | Game logic (FFT-specific) | 559 classes |
| **`faith`** | Engine framework (shared w/ FFXVI lineage) | 534 classes |
| **`SQEX::Sd`** | Audio middleware (CRI ADX2/Atom) | 292 classes |
| **`tinyxml2`** | XML parser | 18 classes |

**Total**: 1,428 RTTI classes, 1,380 vtables, 153,137 functions.

The game is **two games in one**: Classic (PSX-faithful) and Enhanced (new HD) modes. Classic mode uses the base ~100 GlobalWork fields; Enhanced adds `ffto_`-prefixed extensions like equipment set presets.

---

## Game Subsystems (`ffto::Game`)

### Core Systems

| Subsystem | Classes | Key Class | Description |
|---|---|---|---|
| **Battle** | 12 | `BattleControl` (singleton) | Turn-based combat engine |
| **Unit** | 1 | `UnitManager` (singleton) | Character roster management |
| **Shop** | 1 | `ShopManager` (singleton) | Buy/sell/equipment shops |
| **GlobalWork** | 1 | `GlobalWork` (singleton) | Master save state (108 fields per character) |
| **Scene** | 1 | `SceneManager` (singleton) | Scene/map transitions |
| **Event** | 2 | `EventControl` (singleton) | Story event scripting |
| **WorldMap** | 2 | `WorldMapManager` (singleton) | Overworld navigation |
| **WorldSituation** | 1 | `WorldSituationManager` | Chapter/story progress state |

### Feature Systems

| Subsystem | Classes | Description |
|---|---|---|
| **Achievement** | 79 | Trophy/achievement tracking (one class per achievement type) |
| **UI** | 135+ | Full UI framework: Agents (controllers) + Gadgets (widgets) |
| **GameUI** | 14 | UI infrastructure (fade, mouse, movie player) |
| **Sound** | 4 | Voice/SFX management |
| **Novel** | 4 | Visual novel reader system |
| **BraveStory** | 1 | In-game encyclopedia/codex |
| **Glossary** | 1 | Term glossary management |
| **Config** | 1 | Settings persistence |
| **Telemetry** | 1 | Analytics/telemetry |

### Battle Subsystem Detail (12 classes)

```
BattleControl          — Main battle state machine (singleton)
PostBattleCalc         — Post-battle JP/EXP/rewards (singleton)
GenerateAttackTeamManager — Enemy team generation (singleton)
BattleInput            — Player input during battle (8 vtable methods)
BattlePanzerManager    — Battle 3D model management
BattlePanzerResource   — Battle model resources
BWorkHolder            — Battle work memory holder
CharacterBattleVoiceController — Battle voice lines
EnhancedWordfield      — Enhanced mode battle text
EnhancedMarkingUtility — Enhanced mode targeting UI
MapViewCameraManager   — Battle camera control (singleton)
BattleVoiceController  — Voice playback controller
```

---

## Singleton Reference

All major game systems use `faith::Singleton<T>` for global access. Each singleton has:
- A **wrapper vtable** (`faith::Singleton<T>::vftable`) with lifecycle methods
- A **class vtable** (`T::vftable`) with actual game logic

| Singleton | Wrapper Vtable | Class Vtable |
|---|---|---|
| `BattleControl` | `0x14070FC50` | `0x14070FDD0` |
| `GlobalWork` | `0x14070E818` | `0x14070E828` |
| `PostBattleCalc` | `0x14070FC70` | `0x14070FCA0` |
| `ShopManager` | `0x14070E330` | `0x14070E380` |
| `UnitManager` | `0x14070E390` | `0x14070E3E0` |
| `NexModule` | `0x1406FBAD8` | *(engine-level)* |
| `SceneManager` | `0x14070E048` | — |
| `EventControl` | `0x14070DF10` | — |
| `WorldMapManager` | `0x14070E168` | — |
| `GlossaryManager` | `0x14070E450` | — |
| `WorldSituationManager` | `0x14070E4C8` | — |
| `EnhancedWordfield` | `0x14070FC40` | `0x14070FDC0` |
| `BattlePanzerManager` | `0x14070FC60` | `0x14070FD70` |
| `GenerateAttackTeamManager` | `0x14070FC80` | `0x14070FCC0` |
| `MapViewCameraManager` | `0x14070FC90` | `0x14070FCB0` |

---

## GlobalWork Character Data (108 Fields)

The `GlobalWork` singleton holds per-character save data. All fields registered in `sub_1400B93E4` (12,686 bytes).

### Character Identity
| Index | Field | Type | Notes |
|---|---|---|---|
| 0 | `character` | ID | Character template ID |
| 1 | `resist` | flags | Elemental/status resistance |
| 2 | `job` | ID | Current job class |
| 3 | `union_` | ID | Party/team assignment |
| 4 | `sex` | enum | Gender |
| 5 | `birth_1` | int | Zodiac component 1 |
| 6 | `birth_2` | int | Zodiac component 2 |

### Ability Configuration
| Index | Field | Type | Notes |
|---|---|---|---|
| 7 | `sub_command` | ID | Secondary action ability |
| 8-9 | `reaction_ability_1/2` | ID | Reaction ability slots |
| 10-11 | `support_ability_1/2` | ID | Support ability slots |
| 12-13 | `move_ability_1/2` | ID | Movement ability slots |

### Stats & Equipment
| Index | Field | Type | Notes |
|---|---|---|---|
| 14 | `equip_item` | ref | Equipment reference |
| 15 | `exp` | int | Experience points |
| 16 | `level` | int | Character level |
| 17 | `start_bcp` | int | Base Bravery/Courage |
| 18 | `start_faith` | int | Base Faith |
| 19 | `hp_max_base` | int | Base max HP |
| 20 | `mp_max_base` | int | Base max MP |
| 21 | `wt_base` | int | Base speed (Wait Time) |
| 22 | `at_base` | int | Base physical attack |
| 23 | `mat_base` | int | Base magic attack |

### Job System (23 jobs: 0-22)
| Index | Field | Notes |
|---|---|---|
| 24 | `job_change_flag` | Bitflags for unlocked jobs |
| 25-46 | `ability_flag_00..21` | Learned ability flags per job |
| 47 | `job_level` | Current job's level |
| 48-70 | `job_point_00..22` | Current JP per job |
| 71-93 | `total_job_point_00..22` | Lifetime JP per job |

### Identity & Meta
| Index | Field | Notes |
|---|---|---|
| 94 | `chr_name` | Character display name |
| 95 | `name_no` | Character name table index |
| 96 | `in_trip` | Currently on errand/dispatch |
| 97 | `parasite` | Monster egg parasite state |
| 98 | `egg_color` | Monster egg color variant |
| 99 | `pspKilledNum` | WotL multiplayer kills (legacy) |

### Enhanced Mode Extensions
| Index | Field | Notes |
|---|---|---|
| 100 | `unit_order_id` | Sort order in roster |
| 101 | `unit_starting_team` | Starting team assignment |
| 102 | `unit_join_id` | Recruitment sequence ID |
| 103 | `current_equip_set_number` | Active loadout preset (0-2) |
| 104-106 | `ffto_equip_set0..2` | Three equipment set presets |
| 107 | `charaNameKey` | Localization key for name |

---

## Data Loading Pipeline

### NXD Tables
Game data tables are loaded from `.nxd` files via the `NexModule` singleton:

```
Path format: "%s/%s.nxd" (0x14071BED8)
Loader function: sub_1403CE724 (314 lines of pseudocode)
```

The NXD loader parses text files with `#` comments and CR/LF line endings. Each row becomes an 80-byte record (`0x50 * row_count` allocation).

The `NexModule` creates `NxlResourceHandle` objects via `createResourceHandle()` to bridge file data into the engine's resource system.

### Hardcoded Tables
Some tables (ItemShops, JobNeedLevel) are **embedded directly in the executable** rather than loaded from `.nxd` files. These require signature scanning to locate at runtime (as done in PR #7's mod loader).

---

## Achievement System (79 classes)

The achievement system reveals job class names and game mechanics:

### Battle Job Achievements
| Achievement Class | Confirmed Job |
|---|---|
| `AchievementBattleArithmetician` | Arithmetician |
| `AchievementBattleBard` | Bard |
| `AchievementBattleBlackMagicks` | Black Mage |
| `AchievementBattleCharge` | Monk (Charge) |
| `AchievementBattleDancer` | Dancer |
| `AchievementBattleDragoon` | Dragoon |
| `AchievementBattleGeomant` | Geomancer |
| `AchievementBattleHoly` | Holy Knight / White Mage |
| `AchievementBattleMime` | Mime |
| `AchievementBattleMystic` | Mystic |
| `AchievementBattleNinja` | Ninja |
| `AchievementBattleOrator` | Orator |
| `AchievementBattleSamurai` | Samurai |
| `AchievementBattleShockwave` | Dark Knight (Shockwave) |
| `AchievementBattleSummoner` | Summoner |
| `AchievementBattleTeleport` | Time Mage (Teleport) |
| `AchievementBattleThief` | Thief |
| `AchievementBattleThrowItems` | Chemist (Throw Items) |

### Other Achievement Types
- **Story**: `Prologue`, `Chapter1-4`
- **Job mastery**: `FirstJobChange`, `JobMaster`, `JobMasterMania`
- **Facilities**: `FirstPoach`, `PoachProcess`, `FirstProfit`, `Workaholic`, `TreasureHunter`, `AdventurerMaster`
- **Side content**: `DeepDungeonClear`, `Novel`, `Journal`, `Glossary`, `SideStory`
- **Combat**: `EquipBreaker`, `CounterTackleKnockback`
- **Misc**: `ChocoboRider`, `EggHatch`, `Succession`, `MapItemDiscovery`

---

## UI Framework

The UI uses a two-tier class hierarchy:

### UIAgent (Controllers) — 47 classes
Handle screen-level logic. Key agents:
- `UIAgentFFTOShop` — Shop screen (vtable: `0x140707E58`, 12 methods)
- `UIAgentFFTOUnit` — Unit management
- `UIAgentFFTOBattleMain` — Battle HUD (vtable: `0x14070D758`, 9 methods)
- `UIAgentFFTOEmploy` — Recruitment screen
- `UIAgentFFTOPoach` — Poaching screen

### UIGadget (Widgets) — 68 classes
Reusable UI components:
- `UIGadgetFFTOShopItemList` — Shop item list (vtable: `0x140711D08`, **22 methods**)
- `UIGadgetFFTOJobDetailWindowBase` — Job detail panel
- `UIGadgetFFTOAbilityList` — Ability list widget
- `UIGadgetFFTOUnitEquipSetDetail` — Equipment set display
- `UIGadgetFFTOUnitEquipSetSelect` — Equipment set picker

---

## Key Addresses Quick Reference

| Address | What |
|---|---|
| `0x14071BED8` | `"%s/%s.nxd"` format string |
| `0x1400B93E4` | GlobalWork field registration (12,686 bytes) |
| `0x1403CE724` | NXD file loader/parser |
| `0x140195DC4` | UIAgentFFTOShop main logic (1,328 bytes) |
| `0x1400C0DB4` | `job_new` handler |
| `0x1400BCAA0` | `battle_chr_sort` handler |
| `0x1406FC0F0` | Start of `ability_flag_00..21` string block |
| `0x1406FC280` | Start of `job_point_00..22` string block |

---

## Engine Framework (`faith`)

Key engine classes (not game-specific):

| Subsystem | Key Classes |
|---|---|
| **Graphics** | `GraphicsManager`, `ViewBase`, `Renderer`, `MaterialInstance`, `ShaderCommon` |
| **Framework** | `Application`, `Window`, `WindowX64`, `Timer` |
| **Input** | `InputManager`, `XInputController`, `Keyboard`, `Mouse` |
| **Resource** | `ResourceManager`, `ResourceHandle`, `FileAccessor` |
| **Nex** | `NexModule`, `NexAccessor`, `ExcelDB` |
| **Network** | `NetworkManager`, `HTTP` |
| **XML** | `XMLBuilder`, `XMLVisitor` (wraps tinyxml2) |

---

*Generated: 2026-04-23 | static analysis tools | Analysis time: ~7 hours (auto-analysis) + ~30 seconds (script passes)*
