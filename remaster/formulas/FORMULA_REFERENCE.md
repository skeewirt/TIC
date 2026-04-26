# FFT:TIC Formula System Reference

> **Version**: 1.0 — April 2026  
> **Binary**: `FFTIVC-Win64-Shipping.exe` (Steam, protected)  
> **Companion**: [FORMULA_CHEATSHEET.md](FORMULA_CHEATSHEET.md) — simplified math for every formula

---

## Overview

This document maps the complete combat formula calculation pipeline in *Final Fantasy Tactics: The Ivalice Chronicles* (TIC). Every formula function address, the dispatch mechanism, shared subroutines, and the battle work (BWORK) unit struct are documented from static binary analysis.

**What this enables:**
- Hooking any formula function to override damage/healing/status calculations
- Understanding which stats (PA, MA, Faith, Brave, SP) each formula uses
- Removing hardcoded restrictions (weapon type checks, katana inventory, etc.)
- Creating new formula behaviors via code injection

---

## Architecture

```
NXD Ability Data (editable via FF16Tools)
  └─> AbilitySecondaryData[8] = Formula Type Byte
        └─> byte_140678FB0[type] maps to formula category (0-15)

SetupSkillDataAndDispatch (0x140300610, 1541 bytes)
  ├─> Loads AbilitySecondaryData via j_GetAbilitySecondaryData
  ├─> Loads weapon data via j_ItemGetWeaponData
  ├─> Extracts formula byte (v26) from secondary data offset [8]
  │     Valid range: 1-106 (clamped: if (v26-1) > 0x69, v26 = 1)
  ├─> Calls PreFormula_TargetSetup (0x140301C4C)
  ├─> DISPATCH: ((void(*)())qword_14067D128[v26])()  ← THE KEY
  ├─> For formula types < 7: calls PostDispatch_ApplyModifiers (0x1402FD434)
  └─> Calls PostFormula_FinalizeResult (0x140300D7C)

setskillresult (0x1403010E8, 1766 bytes) — RESULT APPLICATION
  ├─> Applies HP/MP damage or healing
  ├─> Applies status effects (j_set_status_all)
  ├─> Modifies Brave/Faith values
  ├─> Triggers reaction ability checks
  ├─> Awards JP/XP (j_Battle_CalculateActionExperience)
  └─> Handles item steal/break/gil changes
```

### Key Dispatch Instruction

```asm
; Address: 0x140300BB3 (inside SetupSkillDataAndDispatch)
; r12 = image base, rax = formula ID (1-106)
call    ds:rva qword_14067D128[r12+rax*8]
```

---

## Formula → Ability Mapping (87 Formulas, 368 Abilities)

> Source: Static binary array at `0x1407852F0` (20 bytes × 368 entries)
> Formula byte at offset +8 of each entry

