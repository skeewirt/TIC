# Ability.layout — TIC Binary-Verified Edition

> **Base**: [Nenkai/fftivc-nex-layouts](https://github.com/Nenkai/fftivc-nex-layouts) @ main  
> **Binary**: `FFT_enhanced.exe` v1.0.0.0 (Steam)

```
table_name|Ability
set_table_type|SingleKeyed
set_table_category|SingleKeyed_Localized
use_base_row_id|true
```

---

## Table Accessor

| | |
|---|---|
| **Sig (Nenkai)** | `40 53 48 83 EC ? 48 8B 05 ? ? ? ? 89 CB` |
| **Resolved (v1.0.0.0)** | `40 53 48 83 EC 20 48 8B 05 6B 76 0E FB 89 CB` |
| **Status** | Confirmed |
| **Address** | `0x148BEC640` (131 bytes, `.xtext` segment) |
| **Thunk** | `j_Ability_en_149688D60` (`0x1400F72F4`) → `jmp sub_148BEC640` |
| **Table ID** | 39 (`0x27`) |
| **Table Global** | `pGUIStringTable` |
| **Lazy Init** | `sub_1403CE590(pSteamAchievements, 39)` → caches into global |
| **Row Lookup** | `NexSearchRow1K(table_ptr, ability_id)` → row pointer |

```c
void* sub_148BEC640(uint a1) {
    if (!pAbilityTable)
        pAbilityTable = sub_1403CE590(pSteamAchievements, 39);
    row = NexSearchRow1K(pAbilityTable, a1);
    if (!row) return nullptr;
    return sub_1403CE30C(row);
}
```

> [!NOTE]
> `j_GetAbilityJpCost` (`0x14DFDAB10`) uses the same pattern and returns `row[32]` = `uint16` at byte offset `0x40` (JpCost fields).

---

## Column Map

### `0x00` — DLCFlags — `int`

```
add_column|DLCFlags|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | DLC entitlement bitfield. Individual bits correspond to DLC packs or distribution channels. Engine checks specific bits to gate ability visibility based on owned content. |
| **Callers** | `uistatuseffectcategory_1400F8374`, `DrawCharacterCombatTimeline_maybe`, `sub_1402A31A8`, `sub_148CA2640`, `sub_14904B770`, `sub_14905967D`, `sub_14906C236` |

---

### `0x04` — IconId — `int`

```
add_column|IconId|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Icon atlas index. Passed to `fGetAbilityIconPath` for menu/UI display. |
| **Callers** | `sub_140110220`, `sub_140107FA0`, `sub_148CA2640` |

---

### `0x08` — Name — `string|rel`

```
add_column|Name|string|rel
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Ability display name. NXD relative string resolved via `row + 8 + *(int*)(row + 8)`. Fed to `GUITextNode__SetText` and `Text_CopyString`. |
| **Callers** | `sub_140107FA0`, `sub_140152808`, `sub_140154C38`, `sub_140201D20`, `DrawCharacterCombatTimeline_maybe`, `sub_140110220` |

---

### `0x0C` — Description — `string|rel|-4`

```
add_column|Description|string|rel|-4
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Ability description text. NXD relative string with -4 base adjustment. |
| **Callers** | `sub_1402A4F54`, `sub_14DBCE0E0` |

---

### `0x10` — UnusedString10 — `string|rel|-8`

```
add_column|UnusedString10|string|rel|-8
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 — empty in all rows |
| **Description** | Unused string column. Resolves to empty string (`""`) for every ability in the shipped NXD data. Vestigial field — possibly a holdover from PSP/WotL that was never populated in TIC. |
| **Callers** | 1 hit — `sub_140154C38` via `xmmword` bulk copy only (no individual read) |

---

### `0x14` — UnusedShort14 — `short`

```
add_column|UnusedShort14|short
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 — zero in all rows |
| **Description** | Unused short. Value is `0` for every tested ability (Cure, Fire, Holy, Haste, Esuna, Protect). No code reads this field — 0 hits from `j_Ability_en` callers. Dead field. |
| **Callers** | None |

---

### `0x16`–`0x19` — NounForm Bytes — `byte` × 4

```
add_column|NounFormByte1|byte
add_column|NounFormByte2|byte
add_column|NounFormByte3|byte
add_column|NounFormByte4|byte
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Text grammar block for ability name formatting (article type, plural form, gender). Shared structure across `Item`, `PoachItem`, `Ability`, `CharaSlot`, `JobCommand` tables. NounFormByte3 varies by ability (values 0–11 observed), others mostly 0/1. |
| **Callers** | `getsomerows_1400F2B7C` |

---

### `0x1A` — Padding — `short`

```
add_column|Padding1A|short
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Struct alignment padding between noun form block (`0x16`–`0x19`) and Comment string (`0x1C`). Always `0`. |
| **Callers** | None |

---

### `0x1C` — Comment — `string`

```
add_column|Comment|string
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 — NULL in all rows |
| **Description** | Empty for all 512 abilities (confirmed via FF16Tools `nxd-to-sqlite`). Non-localized string column with no data in the shipped build. Schema placeholder only. |
| **Callers** | None |

---

### `0x20` — UiId — `int`

```
add_column|UiId|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Foreign key into the UI NXD table. Provides supplemental tooltip text for ability menus. Only Zodiark (1042) and Ultima (1041) use this — both resolve to: *"This is a special ability that can only be learned when an enemy unit uses it on one of your allies."* All other abilities use 0 (no supplemental text). |
| **Callers** | `sub_14DBCE0E0` (GetUIRow lookup), `sub_1402A4F54` (UI text), `sub_1402A31A8` (ApplyUIRowToTextNode) |

---

### `0x24` — BattleVoiceIds — `int[]`

```
add_column|BattleVoiceIds|int[]
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Array of indices into the `BattleVoice` table (53 entries). Determines which voice line(s) a character shouts when casting the ability. Multiple entries allow randomized variation. Patterns: offensive spells `[5]`, healing `[9,10]`, buffs `[11,12]`, debuffs `[13]`, revive `[14]`. `0x24` = array base, `0x28` = count field. All 512 rows populated. |
| **Callers** | `sub_1402639EC` (array length check + indexed read) |

---

### `0x2C` — UiId2 — `int`

```
add_column|UiId2|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 |
| **Description** | Foreign key into the UI NXD table. Provides activation-condition tooltip text for Reaction/Support/Movement abilities. 30 of 512 abilities use this (482 are 0). Values map to: `800` = *"Activates even when damage dealt is zero"*, `801` = *"Activates when HP loss is 1 or more"*, `802` = *"Activates even when no damage is dealt, such as when parried or evaded"*, `809` = *"Activated by standard attacks, Arts of War, Aim, Throw, and Aimed Shot"*, `812` = formatted "None" (no special condition). |
| **Callers** | `sub_14029E078` (GetUIRow lookup, guarded by `test ecx, ecx; jz skip`) |

---

### `0x30` — SlotColorTint — `int`

```
add_column|SlotColorTint|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 — in-game confirmed by NotARobot0010 (monster Job Detail panel color tint) |
| **Description** | Controls the color tint of ability slots on the **Job Change / Job Detail** panel (`ffto_job_detail.uib`). The slots are only rendered when the unit's Job ID (from the 174-entry table) is ≥ 8 — IDs < 8 (standard human jobs) skip the `JobSp` display entirely, meaning this tint is only visible for non-standard unit types (monsters, special story units, etc.). The table index is proven to be the **Job ID** (`*(unit+3)` byte) via `sub_1402745CC` and `sub_14027310C`, which both read `*(a1+3)` as the index into the 174-entry table at `unk_140780EA0` (49-byte stride). The rendering class is identified by its initializer `sub_1402A2C6C` (`"JobSp%02d"`, `"JobName"`, `"JobLv"`, `"JobEXP"`, `"Jp"`, `"TextSp"`). Its caller `sub_14012BFFC` (vtable at `0x14070C188`) references `"JobDetailMenu"`, `"JobDetailLR"`, `"JobAbility"`, `"ListJobAbility"`, `"JobChangeConfirm"`, and `"Monster"`. A full UIB scan confirmed `JobSp` exists in only `ffto_job_detail.uib`. Sole consumer `sub_1402A31A8` loops over 4 slots (`Sp0`–`Sp3`). The first 8 bytes of each table entry are 4 × 2-byte ability keys (27 unique abilities across Reaction, Support, and Movement categories; 89 of 174 entries non-zero). For each slot, the code looks up the NXD row via `sub_1400F72F4(abilityKey)` and reads `*(row + 0x30)`: if equal to `2`, plays the `"Good"` timeline; otherwise plays `"Bad"`. Value `0` (default, 511 of 512 abilities) renders **pinkish/salmon RGBA(241, 192, 184, 255)**. Value `2` (only "Cannot Enter Water", Key 497) renders **light blue/cyan RGBA(221, 244, 245, 255)**. Colors confirmed via UIB binary diff (Nenkai FF16Tools format reference). |
| **Callers** | `sub_1402A31A8` (sole consumer) |

---

### `0x34` — PassiveSortOrder — `int`

```
add_column|PassiveSortOrder|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 — data-driven + binary consumer + UI screen confirmed |
| **Description** | Display sort order for passive abilities in the Reaction/Support/Movement equip lists. Value `0` for all 432 action/spell abilities (not used in passive lists; treated as `999999` by the sort). The 80 non-zero entries are unique multiples of 10, divided into three ranges by category: **Reaction** (1000–1440, 30 abilities), **Support** (2000–2300, 28 abilities), **Movement** (3000–3210, 22 abilities). The 10-step spacing allows inserting new abilities without reindexing. **Binary consumer**: `sub_14028672C` implements a **bubble sort** that directly reads `v32[13]` (= `*(resolvedRow + 0x34)`, DWORD offset 13 = byte offset 52 = 0x34) from the Ability NXD table global (`qword_143CD3CB8`). Rows are looked up via `sub_1403CEE1C` (NXD row finder) and resolved via `sub_1403CE30C`. Comparison logic: sorts ascending by 0x34 value, tiebreaks by ability key. Zero values are replaced with `999999` (line 144: `v33 = 999999`), pushing unsorted abilities to the end. The sort function takes a category/type parameter (`a4`) that filters which passive category is being sorted. **UI screen**: `UIAddonFFTOUnitEquip` (RTTI class `.?AVUIAddonFFTOUnitEquip@UI@Game@ffto@@`). The menu input handler `sub_1402B83EC` processes button ID `100`, setting `dword_14180AFE4 = 27`. The main dispatcher `sub_1401FC3F4` indexes `funcs_1401FC41F[27]` → `sub_14033223C` → `sub_1403327F0` → `sub_140362D04` (passive list builder) → `sub_14028672C` (sort). This is the **Unit Equip screen's Ability sub-panel** — where the player selects Reaction/Support/Movement abilities to equip on a unit. |
| **Callers** | `sub_14028672C` (bubble sort) ← `sub_140362C54`/`sub_140362D04` (list builders) ← `sub_1403327F0` ← `sub_14033223C` (state 27) ← `funcs_1401FC41F` dispatch table ← `sub_1401FC3F4` ← `UIAddonFFTOUnitEquip` (button ID 100) |

---

### `0x38` — AbilityReactionVoiceTypeId — `int`

```
add_column|AbilityReactionVoiceTypeId|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 — data-driven + binary consumer + UI class confirmed |
| **Description** | Index into the `AbilityReactionVoiceType` NXD table (4 rows, keys 0–3), controlling which set of **target reaction voice clips** play when this ability hits. **Value 0** (486 abilities): default/no special reaction voice. **Value 2** (21 abilities): summons (Moogle, Carbuncle, Faerie), katana draws (Murasame, Kiyomori, Masamune), Bard songs (Seraph Song through Nameless Song), Dancer dances (Witch Hunt through Last Waltz) — all multi-target or AoE buff/status abilities. **Value 3** (5 abilities): Raise, Arise, Revive, Squeal, Phoenix Down — specifically revival abilities. Value 1 exists in the lookup table but is unused by any ability. The `AbilityReactionVoiceType` lookup table has 12 DWORD columns (Unknown4–Unknown2C) containing voice parameter weights; row 3 (revival) has distinct values at columns Unknown24/Unknown28 (`4,4` vs `1,1`), suggesting a unique "revived" voice reaction. **Binary consumer**: `sub_14018CBDC` reads `v21[3]` (= `*(resolvedRow + 0x0C)`, DWORD index 3 within the inner resolved struct, corresponding to NXD column 0x38). The value is used as a key to look up `qword_143CD3E38` (the `AbilityReactionVoiceType` table global) via `sub_1403CEE1C` (NXD row finder). The resolved voice type row parameters are then passed to the voice playback system. **UI class**: `UIAddonFFTOConfig` (RTTI class `.?AVUIAddonFFTOConfig@UI@Game@ffto@@`). The consumer is vtable slot +32 of this class, called during tab initialization (`Config` → `TabAll` → `TabButton%02d`). A secondary caller `sub_1401884FC` (vtable slot +112, slot [14]) handles runtime voice selection. |
| **Callers** | `sub_14018CBDC` (voice type resolver) ← `sub_140187020` (vtable[4], init) / `sub_1401884FC` (vtable[14], runtime) ← `UIAddonFFTOConfig` vtable at `off_140708608` |

---

### `0x3C` — AbilityAnimType — `int`

```
add_column|AbilityAnimType|int
```

| | |
|---|---|
| **Status** | Verified 2026-04-24 — data-driven + binary consumer + value-2 branch traced |
| **Description** | Controls the battle VFX animation pipeline across three phases (`a2` = 0, 1, 2). The function `sub_140106790` takes `(a1=battleState, a2=phase, a3=subPhase)`. **Value 0** (497 abilities): default animation — normal VFX slot order, plays all three phases. **Value 1** (15 abilities): **swaps VFX attachment slots** (`a1+58744` ↔ `a1+58760`) in phase 2 so the VFX plays on-body (caster performs in place) rather than projecting outward; plays all three phases normally. Used by all 7 Bard songs, all 7 Dancer dances, and Celestial Stasis — abilities where the caster sings/dances on-the-spot. 14 of 15 also share `AbilityReactionVoiceTypeId = 2`. **Value 2** (0 abilities, fully wired): same VFX slot swap as value 1 in phase 2 (on-body performance), BUT in phase 3 (`a2=2`), **skips the `sub_1401062D8` animation call entirely** — the function returns without playing the follow-up/impact animation. This means value 2 = "self-performance only, no projectile/impact phase." No abilities currently use it, but the code path is complete and a modder can use it. Both reads are gated by the same validity check: `*(a1+58780) >= 0` AND `*(a1+58780) & 0xF800 == 0x7000`. **Binary consumer**: `sub_140106790` (225 lines, battle VFX controller). Ability row via `sub_1400F72F4` (6-line accessor). |
| **Callers** | `sub_140106790` (VFX controller) ← `sub_148624DFC` (battle renderer) ← `sub_1400E3DEC` ← `sub_140214A1C` / `sub_1402DAAE8` |

---

### `0x40` — JpCost — `short` (uint16, little-endian)

```
add_column|JpCost|short
```

| | |
|---|---|
| **Status** | Verified 2026-04-25 — resolved as uint16 (community correction by Talcall) |
| **Description** | JP cost for learning this ability, stored as a **little-endian uint16** at offset 0x40. Nenkai's layout incorrectly split this into two byte columns (`JpCost1` at 0x40, `JpCost2` at 0x41). Combined value = `byte[0x41] × 256 + byte[0x40]`. Range: 0–9999. Values match known PSX JP costs exactly: Cure=50, Fire=50, Haste=100, Raise=200, Arise=600, Holy=600, Meteor=900, Flare=1000, Zodiark=9999. The engine reads only the **low byte** individually via `sub_140280884` L77: `*(uint8*)(row + 64)` → copies to unit record at +50. The full 16-bit value is preserved in the NXD data but the engine caps the individual read at 255 for the combat stat copy. The **displayed JP learn cost** in the Learn Ability UI comes from a separate pre-computed table in **NXD Table 189**, not directly from this field. |
| **Callers** | `sub_140280884` L77 (reads low byte only as uint8, writes to unit record +50). Display chain: `sub_14029F828` → `sub_140128B90`/`sub_14013159C` → `sub_14012D9FC` → `sub_1403636F8` |

**Sample Values:**

| JpCost (uint16) | Low Byte (0x40) | High Byte (0x41) | Abilities |
|-----------------|-----------------|-------------------|-----------|
| 50 | 50 | 0 | Cure, Fire, Blizzard |
| 100 | 100 | 0 | Haste, Protect |
| 200 | 200 | 0 | Raise, Cura |
| 250 | 250 | 0 | Gravity, Steal EXP |
| 600 | 88 | 2 | Holy, Arise |
| 900 | 132 | 3 | Meteor, Firaja, Masamune |
| 1000 | 232 | 3 | Flare, Dual Wield, Reraise |
| 9999 | 15 | 39 | Zodiark, Ultima, Meltdown |

---

### `0x42` — IsRandomDamage — `byte`

```
add_column|IsRandomDamage|byte
```

| | |
|---|---|
| **Status** | Verified 2026-04-25 |
| **Description** | Per-ability damage variance multiplier. When nonzero, the damage formula applies a random scaling factor: `result = ((PRNG_15bit * IsRandomDamage) >> 15) + 1`, producing a value from 1 to (value+1). When 0, damage is fixed (result=1). Capped at 99. Only 6 of 512 abilities use this (all set to 1). |
| **Callers** | `sub_140107FA0` (battle action setup — copies NXD byte to battle context at +0x102D0), `sub_14027FABC` (damage randomization formula — reads from battle context, applies xorshift128 PRNG), `sub_140303200` (damage calculation — calls randomizer twice per action) |

**Data Distribution:**

| Value | Count | Abilities |
|-------|-------|-----------|
| 0 | 506 | All standard abilities |
| 1 | 6 | Pummel, Rush, Throw Stone, Cat Scratch, Tail Sweep, Phoenix Down |

**Data Flow:**
```
NXD Ability[0x42]
  → sub_140107FA0 L173: battle_context[0x102D0] = NXD_row[66]
    → sub_14027FABC L14: random_mult = ((xorshift128() & 0x7FFF) * battle_context[66]) >> 15) + 1
      → sub_140303200 L52,L63: applies random_mult to damage (called 2× per action)
        → sub_1401F14A0: battle action execution pipeline
