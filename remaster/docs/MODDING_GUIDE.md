# FFT:TIC — Modding Guide

> End-to-end technical guide for creating mods for FFT: The Ivalice Chronicles.
> Covers data table mods, runtime memory access, and the full toolchain.

---

## How the Game Stores Data

TIC has **two layers** of game data:

```
┌──────────────────────────────────────────────┐
│  Layer 1: NXD Tables (245 tables in .pac)    │  ← Moddable via file replacement
│  Items, Jobs, Abilities, Battles, UI, etc.   │
├──────────────────────────────────────────────┤
│  Layer 2: Hardcoded Logic (FFT_enhanced.exe) │  ← Requires runtime hooking
│  Singleton managers, formulas, AI, rendering │
└──────────────────────────────────────────────┘
```

**Layer 1** is the easiest path — extract `.pac` archives, edit `.nxd` tables as SQLite, repack as `.diff.pac` overlays. No code modification needed.

**Layer 2** requires understanding the engine's class hierarchy, singleton accessors, and memory layout. This is where our binary analysis comes in.

---

## Toolchain Setup

### Required Tools

| Tool | Purpose | Source |
|---|---|---|
| **FF16Tools.CLI** | PAC extraction, NXD↔SQLite conversion | [GitHub](https://github.com/Nenkai/FF16Tools/releases) |
| **SQLiteStudio** | Visual NXD table editor | [sqlitestudio.pl](https://sqlitestudio.pl) |
| **Reloaded-II** | Mod manager + runtime mod loader | [GitHub](https://github.com/Reloaded-Project/Reloaded-II/releases) |

### Optional Tools

| Tool | Purpose | Source |
|---|---|---|
| **static analysis tools** | Executable analysis/decompilation | Commercial |
| **x64dbg** | Live debugging + memory inspection | [x64dbg.com](https://x64dbg.com) |
| **Cheat Engine** | Memory scanning for struct verification | [cheatengine.org](https://cheatengine.org) |

### Setup

1. Place `FF16Tools.CLI.exe` on your PATH
2. Always use the `-g fft` flag (without it, the tool defaults to FFXVI layouts)
3. Install the `fftivc.utility.modloader` mod in Reloaded-II

---

## Part 1: Data Table Modding (Layer 1)

### Step 1: Extract a PAC Archive

The game data lives in 55 `.pac` files split between `data/classic/` and `data/enhanced/`.

```powershell
$gameDir = "C:\Program Files (x86)\Steam\steamapps\common\FINAL FANTASY TACTICS - The Ivalice Chronicles"

# Extract the main data archive
FF16Tools.CLI pac-extract -i "$gameDir\data\enhanced\0002.pac" -o "c:\Projects\TIC\extracts\enhanced_0002"
```

### Step 2: Convert NXD to SQLite

```powershell
# Convert all .nxd files in the extract to a single SQLite database
FF16Tools.CLI nxd-to-sqlite -i "c:\Projects\TIC\extracts\enhanced_0002\nxd" -g fft
```

This creates a `.sqlite` file with one table per `.nxd` file. Open it in SQLiteStudio.

### Step 3: Edit Tables

The [NXD Table Catalog](NXD_TABLE_CATALOG.md) lists all 245 tables. Key tables for common mods:

| Mod Goal | Tables to Edit |
|---|---|
| Change item stats | `Item` |
| Modify job requirements | `Job`, `JobCommand`, `GeneralJob` |
| Edit abilities | `Ability` |
| Adjust battle encounters | `Battle`, `BattleObjective` |
| Change poaching rewards | `PoachItem` |
| Edit shop inventories | (hardcoded — see Part 2) |
| Modify character names/text | `CharaName`, `Caption` |
| Adjust Deep Dungeon | `DeepDungeon` |
| Change errand rewards | `Profit`, `ProfitBonusItem` |
| Edit map connections | `MapRouteTable`, `Route` |

Column definitions for each table are in [Nenkai/fftivc-nex-layouts](https://github.com/Nenkai/fftivc-nex-layouts).

### Step 4: Convert Back and Repack

```powershell
# Convert SQLite back to .nxd files
FF16Tools.CLI sqlite-to-nxd -i "c:\Projects\TIC\databases\my_edit.sqlite" -g fft

# Create a diff overlay (only changed files)
FF16Tools.CLI pac-repack -i "c:\Projects\TIC\extracts\enhanced_0002_modified" -o "c:\Projects\TIC\mods\my-mod\0002.diff.pac"
```

### Step 5: Load via Reloaded-II

1. Place the mod folder (with `.diff.pac`) in Reloaded-II's mod directory
2. Enable the mod
3. Launch the game through Reloaded-II

The `.diff.pac` layers over the base archive at runtime — no original files are modified.

### Localized Tables

Some tables have language-specific variants. The PAC archives use locale suffixes:

```
0002.pac      → Base data (shared across languages)
0002.en.pac   → English text overrides
0002.ja.pac   → Japanese text overrides
0002.de.pac   → German text overrides
0002.fr.pac   → French text overrides
```

When modding text/localized tables, extract the locale-specific `.pac` file and create a locale-specific `.diff.pac`.

---

## Part 2: Runtime Engine Access (Layer 2)

Some game data is **hardcoded in the executable** and can't be changed via NXD tables alone. This includes shop inventories, damage formulas, JP calculations, and AI behavior.

### Engine Architecture

The game uses two interlocking namespaces:

- **`ffto`** — Game-specific logic (559 classes)
- **`faith`** — Shared engine framework (534 classes)

All major game systems are implemented as **singletons** accessed via `faith::Singleton<T>`:

```
BattleControl      — Battle state machine
GlobalWork         — Master save/character data (108 fields per character)
ShopManager        — Shop inventories and pricing
UnitManager        — Character roster management
PostBattleCalc     — Post-battle JP/EXP/rewards
SceneManager       — Map/scene transitions
EventControl       — Story event scripting
WorldMapManager    — Overworld navigation
```

### Finding Singletons at Runtime

Each singleton's instance is stored at a **global pointer** in memory. To find it:

1. Locate the singleton's vtable in the `.rdata` section using a known address:

```cpp
// From singleton_signatures.h
static constexpr uintptr_t GlobalWork_Singleton_VTable = 0x14070E818;
static constexpr uintptr_t ShopManager_Singleton_VTable = 0x14070E330;
```

2. Cross-reference the vtable to find the global pointer (the constructor writes the vtable pointer into the object, and stores the object address in a static global).

3. At runtime, read the global pointer to get the live singleton instance.

### GlobalWork Memory Layout

The `GlobalWork` singleton stores all character data. Each character occupies a fixed-size record with 108 fields:

```cpp
// From globalwork_character.h
struct CharacterData {
    int32_t character;           // [0] Character template ID
    uint32_t resist;             // [1] Resistance flags
    int32_t job;                 // [2] Current job (0-22)
    int32_t union_;              // [3] Team assignment
    int32_t sex;                 // [4] Gender
    int32_t birth_1;             // [5] Zodiac 1
    int32_t birth_2;             // [6] Zodiac 2
    int32_t sub_command;         // [7] Secondary ability
    int32_t reaction_ability_1;  // [8] Reaction slot 1
    int32_t reaction_ability_2;  // [9] Reaction slot 2
    int32_t support_ability_1;   // [10] Support slot 1
    int32_t support_ability_2;   // [11] Support slot 2
    int32_t move_ability_1;      // [12] Move slot 1
    int32_t move_ability_2;      // [13] Move slot 2
    int32_t equip_item;          // [14] Equipment ref
    int32_t exp;                 // [15] EXP
    int32_t level;               // [16] Level
    int32_t start_bcp;           // [17] Base Bravery
    int32_t start_faith;         // [18] Base Faith
    int32_t hp_max_base;         // [19] Base HP
    int32_t mp_max_base;         // [20] Base MP
    int32_t wt_base;             // [21] Base Speed
    int32_t at_base;             // [22] Base Phys ATK
    int32_t mat_base;            // [23] Base Mag ATK
    uint32_t job_change_flag;    // [24] Unlocked jobs
    uint32_t ability_flag[22];   // [25-46] Learned abilities per job
    int32_t job_level;           // [47] Current job level
    uint16_t job_point[23];      // [48-70] Current JP per job
    uint16_t total_job_point[23]; // [71-93] Lifetime JP per job
    // ... chr_name, name_no, in_trip, parasite, egg_color, pspKilledNum
    // ... unit_order_id, unit_starting_team, unit_join_id
    // ... current_equip_set_number, ffto_equip_set0-2, charaNameKey
};
```

See [globalwork_character.h](../reference/globalwork_character.h) for the complete definition.

### Signature Scanning

Hardcoded addresses shift between game updates. Use **signature patterns** instead:

```cpp
// From signature_patterns.h

// GlobalWork::Init — find this to locate the field registration
// 40 55 53 56 48 8D AC 24 30 DB FF FF B8 D0 25 00 00 E8 ?? ?? ?? ?? 48 2B E0
auto gwInit = ScanPattern(textBase, textSize,
    "40 55 53 56 48 8D AC 24 30 DB FF FF B8 D0 25 00 00");

// NXD loader — hook this to intercept table loading
// 48 89 5C 24 18 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 50 FF FF FF
auto nxdLoader = ScanPattern(textBase, textSize,
    "48 89 5C 24 18 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 50 FF FF FF");
```

See [signature_patterns.h](../reference/signature_patterns.h) for all patterns.

### String References

Key strings embedded in the executable that you can search for:

| String | Address | Purpose |
|---|---|---|
| `%s/%s.nxd` | `0x14071BED8` | NXD file path format — hook callers to intercept table loads |
| `ability_flag_00` | `0x1406FC0F0` | Start of ability flag field names |
| `job_point_00` | `0x1406FC280` | Start of JP field names |
| `ffto_equip_set0` | — | Enhanced-mode equipment set fields |

---

## Part 3: The Two Game Modes

TIC contains **two games in one executable**:

- **Classic Mode** (`FFT_classic.exe`) — PSX-faithful, uses base ~100 GlobalWork fields
- **Enhanced Mode** (`FFT_enhanced.exe`) — New HD version with extended features

Enhanced mode adds `ffto_`-prefixed fields:
- `ffto_equip_set0/1/2` — Three equipment loadout presets (new feature)
- `current_equip_set_number` — Active loadout slot
- `charaNameKey` — Localization key

When modding, test both modes if your changes touch shared data.

---

## Part 4: Job System Deep Dive

### 23 Jobs (indices 0-22)

The achievement system confirms these job classes:

| Confirmed Jobs | Achievement Source |
|---|---|
| Arithmetician | `AchievementBattleArithmetician` |
| Bard | `AchievementBattleBard` |
| Black Mage | `AchievementBattleBlackMagicks` |
| Monk | `AchievementBattleCharge` |
| Dancer | `AchievementBattleDancer` |
| Dragoon | `AchievementBattleDragoon` |
| Geomancer | `AchievementBattleGeomant` |
| Holy Knight | `AchievementBattleHoly` |
| Mime | `AchievementBattleMime` |
| Mystic | `AchievementBattleMystic` |
| Ninja | `AchievementBattleNinja` |
| Orator | `AchievementBattleOrator` |
| Samurai | `AchievementBattleSamurai` |
| Dark Knight | `AchievementBattleShockwave` |
| Summoner | `AchievementBattleSummoner` |
| Time Mage | `AchievementBattleTeleport` |
| Thief | `AchievementBattleThief` |
| Chemist | `AchievementBattleThrowItems` |

Plus Squire, Knight, Archer, White Mage, and any TIC-exclusive additions.

### JP Tracking

Each character tracks JP in two arrays:
- `job_point[23]` — Current JP (spent when learning abilities)
- `total_job_point[23]` — Lifetime JP earned (never decreases)

The `ability_flag[22]` array is a bitmask per job indicating which abilities have been learned.

---

## Reference Documents

| Document | What It Covers |
|---|---|
| [QUICKSTART.md](QUICKSTART.md) | Tool setup, first mod creation |
| [ENGINE_REFERENCE.md](ENGINE_REFERENCE.md) | Full engine architecture, all subsystems, all singletons |
| [NXD_TABLE_CATALOG.md](NXD_TABLE_CATALOG.md) | All 245 NXD data tables with descriptions |
| [globalwork_character.h](../reference/globalwork_character.h) | C++ struct for character data (108 fields) |
| [singleton_signatures.h](../reference/singleton_signatures.h) | All singleton vtable addresses |
| [signature_patterns.h](../reference/signature_patterns.h) | Update-proof byte patterns for sig scanning |
| [globalwork_fields.md](../reference/globalwork_fields.md) | Human-readable field map |
| [DOCUMENT_INDEX.md](../reference/DOCUMENT_INDEX.md) | Master index of all documentation |

### External Resources

| Resource | Link |
|---|---|
| NXD Column Definitions | [fftivc-nex-layouts](https://github.com/Nenkai/fftivc-nex-layouts) |
| FF16Tools | [GitHub](https://github.com/Nenkai/FF16Tools) |
| Reloaded-II | [Wiki](https://reloaded-project.github.io/Reloaded-II/) |
| FFHacktics Discord | Community research hub |

---

## Safety Rules

- ⚠️ **Always back up saves** before testing mods
- ⚠️ **Never modify executables** — all modding is data-level via `.diff.pac` overlays
- ⚠️ **Never commit extracted game assets** to version control
- ⚠️ **anti-tamper is present** — the modding approach works *alongside* DRM, not against it
- ⚠️ **Test both Classic and Enhanced** modes if your mod touches shared data