| F | Count | Category | Key Abilities |
|---|-------|----------|---------------|
| 1 | 16 | Normal Attack (PA×WP) | Attack, Choco Beak, Tackle, Bite, Claw |
| 8 | 39 | MA × Y (Black Magick) | Fire/Blizzard/Thunder, Holy, Flare, Meteor, all Summons, Ultima, Bio |
| 9 | 3 | Gravity (% HP) | Gravity, Graviga, Lich |
| 10 | 38 | Faith-based status | Poison, Toad, Slow, Stop, Blind, Sleep, Break, Dispel, Silence |
| 11 | 15 | Faith-based buff | Reraise, Regen, Protect, Shell, Haste, Float, Reflect, Carbuncle |
| 12 | 6 | MA × Y healing | Cure, Cura, Curaga, Curaja, Moogle, Faerie |
| 13 | 3 | Raise/Revive | Raise, Arise |
| 14 | 1 | Instant death | Death |
| 15 | 2 | HP drain (PA) | Empowerment, Syphon |
| 16 | 2 | MP drain (PA) | Invigoration, Drain |
| 18 | 1 | Quick | Quick |
| 20 | 1 | Golem shield | Golem |
| 21-23 | 3 | Special (Arith) | Return, Disempower, Gravija |
| 26-27 | 4 | Stat sap | Speedsap, Powersap, Mindsap, Magicksap |
| 28 | 7 | Bard songs | Seraph Song → Finale |
| 29 | 7 | Dancer dances | Witch Hunt → Last Waltz |
| 30 | 7 | Iaido (heaven) | Heaven's Wrath → Divinity, Holy Breath |
| 31 | 6 | Iaido (nether) | Hell's Wrath → Impiety |
| 32-35 | 10 | Draw Out | Ashura, Kotetsu, Muramasa, Kiyomori, Masamune, Murasame |
| 36 | 12 | Geomancy | Sinkhole → Magma Surge |
| 37 | 4 | Rend equipment | Rend Helm/Armor/Shield/Weapon |
| 38 | 10 | Steal equipment | Steal Helm/Armor/Shield/Weapon/Accessory |
| 39-41 | 9 | Steal special | Steal Gil, Steal EXP, Steal Heart, Charm |
| 42 | 10 | Orator | Entice, Praise, Preach, Condemn, Insult |
| 43-44 | 4 | Rend stats | Rend Speed/Power/Magick, Rend MP |
| 45 | 5 | Holy Sword | Judgment Blade → Divine Ruination |
| 46 | 4 | Dark Sword (crush) | Crush Armor/Helm/Weapon/Accessory |
| 47-48 | 2 | Drain swords | Duskblade (HP), Shadowblade (MP) |
| 49-50 | 11 | Monk phys multi | Cyclone, Aurablast, Shockwave, Pummel |
| 51-53 | 4 | Monk support | Purification, Chakra, Revive |
| 54-60 | 12 | Squire/basic | Focus, Rush, Throw Stone, Tailwind, Steel, Shout, Chant |
| 56 | 22 | Status phys attack | Salve, Petrify, Shadowbind, Bad Breath, Grand Cross |
| 61 | 3 | % HP attack | Blaster, Mind Blast, Doom |
| 63-64 | 3 | Aimed Shot | Leg Shot, Arm Shot, Seal Evil |
| 65 | 1 | Celestial Stasis | Celestial Stasis |
| 66 | 4 | Construct attacks | Destroy, Compress, Dispose, Pulverize |
| 67-69 | 7 | Max HP/MP/Lvl | Vengeance, Manaburn, Ascension |
| 71 | 2 | Blood Drain | Blood Drain (HP steal) |
| 76-77 | 4 | Monster heal/drain | Choco Cure, Life Nymph, Bloodfeast, Drain Touch |
| 78 | 25 | PA × Y phys | Breath attacks, Cloud limits, Braver → Omnislash |
| 79-80 | 10 | Level/status phys | Goblin Punch, Doom Fist, Venom Fang, touch attacks |
| 81-84 | 5 | Monster buff | Choco Esuna, Guardian/Shell/Magick Nymph |
| 85-93 | 9 | Unique monster | Peck, Beam, Dragon skills, Level Drain |
| 94 | 3 | Tri-element | Tri-Thunder, Tri-Flame, Dark Whisper |
| 95-98 | 5 | Special attacks | Nanoflare, Trepidation, Dread Gaze |
| 102-106 | 5 | WotL additions | Dark Knight / Onion Knight abilities |

---

## Formula Dispatch Table

**Table base**: `0x14067D128` (entry 0 is a sentinel `0x00FF00FF00000000`)  
**Real entries start at**: `0x14067D130` (formula ID 1)  
**Entry size**: 8 bytes (x64 function pointer)  
**Total entries**: 80 (IDs 1-80), plus 6 unused CFG guard stubs

### Formula Type Categories

The `byte_140678FB0` lookup table maps ability type bytes to formula categories:

| Type Byte | Category | Description |
|-----------|----------|-------------|
| 0 | 15 | — |
| 1 | 8 | — |
| 2 | 11 | — |
| 3 | 12 | — |
| 4 | 13 | — |
| 6 | 1 | — |
| 8 | 10 | — |
| 17 | 4 | — |
| 18 | 9 | — |
| 19 | 7 | Item use |
| 20 | 2 | — |
| 21 | 3 | — |
| 52 | 9 | — |
| 56 | 2 | — |
| 57 | 2 | — |
| 59 | 7 | — |
| 62 | 7 | — |

### Primary Formulas (IDs 1-48)