```

**Formula (sub_14027FABC):**
```c
// xorshift128 PRNG state at xmmword_1408DFD58
v2 = state[0] ^ (state[0] << 11);
state = shift_left_4bytes(state);
state[3] ^= v2 ^ ((v2 ^ (state[3] >> 11)) >> 8);
// Random multiplier: 1 to (IsRandomDamage + 1)
return ((WORD6(state) & 0x7FFF) * IsRandomDamage) >> 15) + 1;
// Capped at 99
```

**Player Experience:** When using Pummel, Rush, Throw Stone, Cat Scratch, Tail Sweep, or Phoenix Down, the damage number shown fluctuates between the base calculated value and ~2× that value. All other abilities deal fixed calculated damage. A modder setting this to e.g. 5 would create ±500% damage variance.

---

### `0x43` — IsRandomStatus — `byte`

```
add_column|IsRandomStatus|byte
```

| | |
|---|---|
| **Status** | Verified 2026-04-25 |
| **Description** | Controls whether an ability's status effect is deterministic or randomly selected from a pool. When 1, the status pipeline randomly picks ONE status from the ability's status list and forces the application count to 1. When 0, the ability applies its fixed pre-defined status. Only 5 of 512 abilities use this. |
| **Callers** | `sub_140107520` (NXD accessor wrapper — reads byte 0x43 from ability row), `sub_140107694` (status application pipeline — branches on random vs fixed at L197/L211), `sub_140107554` / `sub_1401075F4` (status count setters — force count=1 when random), `sub_1403001A0` (battle formula reader — reads copied value from battle context) |

**Data Distribution:**

| Value | Count | Abilities |
|-------|-------|-----------|
| 0 | 507 | All standard abilities (fixed status effects) |
| 1 | 5 | Finishing Touch, Blaster, Mind Blast, Bewitching Gaze, Toot |

**Data Flow:**
```
NXD Ability[0x43]
  → sub_140107520: reads *(j_Ability_en(ability_id & 0x7FF) + 0x43)
    → sub_140107694 L197: if (IsRandomStatus) { random_select_from_pool } else { apply_fixed }
    → sub_140107554 L9-10: if (IsRandomStatus) { force_count = 1 }  (event 2786)
    → sub_1401075F4 L9-10: if (IsRandomStatus) { force_count = 1 }  (event 2787)
      → sub_140107FA0: battle action setup (also reads IsRandomDamage at 0x42)
```

**Key Logic (sub_140107554 / sub_1401075F4):**
```c
v4 = sub_140107520(a1);     // Read IsRandomStatus from NXD
if (v4)
    a2 = 1;                  // Force: only 1 status from pool
v7[0] = a2;
sub_1400FD360(a1 + 66088, v7);  // Apply to battle context
```

**Player Experience:** When a monster uses Blaster, the game randomly picks ONE status (e.g. KO or Petrify) from the ability's status pool instead of always inflicting the same effect. Mind Blast similarly randomizes which debuffs it applies. Standard spells like Blind or Sleep always inflict their named status (IsRandomStatus=0). A modder setting a spell like Fire to IsRandomStatus=1 would make it randomly select from Fire's status list instead of always applying the same one.