| ID | Address | Size | Traits | Calls | Notes |
|----|---------|------|--------|-------|-------|
| 1 | `0x1402FDD80` | 5 | — | — | NOP/dummy |
| 2 | `0x1402FDDA0` | 97 | — | D8F0, DB50 | |
| 3 | `0x1402FDE04` | 54 | — | DA94, CB18 | |
| 4 | `0x1402FDE3C` | 284 | — | 303CE8, GetAbilSecondary, C81C, C914, C9FC, CAC8, BDDC, CB6C, CD98, CE2C, CEBC, CE88 | Complex multi-call |
| 5 | `0x1402FDF58` | 142 | — | C254, C364, C3A0, C3EC, C4F0, C6AC, DA94, CB18, CB6C, D870, D5A4 | |
| 6 | `0x1402FDFE8` | 57 | — | D8F0, C6AC, DA94, CB18, CB6C, CF54 | |
| 7 | `0x1402FE024` | 47 | — | C6AC, BDDC, DA94, CB6C | |
| 8 | `0x1402FE054` | 126 | — | D9D0, C84C, C914, C9FC, CAC8, BDDC, CB6C, CD98, CE2C, CEBC, CE88, D870, D5A4 | |
| 9 | `0x1402FE0D4` | 117 | — | D9D0, DC88, CD98, CE2C, CE88, D870, D5A4 | |
| 10 | `0x1402FE14C` | 32 | — | D9D0, DC88, D5EC | |
| 11 | `0x1402FE16C` | 88 | — | C84C, C914, BDDC, CBB0, CEBC, D06C, D5EC | |
| 12 | `0x1402FE1C4` | 70 | — | C84C, C914, BDDC, CB6C, CEBC | |
| 13 | `0x1402FE20C` | 146 | — | C84C, C914, BDDC, CBB0, CEBC, D06C, 300164, CFDC | |
| 14 | `0x1402FE2A0` | 262 | MA | D9D0, C84C, C914, C9FC, CAC8, BDDC, CBB0, CEBC, D06C, 300164 | |
| 15 | `0x1402FE3A8` | 85 | — | D9D0, DC2C, D01C | |
| 16 | `0x1402FE400` | 81 | — | D9D0, DC2C, CF54 | |
| 17 | — | — | — | — | UNUSED |
| 18 | `0x1402FE454` | 86 | — | C914, BDDC, CBB0, CEBC, D06C | |
| 19 | — | — | — | — | UNUSED |
| 20 | `0x1402FE4AC` | 175 | DIV100 | C914, CBB0, D06C | Faith-based (÷100) |
| 21 | `0x1402FE55C` | 42 | — | D9D0, DC2C | |
| 22 | `0x1402FE588` | 53 | — | D9D0, DC2C | |
| 23 | `0x1402FE5C0` | 72 | HP | D9D0, DC2C | HP-based |
| 24-25 | — | — | — | — | UNUSED |
| 26 | `0x1402FE608` | 121 | — | D9D0, C84C, C914, C9FC, CAC8, BDDC, CBB0, CEBC, D06C, D13C | |
| 27 | `0x1402FE684` | 76 | — | D9D0, DC88 | |
| 28 | `0x1402FE6D0` | 212 | MA | FB9C0 | MA-based |
| 29 | `0x1402FE7A4` | 203 | MA | FB9C0, C6AC | MA-based |
| 30 | `0x1402FE870` | 23 | — | D9D0, DBFC | Tiny (also used by 88, 89) |
| 31 | `0x1402FE888` | 294 | DIV100 | D9D0, C84C, C914, C9FC, CAC8, BDDC, CB6C, CD98, CE2C, CE88, D870, D5A4 | Faith-based (÷100) |
| 32 | `0x1402FE9B0` | 50 | — | D1C0 | |
| 33 | `0x1402FE9E4` | 98 | — | D1C0, C914, C9FC, CAC8, BDDC | |
| 34 | `0x1402FEA48` | 18 | — | D1C0 | |
| 35 | `0x1402FEA5C` | 55 | — | D1C0, CB6C | |
| 36 | `0x1402FEA94` | 63 | — | D9D0, DBAC | |
| **37** | **`0x1402FEAD4`** | **342** | — | **SetupSkillDataAndDispatch**, D8F0, DA94, CBB0, D06C, D0E0 | **Recursive dual-strike** |
| 38 | `0x1402FEC2C` | 204 | — | D228, C168, D8F0, DD44, D0E0 | |
| 39 | `0x1402FECF8` | 94 | — | D8F0, DD44, CC0C | |
| 40 | `0x1402FED58` | 270 | MA, PA | D8F0, C87C, C96C, C9A4, CA54, BDDC, CBB0, D06C | Physical+Magic hybrid |
| 41 | `0x1402FEE68` | 121 | MA | BDDC, CBB0, D06C, D5EC | MA-based |
| **42** | **`0x1402FEEE4`** | **366** | **MA** | **j_adjust_joblevel(100, faith)**, BDDC, CBB0, D06C, D5EC, CC0C | **Faith-based status (Nether Mantra)** |
| 43 | `0x1402FF054` | 82 | — | D8F0, DA94, CBB0, D06C, D13C | |
| 44 | `0x1402FF0A8` | 122 | — | D8F0, DA94, CBB0, D06C | |
| 45 | `0x1402FF124` | 5 | — | — | NOP |
| 46 | `0x1402FF198` | 299 | DIV100 | D8F0, D228, D0E0, C81C, DA94, CB18, CB6C, C1B8, CE88 | Calls faith_resultadjust |
| 47 | `0x1402FF2C4` | 70 | — | D8F0, DA94, CB18, CB6C, D01C | |
| 48 | `0x1402FF30C` | 5 | — | — | NOP |

### Extended Formulas (IDs 50-80)

| ID | Address | Size | Traits | Notes |
|----|---------|------|--------|-------|
| 50 | `0x1402FF3E0` | 159 | — | |
| 51 | `0x1402FF480` | 83 | — | |
| 52 | `0x1402FF4D4` | 95 | — | |
| 53 | `0x1402FF534` | 136 | — | |
| 54 | `0x1402FCC90` | 24 | — | |
| 55 | `0x1402FF5BC` | 5 | — | NOP |
| 56 | `0x1402FD5EC` | 5 | — | NOP (common tail call) |
| 57-58 | `0x1402FCCC0` / `0x1402FCCA8` | 24 | — | |
| 59 | `0x1402FCCD8` | 40 | — | |
| 60 | `0x1402FCD00` | 58 | — | |
| 61 | `0x1402FF684` | 32 | — | Calls f56 |
| 62 | `0x1402FF6A4` | 43 | HP | HP-based |
| 63 | `0x1402FF6D0` | 73 | — | Calls f56 |
| 64 | `0x1402FF71C` | 102 | MA | MA-based, calls f56 |
| 65 | `0x1402FF784` | 85 | MA | MA-based, calls f56 |
| 66 | `0x1402FF7DC` | 111 | — | |
| 67 | `0x1402FCD3C` | 31 | HP | HP-based |
| 68 | `0x1402FCD5C` | 27 | — | |
| 69 | `0x1402FCD78` | 31 | HP | `j_CheckWeatherThing` |
| 70 | — | — | — | UNUSED |
| 71 | `0x1402FF84C` | 67 | — | |
| 72 | `0x1402FF890` | 5 | — | NOP |
| 73 | `0x1402FD830` | 61 | — | j_ItemGetItemData |
| 75 | `0x1402FF8F8` | 113 | HP | j_ItemGetItemData |
| 76 | `0x1402FF96C` | 60 | — | |
| 77 | `0x1402FF9A8` | 113 | — | |
| 78 | `0x1402FFA1C` | 55 | — | |
| 79 | `0x1402FFA54` | 89 | HP | |
| 80 | `0x1402FFAB0` | 64 | — | Calls f56 |
| **100** | **`0x140304380`** | **31** | — | **`RESUME_SET_BCALC`** (Battle Calculator) |

---

## Shared Subroutines (Verified)

These `sub_1402F*` functions are called by multiple formulas. All thunks resolved to real addresses via decompilation.

### Damage Calculation Pipeline

| Thunk | Real Address | Size | Calls | Name | Behavior |
|-------|-------------|------|-------|------|----------|
| `0x1402FC6AC` | `0x14E5F260A` | 443b | 4× | **CalcWeaponDamage** | Reads PA(+43), branches on weapon type: bare fist=PA²/3, sword/katana=PA×WP, gun=WP², bow=PA×WP/2, etc. |
| `0x1402FBDDC` | `0x14E59734D` | 238b | 20× | **ZodiacCompatibility** | Reads zodiac sign from BWORK+8, looks up `byte_14067D480` compat table, scales damage 50-150% |
| `0x1402FCB6C` | `0x14E6B90D8` | 67b | 13× | **CalcFinalDamage** | `damage = PA × Y`, caps at 0x7FFF (32767). Sets attack flag 0x80. If formula=106, halves |
| `0x1402FCBB0` | `0x14E6BEF70` | 92b | 17× | **CalcTotalDamage** | Adds PA×WP + MA×Y components. Calls ZodiacCompat on Y component. Special-case for ability 65 (Golem) |
| `0x1402FD9D0` | (inline) | 194b | 16× | **LoadEvadeAndEquipModifiers** | Loads accessory(+30), shield(+34,+38) evasion. Sets base hit=100. Calls 3 evasion sub-functions |
| `0x1402FDC2C` | (inline) | 90b | 5× | **CalcMagicDamageChain** | Sets PA from +63, Y from secondary data. Chains: C914→C9FC→CAC8→BDDC→CBB0→CEBC→D06C |
| `0x1402FDD44` | (inline) | 58b | 5× | **CalcPhysicalDamageChain** | Chains: C87C→C96C→C9A4→CA54→BDDC→CBB0→D06C |

### Modifier Functions

| Thunk | Real Address | Size | Calls | Name | Behavior |
|-------|-------------|------|-------|------|----------|
| `0x1402FC84C` | `0x14E5FF60C` | 45b | 7× | **ApplyElementBoost** | Checks BWORK+122 (element absorb/boost) vs element, ×5/4 if matching |
| `0x1402FC87C` | `0x14E6071D3` | 162b | 5× | **ApplyPA_StatusMods** | Protect(÷3 at +153), Martial Arts(×3/2 at +154), Attack Up(×3/2 at +155) |
| `0x1402FC914` | (inline) | 86b | 12× | **ApplyCasterMagicBoost** | Checks CASTER +153 bit 2: ×4/3. Checks +155 bit 0: ×3/2. (Talcall: `magicAttackUp`) |
| `0x1402FC9FC` | (inline) | 85b | 6× | **ApplyTargetShell** | Checks TARGET +153 bit 1: ×2/3. Checks +155 bit 0: ×3/2 |
| `0x1402FCAC8` | (inline) | 79b | 6× | **ApplySleepChargeModifier** | Checks +100 bit 4 (Charging), +99 bits 1-2 (Sleeping/Performing): ×2/3 or ×3/2 |
| `0x1402FCEBC` | (inline) | 152b | 8× | **ApplyFaithMultiplier** | `damage × caster_faith × target_faith / 10000`. Reads faith from +101 |
| `0x1402FD06C` | `0x14E6FFD7B` | 115b | 16× | **ApplyFaithScaling** | `damage × faith / 100`, calls `j_adjust_joblevel`. Applied when damage < 100 |
| `0x1402FDA94` | `0x14E740076` | 205b | 11× | **ApplyPhysModifiers** | Dual-wield(×2), Berserk(×3/2 at +153), Attack Up(×3/2 at +155). Chains zodiac compat |

### Evasion & Hit Rate

| Thunk | Real Address | Size | Calls | Name | Behavior |
|-------|-------------|------|-------|------|----------|
| `0x1402FD8F0` | `0x14E72BC90` | 252b | 14× | **CalcPhysicalEvade** | Loads evasion from equipment, checks weapon type, applies difficulty scaling, calls evasion sub-functions |

### Status & Special

| Thunk | Real Address | Size | Calls | Name | Behavior |
|-------|-------------|------|-------|------|----------|
| `0x1402FCFDC` | `0x14E6DBBA7` | 63b | 7× | **UndeadReverse** | Checks undead status: flips damage to healing. Reflect is handled separately outside formulas |
| `0x1402FCB18` | `0x14E69BFE0` | 93b | 6× | **ApplyZodiacCharge** | RNG-based zodiac bonus. If compatible, adds bonus damage via `sub_1402FBA24` |
| `0x1402FD5A4` | `0x14E715847` | 70b | 5× | **SaveAndRestoreResultFlags** | Saves result state, calls f56 (status application), restores. Preserves result across status calc |
| `0x1402FD5EC` | (f56 thunk) | 5b | 8× | **resultcalculate_f56** | Status-only formula. NOP for damage, triggers status application pipeline |
| `0x1402FD228` | — | — | 3× | **DualHitSetup** | Dual-hit / secondary attack setup |
| `0x1402FC1B8` | — | — | 1× | **faith_resultadjust** | Confirmed via WotL symbol signature |
| `0x1402FCC0C` | — | — | 2× | **NetherMantraProc** | Nether Mantra / status proc check |
| `0x1402FB9C0` | — | — | 2× | **CalcBardDancerMA** | MA-based calculation core for Bard/Dancer |

---

## BWORK (Battle Work) Unit Structure

**Base array**: `0x14184D890` (21 slots × 512 bytes)  
**Current caster pointer**: `qword_141864090`  
**Current target pointer**: `qword_141864080`  
**Caster source pointer**: `qword_141864098`

| Offset | Size | Field | Source |
|--------|------|-------|--------|
| +0 | 1 | Unit ID / validity | setskillresult |
| +1 | 1 | Unit slot | setskillresult |
| +3 | 1 | Unit type byte | F88 caster validation |
| +5 | 1 | Flags (bits 4-5 = HP bar type, bit 2 = F88 gate) | setskillresult, F88 |
| +6 | 1 | Equipment flags (bit 5 = unarmed?) | sub_1402FD9D0 |
| +8 | 1 | Unknown — used in F88 caster range check | F88 |
| +30 | 2 | Weapon L slot (item ID) | sub_1402FD9D0 → ItemGetWeaponData |
| +34 | 2 | Weapon R slot (item ID) | sub_1402FD9D0 → ItemGetWeaponData |
| +38 | 2 | Accessory slot (item ID) | sub_1402FD9D0 → accessory evade |
| +40 | 1 | CT (Charge Time) | setskillresult |
| +41 | 1 | Level | setskillresult |
| +43 | 1 | **Faith** | setskillresult: `sub_140302CE0(result[24], unit+43, 100, ...)` |
| +45 | 1 | **Brave** | setskillresult: `sub_140302CE0(result[25], unit+45, 100, 0)` |
| +46 | 1 | SP (Speed) | formula trait analysis |
| +48 | 2 | **Current HP** | setskillresult |
| +50 | 2 | **Max HP** | setskillresult |
| +52 | 2 | Current MP | setskillresult |
| +54 | 2 | Max MP | setskillresult |
| +56 | 1 | **PA (Physical Attack)** | setskillresult: `sub_140302CE0(result[22], unit+56, 99, 1)` |
| +57 | 1 | **MA (Magic Attack)** | setskillresult: `sub_140302CE0(result[23], unit+57, 99, 1)` |
| +58 | 7 | Status effect block 1 | setskillresult: `sub_140302CE0(result[20], unit+58, 50, 1)` |
| +62 | 1 | **Current PA** (runtime, post-buff) | formulas read `caster[62]` as PA |
| +63 | 1 | **Current MA** (runtime, post-buff) | formulas read `caster[63]` / `source[63]` as MA |
| +64 | 1 | **Current SP** (runtime, post-buff) | formula trait analysis |
| +65 | 1+ | Status effect block 2 | setskillresult: `sub_140302CE0(result[21], unit+65, 255, 0)` |
| +79-81 | 3 | Job data (class, gender, etc.) | sub_140300610 |
| +87-96 | 10 | Status flags (active status bitfield) | setskillresult |
| +92-96 | 5 | Status immunity/absorption flags | F14 undead check at +92 |
| +97-101 | 5 | Status infliction flags | setskillresult (reaction trigger source) |
| +99 | 1 | Status byte: bit 6 = undead, bit 4 = transparent | element_check, undead_reverse |
| +102-117 | 16 | Status parameters | setskillresult |
| +122 | 1 | Element affinity flags | sub_1402FC81C — ×5/4 if `(unit[122] & element) != 0` |
| +148-150 | 3 | Reaction trigger flags | setskillresult |
| +151 | 1 | Support ability flags (block 2) | formula checks |
| +153 | 1 | Support ability flags (block 3) | formula checks |
| +154 | 1 | Support ability flags (block 4) | formula_42 |
| +396 | 1 | Evade counter | setskillresult: `++unit[396]` on death |
| +397 | 1 | Death sentence counter | setskillresult: set to -1 on death trigger |
| +398 | 1 | **Monster species ID** | F90-F93: 15/16 = Dragon |
| +416-418 | 3 | Secondary action data (for recursive formulas) | formula_37 |
| +424 | 2 | Steal item ID | setskillresult |
| +436 | 1 | Unit control flags (bit 7 = guest/charmed, bits 0-4 = redirect unit ID) | setskillresult, element_check |
| +443 | 1 | Action result type | setskillresult |
| +444 | 1 | Unit team/allegiance | setskillresult |
| +494 | 1 | HP bar display flags | setskillresult |
| +495-499 | 5 | Status clear block | setskillresult |
| +501 | 1 | Damage display type | setskillresult |

**Note on PA/MA offsets**: +56/+57 are the **base stat** locations written by `setskillresult` via `sub_140302CE0`. Offsets +62/+63 are **runtime current** values read by formula functions (post-buff/debuff). The engine maintains both.

---

## Target Result Structure (Current Action Data)

Written to `qword_141864080` (target result pointer).  
Talcall labels this `battle_current_action` / `target_CurrentAction`.

| Offset | Size | Field | Notes |
|--------|------|-------|-------|
| +0 | 1 | `hit` — Result valid / hit flag | 0 = miss, nonzero = hit |
| +2 | 1 | Result type | 7 = miss, 5 = absorb, 11 = immune |
| +6 | 2 | `hp_dmg` — HP damage value | Talcall: `hp_dmg` |
| +8 | 2 | HP heal value | |
| +10 | 2 | MP/secondary damage value | Used for drains, stat reduction |
| +12 | 2 | MP heal value | |
| +14 | 2 | Gil amount | |
| +16 | 2 | Ability ID (for display) | 450 = item pickup trigger |
| +18 | 2 | `attack_type` — Result/action flags | See attack_type table below |
| +20 | 1 | **Status modifier → unit+58** | `sub_140302CE0(result[20], unit+58, 50, 1)` — status block 1, cap 50 |
| +21 | 1 | **Status modifier → unit+65** | `sub_140302CE0(result[21], unit+65, 255, 0)` — status block 2, uncapped |
| +22 | 1 | **PA modifier → unit+56** | `sub_140302CE0(result[22], unit+56, 99, 1)` — cap 99. Bit 7 = increase |
| +23 | 1 | **MA modifier → unit+57** | `sub_140302CE0(result[23], unit+57, 99, 1)` — cap 99. Bit 7 = increase |
| +24 | 1 | **Faith modifier → unit+43** | `sub_140302CE0(result[24], unit+43, 100, ...)` — cap 100 |
| +25 | 1 | **Brave modifier → unit+45** | `sub_140302CE0(result[25], unit+45, 100, 0)` — cap 100 |
| +29-33 | 5 | **Inflict status bytes** (0x1D-0x21) | EpicBrownie verified |
| +34-38 | 5 | **Remove status bytes** (0x22-0x26) | EpicBrownie verified |
| +36 | 1 | Status removal sub-flags | setskillresult sets bits for Brave/Faith thresholds |
| +39 | 1 | **Damage flags** (0x27) | See table below |
| +40 | 2 | Item pickup ID | Only read when ability ID = 450 |
| +42 | 1 | CT/XP modifier | Bit 7: subtract CT. Bits 0-6: amount |
| +43 | 1 | JP gain flag | |
| +44 | 2 | CT modifier (secondary) | |

### Damage Flags (offset +39 / 0x27)

| Bit | Hex | Decimal | Flag | Formulas |
|-----|-----|---------|------|----------|
| 7 | 0x80 | 128 | **HP_Damage** | F08, F09, F13, F14, F23, F50, F62, F66-69, F77-79 |
| 6 | 0x40 | 64 | **HP_Healing** | F14(undead), F28(Bard), F60(Chant) |
| 5 | 0x20 | 32 | **MP_Damage** | F15, F22, F27, F33, F44 |
| 4 | 0x10 | 16 | **MP_Healing** | F28(Bard), F73 |
| 3 | 0x08 | 8 | **StatusChange** | F56 (status engine) |
| 0 | 0x01 | 1 | **StatChange** | F18(Quick), F20(Golem), F21, F40, F54-58 |

Composite values: `0x50` (80) = HP_Healing + MP_Healing (F52 Chakra).

These flags **must** be set when overriding a formula — the engine's `setskillresult` reads them to determine which result fields to process.

### Stat Modifier Engine (`sub_140302CE0` → `sub_14E847320`)

Result offsets +20 through +25 are processed by `sub_140302CE0(value, stat_ptr, cap, flags)`:

```
Encoding: bit 7 = direction (1 = increase, 0 = decrease)
          bits 0-6 = magnitude
Special:  if cap == 0xFF and magnitude == 0x7F → value becomes 0xFF (set to max)
```

The engine computes `new_stat = old_stat ± magnitude`, clamps to `[flags_min, cap]`, and writes back. If the stat didn't change, the function returns 0 (no visual update).

### Attack Type Flags (offset +18)

| Bit | Hex | Meaning | Source |
|-----|-----|---------|--------|
| 15 | 0x8000 | Negative (Golem barrier damage) | setskillresult |
| 14 | 0x4000 | Death trigger (check death sentence) | setskillresult |
| 9 | 0x0200 | Counter/reaction triggered | counter_check |
| 8 | 0x0100 | Level drain (decrease level) | F89 |
| 7 | 0x0080 | Level boost (increase level) | setskillresult |
| 3 | 0x0008 | Steal item (triggers inc_party_item) | setskillresult |
| 1 | 0x0002 | Full status clear (wipe all statuses) | setskillresult |
| 0 | 0x0001 | HP bar refresh | setskillresult |

### Verified Shared Subroutines

| Thunk | Target | Role | Evidence |
|-------|--------|------|----------|
| `sub_1402FC81C` | `sub_14E5FC0DD` | Element affinity boost: ×5/4 if `unit[122] & element` | Decompiled: checks source[122] against element byte |
| `sub_1402FCFDC` | `sub_14E6DBBA7` | Undead reverse: if `unit[97] & 0x10` (undead), set HP_Damage; else convert damage→heal | Decompiled: swaps result[6]↔result[8], toggles flags |
| `sub_1402FD5A4` | `sub_14E715847` | Save/restore result + apply status: saves hit/type/CT, calls f56, then restores | Decompiled: saves result[0],[2],[44], calls f56, restores |
| `sub_1402FD870` | `sub_14E721080` | Counter/reaction check: compares caster/target MA, sets attack_type bit 9 | Decompiled: reads source[63] vs caster[63] |
| `sub_1402FCD98` | `sub_14E6C6588` | Weather modifier: adjusts damage based on weather state (×3/4 or ×5/4) | Decompiled: checks global weather, modifies result[6] |
| `sub_1402FCE2C` | `sub_14E6CB198` | Element absorb/immunity check: if target absorbs element, set miss; then apply element modifiers | Decompiled: checks unit[99] bit 6, unit[436] redirect |
| `sub_1402FCE88` | `sub_14E6D4548` | Post-damage processing: if result type ≠ 5 (absorb), set HP_Damage or convert to HP_Healing | Decompiled: checks attack_type, swaps damage↔heal |
| `sub_1402FD9D0` | (194 bytes inline) | Evade/equipment loader: reads weapon/accessory evade from item data, checks transparent status | Decompiled: reads unit[30],[34],[38] item slots |
| `sub_1402FDCE8` | (90 bytes inline) | Magic hit chain: MA=source[63], X=ability_X → ElementBoost → MagicAttackUp → Shell → Sleep → Zodiac → CalcTotal → FaithScaling | Decompiled: calls FC84C→FC914→FC9FC→FCAC8→FBDDC→FCBB0→FD06C |

---

## Reaction System

| Function | Address | Size | Role |
|----------|---------|------|------|
| `_Battle_CheckReactions` | `0x140301864` | — | Entry point (called from setskillresult) |
| `_Battle_RollReactions` | `0x140302A20` | 87 | Iterates reaction abilities |
| `__Battle_RollForReaction` | `0x140302A78` | 78 | Individual roll: `j_adjust_joblevel(100, faith)` |
| `_Battle_RollForCriticalReaction` | — | — | Critical HP reaction variant |

Reaction ability IDs triggered from `setskillresult`:
- 422: HP < 0 reaction (Counter, First Strike)
- 423: HP damage > 0 (Parry, etc.)
- 424: HP damage (general)
- 428: Status inflicted
- 431-434: Critical HP reactions
- 439, 441: Special reactions

---

## Global Variables

### BattleActionContext (`0x14186407C`) — EpicBrownie verified

The core pointers used by formulas and `setskillresult` are fields of a single struct:

| Offset | Address | Size | Field | Notes |
|--------|---------|------|-------|-------|
| +0 | `0x14186407C` | 4 | **ActionState** | 0 = ability actually executing, nonzero = preview/AI. Guards all stat writes in `setskillresult` |
| +4 | `0x141864080` | 8 | **Defender result ptr** | Points to current target's result area (action data) |
| +12 | `0x141864088` | 8 | **Attacker result ptr** | Points to secondary result area (attacker's action data) |
| +20 | `0x141864090` | 8 | **Defender BWORK ptr** | Points to target unit's BWORK struct |
| +28 | `0x141864098` | 8 | **Attacker BWORK ptr** | Points to acting unit's BWORK struct |

**Pointer role swap**: During formula execution, `SetupSkillDataAndDispatch` sets `+20` to the **caster** and `+28` to the caster's **source** copy. During `setskillresult`, the pointers are reassigned per-target so `+20` = **defender** (unit being affected). Formula code reads caster stats from `+28` (`qword_141864098 + 63` = caster MA).

### Other Global Variables

| Address | Name | Purpose |
|---------|------|---------|
| `0x14184D890` | BWORK array | 21 unit battle work structs (512 bytes each) |
| `0x1407A9ED0` | Formula context | Byte 0 = caster ID, Byte 1 = target ID, Byte 15 = job/facing |
| `0x1407A9EE0` | Attack params | Word 0 = element, Word 4 = ability ID, Byte 12 = dual wield, Byte 13 = weapon element |
| `0x1407A9F00` | Ability secondary (runtime) | Runtime buffer loaded from GetAbilitySecondaryData, 20 bytes |
| `0x1407852F0` | **Ability secondary (base)** | **Static array in binary: 368 × 20 bytes. Source of all base formula/range/element data** |
| `0x140783630` | Ability secondary (work) | Runtime copy of base array, modified by NXD overrides at load time |
| `0x1407A9F18` | Weapon data | Loaded from ItemGetWeaponData, 8 bytes |
| `0x14067D128` | Formula dispatch table | 80 function pointers indexed by formula ID |
| `0x14067D480` | Zodiac compat table | Zodiac sign compatibility lookup (used by ZodiacCompatibility sub) |
| `0x140678FB0` | Formula type lookup | 128-byte table mapping ability type → formula category |
| `0x140809850` | Element/status table | 16 entries × 6 bytes |
| `0x140D3A36A` | Secondary data loaded flag | Byte flag: 0=not loaded, 1=loaded. Guards lazy init of ability secondary |

### Data Loading Architecture

```
j_GetAbilitySecondaryData (0x1402B6D2C → sub_14DF5E42A, 63 bytes)
  ├─ if ability_id > 0x16F (367): return nullptr
  ├─ if !byte_140D3A36A (first call):
  │    └─ j_LoadOverrideAbilityActionData (0x1402B6AF0 → sub_14DF57190, 612 bytes)
  │         ├─ memcpy(0x140783630, 0x1407852F0, 7360)  ← copy base data
  │         └─ foreach entry in NXD OverrideAbilityActionData:
  │              └─ if value != -1: overwrite corresponding byte in work array
  └─ return &0x140783630 + 20 * ability_id
```

---

## Decompiled Files

All formula functions are decompiled to C pseudocode in `reference/decompiled_formulas/`:

```
formula_01.c through formula_80.c    — Individual formula calculations
pre_formula_target_setup.c           — Target initialization
post_dispatch_modifiers.c            — Physical damage modifiers
post_formula_finalize.c              — Final result processing
```

Additional battle pipeline decompilations in `reference/`:
```
decompiled_setskillresult.c          — Result application (HP/MP/status/reactions)
decompiled_sub_140300610_large_uses_100.c  — SetupSkillDataAndDispatch
decompiled_BattleRoutine_child_B078.c      — AI unit evaluation
decompiled_EquipCheck_CanUnitEquipItem.c   — Equipment restriction logic
decompiled_CheckUnitActionEffective.c      — Action hit/miss determination
decompiled__Battle_RollReactions.c         — Reaction trigger system
decompiled___Battle_RollForReaction.c      — Individual reaction probability
```

---

## Hooking Guide

### To override a specific formula:
1. Find the formula ID your ability uses (from `AbilitySecondaryData[8]`)
2. Look up the function address in the dispatch table above
3. Hook that address with your replacement function
4. Your function receives no arguments — read from `BattleActionContext` (`0x14186407C`): `+20` (caster BWORK, but labeled defender in struct), `+28` (source BWORK), `+4` (target result)
5. Write damage to `target_result[+6]` (HP dmg) or `target_result[+8]` (HP heal)

### To modify faith-based reactions:
Hook `__Battle_RollForReaction` at `0x140302A78`. The faith check is `j_adjust_joblevel(100, unit_faith)`. Replace with constant `1` to always proc, or `0` to never proc.

### To remove weapon restrictions:
Hook the relevant formula function. For example, formula 42 (Nether Mantra) checks `v0[151] & 0x20` and `v0[6] & 0x20` for specific status flags.

---

*This document is generated from static binary analysis. Addresses are for the current Steam release. Future patches may shift addresses; use signature scanning for stability.*
