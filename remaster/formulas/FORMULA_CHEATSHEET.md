# FFT: IC Formula Cheat Sheet

> Companion to [FORMULA_REFERENCE.md](FORMULA_REFERENCE.md) — simplified math for every formula.
> All formulas verified against decompiled `resultcalculate_fXX` functions.
> Decompiled C pseudocode shown below each formula for verification.


## Reading This Guide

- **PA** = Physical Attack (caster +42), **MA** = Magic Attack (caster +63)
- **WP** = Weapon Power (from equipped weapon data)
- **X, Y** = Per-ability parameters (ability secondary data offset +9, +10)
- **Faith** = Unit faith stat (+101, range 0–100), **Brave** = Unit brave (+45)
- **Zodiac** = Zodiac compatibility modifier (50–150%)
- **MaxHP/CurHP** = Target's maximum/current HP (+50/+48)
- Modifiers in `[brackets]` are conditional

---

## Magic Formulas

### F08 — Black Magick / Summon Damage
```
Damage = MA × Y × [×5/4 element-boost equip]
 × [×4/3 caster magic boost] × [×2/3 target Shell]
 × [×3/2 target Sleep/Charging]
 × Zodiac(50-150%) × Faith(caster×target/10000)
capped at 32767
```
> Fire/Blizzard/Thunder, Holy, Flare, Meteor, Summons, Ultima, Bio
<details><summary>Decompiled (resultcalculate_f08)</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result) {
 MA = caster[63];
 Y = ability_secondary[14]; // Y param
 ApplyElementBoost(); // sub_1402FC84C — ×5/4 if element match
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3 if caster[153] bit 4
 ApplyTargetShell(); // sub_1402FC9FC — ×2/3 if target[153] bit 2
 ApplySleepChargeModifier(); // sub_1402FCAC8 — ×3/2 if sleeping/charging
 ZodiacCompatibility(); // sub_1402FBDDC — 50-150%
 CalcFinalDamage(); // sub_1402FCB6C — PA × Y, cap 32767
 // ...then if target alive:
 ApplyFaithMultiplier(); // sub_1402FCEBC — ×caster_faith×target_faith/10000
 // ...status
}
```
</details>

### F09 — Gravity
```
Damage = (Y × target_MaxHP + 99) / 100
Hit check: (MA + X) × [×4/3 MagicAttackUp] × [×2/3 Shell] × [×3/2 Sleep]
 × Zodiac(50-150%) × Faith(caster×target/10000)
 must pass for damage to apply
```
> Gravity (Y=25), Graviga (Y=50), Lich (Y=50)
<details><summary>Decompiled (resultcalculate_f09)</summary>

```c
result = LoadEvadeAndEquipModifiers();
if (!result) {
 // CalcMagicDamageChain (sub_1402FDC88) expands to:
 MA = caster[63]; X = ability_secondary[13];
 ApplyElementBoost(); // sub_1402FC84C — ×5/4
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
 ApplyTargetShell(); // sub_1402FC9FC — ×2/3
 ApplySleepChargeModifier(); // sub_1402FCAC8 — ×3/2
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcTotalDamage(); // sub_1402FCBB0 — MA + X (ADDITIVE)
 ApplyFaithMultiplier(); // sub_1402FCEBC
 ApplyFaithScaling(); // sub_1402FD06C
 if (!result) {
 damage = (ability_secondary[14] * target[50] + 99) / 100; // Y% of MaxHP
 target_result[39] |= 0x80; // flags: HP_Damage
 target_result[6] = damage;
 }
}
```
</details>

### F10 — Faith-Based Status
```
Hit% = (MA + X) × [×5/4 element] × [×4/3 MagicAttackUp] × [×2/3 Shell]
 × [×3/2 Sleep/Charge] × Zodiac(50-150%)
 × Faith(caster×target/10000)
 → inflicts status on success (no damage)
```
> Poison, Toad, Slow, Stop, Blind, Sleep, Break, Dispel, Silence
<details><summary>Decompiled (resultcalculate_f10)</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result) {
 // CalcMagicDamageChain (sub_1402FDC88) expands to:
 MA = caster[63]; X = ability_secondary[13];
 ApplyElementBoost(); // sub_1402FC84C — ×5/4
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
 ApplyTargetShell(); // sub_1402FC9FC — ×2/3
 ApplySleepChargeModifier(); // sub_1402FCAC8 — ×3/2
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcTotalDamage(); // sub_1402FCBB0 — MA + X (ADDITIVE)
 ApplyFaithMultiplier(); // sub_1402FCEBC
 ApplyFaithScaling(); // sub_1402FD06C
 if (!result)
 resultcalculate_f56(); // status-only application
}
```
</details>

### F11 — Faith-Based Buff
```
Power = (MA_modified + X_with_zodiac)
 where MA_modified = MA × [×5/4 element] × [×4/3 MagicAttackUp] × Zodiac
 then: Power × Faith(caster×target/10000)
 → applies buff status on success
```
> Reraise, Regen, Protect, Shell, Haste, Float, Reflect, Carbuncle, Dispelna, Aegis
<details><summary>Decompiled (resultcalculate_f11)</summary>

```c
MA = caster[63];
Y = ability_secondary[13]; // X param (note: offset 13, not 14)
ApplyElementBoost(); // sub_1402FC84C
ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
ZodiacCompatibility(); // sub_1402FBDDC
CalcTotalDamage(); // sub_1402FCBB0
ApplyFaithMultiplier(); // sub_1402FCEBC
ApplyFaithScaling(); // sub_1402FD06C
if (target_result[0])
 resultcalculate_f56(); // apply status
```
</details>

### F12 — Magical Healing
```
Heal = MA × Y × [×5/4 element] × [×4/3 MagicAttackUp]
 × Zodiac(50-150%) × Faith(caster×target/10000)
capped at 32767, then Undead reverse check
```
> Cure (Y=14), Cura (Y=20), Curaga (Y=30), Curaja (Y=40), Moogle (Y=10), Faerie (Y=20)
<details><summary>Decompiled (resultcalculate_f12)</summary>

```c
MA = caster[63];
Y = ability_secondary[14]; // Y param
ApplyElementBoost(); // sub_1402FC84C
ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
ZodiacCompatibility(); // sub_1402FBDDC
CalcFinalDamage(); // sub_1402FCB6C — MA × Y
ApplyFaithMultiplier(); // sub_1402FCEBC
UndeadReverse(); // sub_1402FCFDC
```
</details>

### F13 — Raise / Revive
```
Step 1: Hit = (MA_modified + X_with_zodiac)
 where MA = MA × [×5/4 element] × [×4/3 MagicAttackUp] × Zodiac
 then × Faith(caster×target/10000)
Step 2: if target dead → Heal = (Y × MaxHP + 99) / 100
```
> Raise (Y=50), Arise (Y=100)
<details><summary>Decompiled (resultcalculate_f13)</summary>

```c
MA = caster[63]; Y = ability_secondary[13];
ApplyElementBoost(); ApplyCasterMagicBoost();
ZodiacCompatibility(); CalcTotalDamage();
ApplyFaithMultiplier(); ApplyFaithScaling();
if (target_result[0]) {
 if (sub_140300164()) { // check if target dead
 damage = (Y * target_MaxHP + 99) / 100;
 target_result[39] |= 0x80;
 target_result[6] = damage;
 UndeadReverse();
 }
}
```
</details>

### F14 — Death / Instant Kill
```
Hit = (MA_modified + X_with_zodiac)
 where MA = MA × [×5/4 element] × [×4/3 MagicAttackUp]
 + [×2/3 Shell] × [×3/2 Sleep] (if not Undead bypass)
 × Zodiac × Faith(caster×target/10000)
On hit: Damage = (Y × MaxHP + 99) / 100
Undead → heals instead | Immune → miss | Reflect → bounced
```
> Death (Y=100)
<details><summary>Decompiled (resultcalculate_f14) — 262 bytes, complex</summary>

```c
if (target[97] & 0x10) bypass_evade = true; // Undead bypass
else { result = LoadEvadeAndEquipModifiers(); }
MA = caster[63]; Y = ability_secondary[13];
ApplyElementBoost(); ApplyCasterMagicBoost();
if (!bypass_evade) { ApplyTargetShell(); ApplySleepChargeModifier(); }
ZodiacCompatibility(); CalcTotalDamage();
ApplyFaithMultiplier(); ApplyFaithScaling();
if (target_result[0] && sub_140300164()) {
 damage = (Y * target_MaxHP + 99) / 100;
 if (target[97] & 0x10) // Undead → heal
 { result[39] = 64; result[8] = damage; result[6] = 0; }
 else if (target[92] & 0x20) // immune
 { result[0] = 0; }
 else
 { result[39] = 0x80; } // flags: HP_Damage
}
```
</details>

---

## Drain Formulas

### F15 — HP Drain (Magical)
```
Hit check: (MA + X) × [×4/3 MagicAttackUp] × [×2/3 Shell] × [×3/2 Sleep]
 × Zodiac(50-150%) × Faith(caster×target/10000)
 (no element boost)
Drain = (Y × target_MaxMP + 99) / 100
Caster heals HP equal to drain amount
```
> Empowerment (Y=33), Syphon (Y=25)
<details><summary>Decompiled (resultcalculate_f15)</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result) {
 // CalcMagicDamageChain2 (sub_1402FDC2C, no element boost) expands to:
 MA = caster[63]; X = ability_secondary[13];
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
 ApplyTargetShell(); // sub_1402FC9FC — ×2/3
 ApplySleepChargeModifier(); // sub_1402FCAC8 — ×3/2
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcTotalDamage(); // sub_1402FCBB0 — MA + X (ADDITIVE)
 ApplyFaithMultiplier(); // sub_1402FCEBC
 ApplyFaithScaling(); // sub_1402FD06C
 damage = (Y * target[54] + 99) / 100; // Y% of target stat at +54
 result[10] = damage; // drain amount
 result[6] = damage;
 result[39] = 32; // flags: MP_Damage/Drain
 sub_1402FD01C();
 }
}
```
</details>

### F16 — MP Drain (Magical)
```
Hit check: (MA + X) × [×4/3 MagicAttackUp] × [×2/3 Shell] × [×3/2 Sleep]
 × Zodiac(50-150%) × Faith(caster×target/10000)
 (no element boost)
Damage = (Y × target_MaxHP + 99) / 100
Caster recovers MP equal to damage dealt
```
> Invigoration (Y=25), Drain (Y=25)
<details><summary>Decompiled (resultcalculate_f16)</summary>

```c
result = LoadEvadeAndEquipModifiers();
if (!result) {
 // MagicChain2 (sub_1402FDC2C, no element boost):
 // MA=caster[63], X=ability_X → CasterBoost(×4/3) → Shell(×2/3)
 // → Sleep(×3/2) → Zodiac → CalcTotal(MA+X) → Faith² → FaithScaling
 result = CalcMagicDamageChain2(); // sub_1402FDC2C
 if (!result) {
 damage = (Y * target[50] + 99) / 100; // Y% of MaxHP
 result[39] |= 0x80; // flags: HP_Damage
 result[6] = damage;
 sub_1402FCF54(); // MP drain to caster
 }
}
```
</details>

---

## Special Magic

### F18 — Quick
```
Power = (MA + X) × [×4/3 MagicAttackUp]
 × Zodiac(50-150%) × Faith(caster×target/10000)
 (no element boost, no Shell, no Sleep)
On success: target gains an extra turn immediately
```
> Quick
<details><summary>Decompiled (resultcalculate_f18)</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
 MA = caster[63];
 X = ability_secondary[13];
 ApplyCasterMagicBoost();                        // sub_1402FC914 — ×4/3
 ZodiacCompatibility();                          // sub_1402FBDDC
 CalcTotalDamage();                              // sub_1402FCBB0 — MA + X
 ApplyFaithMultiplier();                         // sub_1402FCEBC
 ApplyFaithScaling();                            // sub_1402FD06C
 if (target_result[0]) {
  target_result[21] = 0xFF;                      // all status flags
  target_result[39] = 1;                         // flags: StatChange
 }
}
```
</details>

### F20 — Golem Shield
```
Power = (MA + X) × [×4/3 MagicAttackUp]
 then Faith scaling (based on caster status)
On success: creates barrier, sets attack_type = 1
```
> Golem (Y=200)
<details><summary>Decompiled (resultcalculate_f20) — 175 bytes</summary>

```c
MA = caster[63];
X = ability_secondary[13];
ApplyCasterMagicBoost();                     // sub_1402FC914 — ×4/3
CalcTotalDamage();                           // sub_1402FCBB0 — MA + X
// Faith scaling: if caster status_5 bit 7 set, force 100
// if caster status_5 bit 6 set, force 0
ApplyFaithScaling();                         // sub_1402FD06C
if (target_result[0]) {
 target_result[39] = 1;                      // flags: StatChange
 target_result[18] = 1;                      // attack_type
}
```
</details>

### F21 — Return
```
Hit check: (MA + X) × [×4/3 MagicAttackUp] × [×2/3 Shell]
 × [×3/2 Sleep] × Zodiac(50-150%) × Faith(caster×target/10000)
 (no element boost)
On success: apply status effect (CT reset)
```
> Return
<details><summary>Decompiled (resultcalculate_f21)</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
 // MagicChain2 (sub_1402FDC2C, no element boost):
 // CasterBoost(×4/3) → Shell(×2/3) → Sleep(×3/2) → Zodiac
 // → CalcTotal(MA+X) → Faith² → FaithScaling
 result = sub_1402FDC2C();
 if (!result) {
  target_result[21] = 127;                      // flags: StatusChanges
  target_result[39] = 1;
 }
}
```
</details>

### F22 — Disempower
```
Hit check: (MA + X) × [×4/3 MagicAttackUp] × [×2/3 Shell]
 × [×3/2 Sleep] × Zodiac(50-150%) × Faith(caster×target/10000)
 (no element boost)
On success: target loses stat points
```
> Disempower
<details><summary>Decompiled (resultcalculate_f22)</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
 // MagicChain2 (sub_1402FDC2C, no element boost):
 // CasterBoost(×4/3) → Shell(×2/3) → Sleep(×3/2) → Zodiac
 // → CalcTotal(MA+X) → Faith² → FaithScaling
 result = sub_1402FDC2C();
 if (!result) {
  target_result[10] = target[52];               // current stat value
  target_result[39] = 32;                       // flags: MP_Damage/Drain
 }
}
```
</details>

### F23 — Gravija
```
Hit check: (MA + X) × [×4/3 MagicAttackUp] × [×2/3 Shell]
 × [×3/2 Sleep] × Zodiac(50-150%) × Faith(caster×target/10000)
 (no element boost)
Damage = (Y × target_CurHP + 99) / 100
```
> Gravija
<details><summary>Decompiled (resultcalculate_f23)</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
 // MagicChain2 (sub_1402FDC2C, no element boost):
 // CasterBoost(×4/3) → Shell(×2/3) → Sleep(×3/2) → Zodiac
 // → CalcTotal(MA+X) → Faith² → FaithScaling
 result = sub_1402FDC2C();
 if (!result) {
  hp = target[48];                              // current HP
  if (hp)
   target_result[6] = hp - 1;                   // damage = CurHP - 1
  target_result[39] = 0x80;                     // flags: HP_Damage
 }
}
```
</details>

---

## Physical Formulas

### F01 — Normal Attack
```
1. CalcWeaponDamage sets PA based on weapon type (fists/swords/guns etc)
2. PA += WP (weapon power added to PA)
3. Damage = PA × Y × [×2 dual wield] × [×3/2 Berserk] × [×3/2 AttackUp]
 × [×2/3 target Protect] × [×3/2 target Sleep/Charging]
 × Zodiac(50-150%) × [element absorb/weak/half]
capped at 32767, then counter check
```
> Attack, Choco Beak, Tackle, Bite, Claw, all monster basic attacks (16 total)
<details><summary>Decompiled (resultcalculate_f01, thunk resolved)</summary>

```c
// Thunk: 0x1402FDD80 → 0x14E7675C0 → sub_1402FDB50 → 0x14E756D80
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 CalcWeaponDamage(); // sub_1402FC6AC — weapon-type PA/Y setup
 PA += WP; // byte_1407A9F1C added to PA
 sub_1402FC81C(); // unknown setup
 ApplyPhysModifiers(); // sub_1402FDA94 — ×2 dual wield, ×3/2 Berserk/AttackUp
 // then ×2/3 Protect, ×3/2 Sleep, Zodiac
 ApplyZodiacCharge(); // sub_1402FCB18 — critical hit chance
 CalcFinalDamage(); // sub_1402FCB6C — PA × Y, cap 32767
 ApplyElementCheck(); // sub_1402FC1B8 — absorb/weak/half
 if (target_result[0]) {
 PostDamage(); // sub_1402FCE88
 CounterCheck(); // sub_1402FD870
 }
}
```
</details>

### F26 — Stat Sap
```
Damage = MA × Y × [×5/4 element] × [×4/3 caster magic boost]
 × [×2/3 target Shell] × [×3/2 target Sleep/Charging]
 × Zodiac(50-150%) × Faith(caster×target/10000)
capped at 32767, then saps target stat + status applied
```
> Speedsap (X=3), Powersap (X=5), Mindsap (X=5)
<details><summary>Decompiled (resultcalculate_f26)</summary>

```c
result = LoadEvadeAndEquipModifiers();
if (!result) {
 MA = caster[63]; Y = ability_secondary[14];
 ApplyElementBoost(); // sub_1402FC84C — ×5/4
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
 ApplyTargetShell(); // sub_1402FC9FC — ×2/3
 ApplySleepChargeModifier(); // sub_1402FCAC8 — ×3/2
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcFinalDamage(); // sub_1402FCB6C — MA × Y, cap 32767
 // if target alive:
 ApplyFaithMultiplier();
 // ... stat sap amount stored, then status applied
}
```
</details>

### F27 — Magicksap
```
Hit check: (MA + X) × [×5/4 element] × [×4/3 MagicAttackUp] × [×2/3 Shell]
 × [×3/2 Sleep] × Zodiac(50-150%) × Faith(caster×target/10000)
On success: drains MP from target to caster
```
> Magicksap (X=250, Y=50)
<details><summary>Decompiled (resultcalculate_f27)</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
 // MagicChain (sub_1402FDC88, WITH element boost):
 // ElementBoost(×5/4) → CasterBoost(×4/3) → Shell(×2/3)
 // → Sleep(×3/2) → Zodiac → CalcTotal(MA+X) → Faith² → FaithScaling
 result = sub_1402FDC88();
 if (!result) {
  drain = (Y * target[54] + 99) / 100;          // Y% of target MP
  target_result[39] = 32;                        // flags: MP_Damage/Drain
 }
}
```
</details>


---

## Bard / Dancer

### F28 — Bard Songs
```
Power = (MA + X) × Zodiac(50-150%)
then per-ability branch:
 117: all buffs | 118/119: Brave ±Y | 120/121: Faith ±Y
 123: Nether Mantra (drain Speed×MA×(Y+1) from target)
 else: status via f56
Faith scaling applied to hit chance
```
> Seraph Song, Life's Anthem, Rousing Melody, Battle Chant, Magickal Refrain, Nameless Song, Finale
<details><summary>Decompiled (resultcalculate_f28) — 212 bytes</summary>

```c
// Checks if caster can perform (status checks)
sub_140301BE8(); // validate performer
if (target[151] & 0x20) {
 target_result[44] = 100 - caster[43]; // PA-based effect
 // Faith roll: j_adjust_joblevel(100, caster[43])
}
// Per ability ID switch:
// 117: result[21] = 127 (all buffs)
// 118: result[24] = Y | 0x80
// 119: result[24] = Y & 0x7F
// 120: result[25] = Y | 0x80
// 121: result[25] = Y & 0x7F
// 123: sub_1402FCC0C() (Nether Mantra proc)
// else: resultcalculate_f56()
MA = caster[63]; Y = ability_secondary[13];
ZodiacCompatibility(); CalcTotalDamage(); ApplyFaithScaling();
```
</details>

### F29 — Dancer Dances
```
Power = (MA + X) × Zodiac(50-150%)
Same per-ability branch structure as F28 but targets enemies
Applies debuffs/damage instead of buffs
```
> Witch Hunt, Mincing Minuet, Slow Dance, Polka, Heathen Frolic, Forbidden Dance, Last Waltz
<details><summary>Decompiled (resultcalculate_f29) — 203 bytes, similar structure to F28</summary>

```c
// Same pattern as F28 but targets enemies
// Per-ability switch on WORD4(xmmword_1407A9EE0) for different effects
// Calls CalcBardDancerMA (sub_1402FB9C0) for base calculation
```
</details>

---

## Iaido / Draw Out

### F30 — Iaido Heaven
```
PA = MA, Y = (MA + ability_Y) / 2
Damage = PA × Y × [×5/4 element] × [×4/3 caster boost]
 × [×2/3 Shell] × [×3/2 Sleep] × Zodiac(50-150%)
 × [weather] × [element absorb/weak]
capped at 32767, then counter + status check
```
> Heaven's Wrath → Divinity, Holy Breath
<details><summary>Decompiled (resultcalculate_f30) — 23 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result)
 // sub_1402FDBFC: MA=caster[63], Y=(MA+ability_Y)/2, then full physical chain:
 // ElementBoost(×5/4) → CasterBoost(×4/3) → Shell(×2/3) → Sleep(×3/2)
 // → Zodiac → CalcFinalDamage(PA×Y) → Weather → ElementCheck → PostDamage → Counter
 sub_1402FDBFC();
```
</details>

### F31 — Iaido Nether
```
Damage = MA × Y × [×4/3 caster boost] × [×2/3 Shell]
 × [×3/2 Sleep] × Zodiac(50-150%)
 × Faith(caster×target/10000)
capped at 32767, then status applied (no element boost)
```
> Hell's Wrath → Impiety
<details><summary>Decompiled (resultcalculate_f31) — 294 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers();
if (!result) {
 MA = caster[63]; Y = ability_secondary[14];
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
 ApplyTargetShell(); // sub_1402FC9FC — ×2/3
 ApplySleepChargeModifier(); // sub_1402FCAC8
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcFinalDamage(); // sub_1402FCB6C
 // ... then FaithMultiplier + status
 ApplyFaithMultiplier(); // sub_1402FCEBC
 SaveAndRestoreResultFlags(); // sub_1402FD5A4
}
```
</details>

### F32 — Draw Out (Damage)
```
Damage = MA × Y × physical modifier chain
 × [×5/4 element] × [×4/3 MagicAttackUp] × [×2/3 Shell]
 × [×3/2 Sleep] × Zodiac × [weather] × [element absorb/weak]
```
> Ashura, Kotetsu, Muramasa, Chirijiraden
<details><summary>Decompiled (resultcalculate_f32) — 50 bytes</summary>

```c
sub_1402FD1C0();                                 // inventory check
MA = caster[63]; Y = ability_secondary[14];
// sub_1402FDBAC: full multiplicative physical chain:
// ElementBoost(×5/4) → CasterBoost(×4/3) → Shell(×2/3) → Sleep(×3/2)
// → Zodiac → CalcFinalDamage(MA×Y) → Weather → ElementCheck → PostDamage → Counter
sub_1402FDBAC();
```
</details>

### F33 — Draw Out (Damage + Status)
```
Damage = MA × Y × [×4/3 MagicAttackUp] × [×2/3 Shell]
 × [×3/2 Sleep] × Zodiac(50-150%)
capped at 32767, then status applied (no faith scaling)
```
> Bizen Osafune
<details><summary>Decompiled (resultcalculate_f33) — 98 bytes</summary>

```c
sub_1402FD1C0();                                 // inventory check
MA = caster[63]; Y = ability_secondary[14];
ApplyCasterMagicBoost();                         // sub_1402FC914 — ×4/3
ApplyTargetShell();                              // sub_1402FC9FC — ×2/3
ApplySleepChargeModifier();                      // sub_1402FCAC8 — ×3/2
ZodiacCompatibility();                           // sub_1402FBDDC
target_result[10] = MA * Y;                      // damage = MA × Y
target_result[39] = 32;                          // flags: HP_Damage
```
</details>

### F34 — Draw Out (Buff)
```
Status-only: applies buff from ability data (no damage)
Uses f56 status engine for Protect, Shell, Regen, Haste etc
```
> Kiyomori (→Protect+Shell), Masamune (→Regen+Haste)
<details><summary>Decompiled (resultcalculate_f34) — 18 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers();
if (!result)
 resultcalculate_f56(); // apply buff status
```
</details>

### F35 — Draw Out (Heal)
```
Heal = MA × Y × Zodiac(50-150%)
capped at 32767, then Undead reverse check
(no faith scaling, no element boost)
```
> Murasame
<details><summary>Decompiled (resultcalculate_f35) — 55 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers();
if (!result) {
 MA = caster[63]; Y = ability_secondary[14];
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcFinalDamage(); // sub_1402FCB6C
 UndeadReverse(); // sub_1402FCFDC
}
```
</details>

---

## Geomancy / Equipment Skills

### F36 — Geomancy
```
PA = MA, Y = ability_Y
1. CalcWeaponDamage sets base values by weapon type
2. Damage = PA × Y × [×2 dual wield] × [×3/2 Berserk/AttackUp]
 × [×2/3 target Protect] × [×3/2 target Sleep]
 × Zodiac(50-150%) × [critical chance]
capped at 32767 (terrain-dependent element)
```
> All 12 Geomancy skills (Sinkhole → Magma Surge)
<details><summary>Decompiled (resultcalculate_f36) — 63 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers();
if (!result) {
 MA = caster[63]; Y = ability_secondary[14];
 CalcWeaponDamage(); // sub_1402FC6AC
 ApplyPhysModifiers(); // sub_1402FDA94
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcFinalDamage(); // sub_1402FCB6C
}
```
</details>

### F37 — Rend Equipment
```
Physical evade check, then:
 DualHitSetup selects which equipment slot to target
 Damage = PA × weapon_data × [phys modifiers]
 On success: destroys target's equipment in that slot
 May dispatch a second hit for dual wield
```
> Rend Helm/Armor/Shield/Weapon
<details><summary>Decompiled (resultcalculate_f37) — 342 bytes, complex</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 if (DualHitSetup()) { // sub_1402FD228
 PA = caster[62]; Y = weapon_data;
 // ... physical damage with dual-hit
 }
 // Equipment destruction logic
 // Calls SetupSkillDataAndDispatch for second hit
}
```
</details>

### F38 — Steal Equipment
```
Physical evade check, then:
 Checks target's equipment slots for stealable items
 Success rate based on Speed differential
 On success: moves item from target to caster inventory
```
> Steal Helm/Armor/Shield/Weapon/Accessory
<details><summary>Decompiled (resultcalculate_f38) — 204 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 // Complex steal logic checking equipment slots
 // Success rate modified by PA and Speed
 // Moves item from target to caster inventory
}
```
</details>

### F39 — Steal Gil
```
Physical evade check, then:
 Steals gil from target on success
```
> Steal Gil, Glitterlust
<details><summary>Decompiled (resultcalculate_f39) — 94 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 // Gil steal calculation
 result[39] = 1; // flags: StatChange
}
```
</details>

### F40 — Steal EXP
```
Physical evade check, then:
 Complex EXP/level transfer between caster and target
```
> Steal EXP
<details><summary>Decompiled (resultcalculate_f40) — 270 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 // Complex 270-byte function
 // Reads target level/EXP, modifies both units
 // Multiple conditional branches
}
```
</details>

### F41 — Steal Heart / Charm
```
Hit = (MA + X) × [×2 dual wield] × [×3/2 Berserk/AttackUp]
 × [×2/3 target Protect] × [×3/2 target Sleep]
 × Zodiac(50-150%) × faith_scaling
On success: inflicts Charm status
```
> Steal Heart, Charm, Snort
<details><summary>Decompiled (resultcalculate_f41) — 121 bytes</summary>

```c
MA = caster[63]; X = ability_secondary[13];
ApplyPhysModifiers(); // sub_1402FDA94
CalcTotalDamage(); // sub_1402FCBB0
ApplyFaithScaling(); // sub_1402FD06C
if (target_result[0])
 resultcalculate_f56(); // apply charm status
```
</details>

---

## Orator / Speechcraft

### F42 — Speechcraft
```
Hit = (MA + X) × Zodiac(50-150%) × faith_scaling
then per-ability branch:
 118/119: Brave ±Y | 120/121: Faith ±Y
 123: Nether Mantra (Speed drain)
 else: status via f56
```
> Entice, Stall, Praise, Intimidate, Preach, Enlighten, Condemn, Insult, Mimic Darlavon
<details><summary>Decompiled (resultcalculate_f42) — 366 bytes, complex switch</summary>

```c
// Validates performer status
sub_140301BE8();
if (target[151] & 0x20) {
 result[44] = 100 - caster[43];
 // j_adjust_joblevel faith roll
}
// Then per ability ID:
MA = caster[63]; Y = ability_secondary[13];
ZodiacCompatibility(); CalcTotalDamage(); ApplyFaithScaling();
// Switch on WORD4(xmmword_1407A9EE0):
// 117: result[21] = 127 (all buffs)
// 118/119: modify result[24] (Brave adjust)
// 120/121: modify result[25] (Faith adjust)
// 123: NetherMantraProc (sub_1402FCC0C)
// else: resultcalculate_f56()
```
</details>

### F43 — Rend Stats
```
Damage = MA × Y × [×4/3 caster boost] × Zodiac(50-150%)
capped at 32767, then status applied (stat reduction)
```
> Rend Speed (X=2), Rend Power (X=3), Rend Magick (X=3)
<details><summary>Decompiled (resultcalculate_f43) — 82 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 MA = caster[63]; Y = ability_secondary[14];
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcFinalDamage(); // sub_1402FCB6C
 SaveAndRestoreResultFlags(); // sub_1402FD5A4
}
```
</details>

### F44 — Rend MP
```
Hit = (MA + Y) × [×4/3 caster boost] × Zodiac(50-150%)
 × faith_scaling
On success: status applied (MP reduction)
(additive, not multiplicative)
```
> Rend MP
<details><summary>Decompiled (resultcalculate_f44) — 122 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 MA = caster[63]; Y = ability_secondary[14];
 ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
 ZodiacCompatibility(); // sub_1402FBDDC
 CalcTotalDamage(); // sub_1402FCBB0
 ApplyFaithScaling(); // sub_1402FD06C
 if (target_result[0])
 resultcalculate_f56();
}
```
</details>

---

## Knight Swords

### F45 — Holy Sword
```
Damage = PA × (WP + Y) × [×2 dual wield] × [×3/2 Berserk/AttackUp]
 × [×2/3 target Protect] × [×3/2 target Sleep]
 × Zodiac(50-150%) × [critical] × [element absorb/weak/half]
capped at 32767, then status applied
```
> Judgment Blade, Cleansing Strike, Northswain's Strike, Hallowed Bolt, Divine Ruination
<details><summary>Decompiled (resultcalculate_f45, thunk resolved) — 113 bytes</summary>

```c
// Thunk: 0x1402FF124 → 0x14E76A74E
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 PA = caster[62]; // PA stat (not MA!)
 Y = byte_1407A9F1C + ability_secondary[14]; // WP + Y param
 sub_1402FC81C(); // unknown setup
 ApplyPhysModifiers(); // sub_1402FDA94
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcFinalDamage(); // sub_1402FCB6C
 faith_resultadjust(); // sub_1402FC1B8
 if (target_result[0]) {
 sub_1402FCE88(); // post-damage
 SaveAndRestoreResultFlags(); // sub_1402FD5A4
 }
}
```
</details>

### F46 — Dark Sword (Crush)
```
Damage = PA × WP × [phys modifiers] × Zodiac × [critical]
 × [element absorb/weak/half]
Dual wield: PA halved for off-hand hit
On success: destroys target equipment + deals damage
```
> Crush Armor, Crush Helm, Crush Weapon, Crush Accessory
<details><summary>Decompiled (resultcalculate_f46) — 299 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (result) { /* evade handling */ return; }
if (DualHitSetup()) { // sub_1402FD228
 PA = caster[62]; Y = weapon_data;
 if (DualHitSetup()) PA /= 2; // halve for dual wield
} else {
 sub_1402FD0E0(); // alt setup
 result[18] = 4; // equipment destroy flag
 PA = caster[62]; Y = weapon_data;
}
sub_1402FC81C();
ApplyPhysModifiers(); // sub_1402FDA94
ApplyZodiacCharge(); // sub_1402FCB18
CalcFinalDamage(); // sub_1402FCB6C
faith_resultadjust(); // sub_1402FC1B8
```
</details>

### F47 — Duskblade (HP Drain)
```
Damage = PA × WP × [×2 dual wield] × [×3/2 Berserk/AttackUp]
 × [×2/3 target Protect] × [×3/2 target Sleep]
 × Zodiac(50-150%) × [critical]
capped at 32767. Caster heals HP equal to damage dealt
```
> Duskblade
<details><summary>Decompiled (resultcalculate_f47) — 70 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 PA = caster[62]; Y = weapon_data; // byte_1407A9F1C
 ApplyPhysModifiers(); // sub_1402FDA94
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcFinalDamage(); // sub_1402FCB6C
 sub_1402FD01C(); // HP drain to caster
}
```
</details>

### F48 — Shadowblade (MP Drain)
```
Damage = PA × WP × [×2 dual wield] × [×3/2 Berserk/AttackUp]
 × [×2/3 target Protect] × [×3/2 target Sleep]
 × Zodiac(50-150%) × [critical]
capped at 32767. Caster recovers MP equal to damage dealt
```
> Shadowblade
<details><summary>Decompiled (resultcalculate_f48, thunk resolved) — 70 bytes</summary>

```c
// Thunk: 0x1402FF30C → 0x14E77B1CC
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 PA = caster[62]; Y = weapon_data; // byte_1407A9F1C
 ApplyPhysModifiers(); // sub_1402FDA94
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcFinalDamage(); // sub_1402FCB6C
 sub_1402FCF54(); // MP drain to caster
}
```
</details>

---

## Monk / Martial Arts

### F49 — Monk Physical (Averaged)
```
PA = caster PA stat, Y = (ability_Y + PA) / 2
Damage = PA × Y × [×5/4 element] × [×3/2 Berserk]
 × [×2/3 target Protect] × [×3/2 target Sleep]
 × Zodiac(50-150%) × [critical] × [weather] × [element absorb/weak]
capped at 32767, then counter + status check
```
> Cyclone, Aurablast, Shockwave
<details><summary>Decompiled (sub_14E7848F1 via thunk at 0x1402FF354) — 139 bytes</summary>

```c
// Thunk: 0x1402FF354 → 0x14E7848F1 (anti-tamper-obfuscated)
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 PA = caster[62]; // PA stat
 Y = (ability_Y + PA) / 2; // averaged
 ApplyElementBoost(); // sub_1402FC84C
 ApplyPA_StatusMods(); // sub_1402FC87C
 sub_1402FC96C(); sub_1402FC9A4(); sub_1402FCA54();
 ZodiacCompatibility(); // sub_1402FBDDC
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcFinalDamage(); // sub_1402FCB6C (PA × Y)
 ApplyWeather(); // sub_1402FCD98
 ApplyElementCheck(); // sub_1402FCE2C
 if (target_result[0]) {
 sub_1402FCE88(); // post-damage
 result = sub_1402FD870(); // counter check
 if (!result) return sub_1402FD5A4(); // status
 }
}
```
</details>

### F50 — Pummel (Random Hits)
```
Y_avg = (ability_Y + PA) / 2
Base = (PA + Y_avg) × [×3/2 Berserk] × [×2/3 target Protect]
 × [×3/2 Sleep] × Zodiac(50-150%) × [critical]
Hits = random(1..X)
Total Damage = Base × Hits
(ADDITIVE base, not multiplicative)
```
> Pummel
<details><summary>Decompiled (resultcalculate_f50) — 159 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 PA = caster[62];
 Y = (ability_secondary[14] + caster[62]) >> 1; // (Y+PA)/2
 ApplyPA_StatusMods(); // sub_1402FC87C
 sub_1402FC96C(); sub_1402FC9A4(); sub_1402FCA54();
 ZodiacCompatibility(); // sub_1402FBDDC
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcTotalDamage(); // sub_1402FCBB0
 hits = RNG() * X / 0x8000 + 1; // random hit count
 result[6] = hits * result[6]; // multiply damage
 result[39] = 0x80;
}
```
</details>

### F51 — Purification
```
Hit = (PA + X) × [×3/2 Berserk] × [×3/2 Charging]
 × Zodiac(50-150%) × faith_scaling
On success: removes negative statuses from target
(ADDITIVE base)
```
> Purification
<details><summary>Decompiled (resultcalculate_f51) — 83 bytes</summary>

```c
PA = caster[62]; X = ability_secondary[13];
ApplyPA_StatusMods(); // sub_1402FC87C
sub_1402FC96C(); // phys modifier
ZodiacCompatibility(); // sub_1402FBDDC
CalcTotalDamage(); // sub_1402FCBB0
ApplyFaithScaling(); // sub_1402FD06C
if (target_result[0])
 resultcalculate_f56(); // remove statuses
```
</details>

### F52 — Chakra
```
Base = PA × Y × [×3/2 Berserk] × Zodiac(50-150%)
capped at 32767
HP heal = Base, MP heal = Base / 2
(MULTIPLICATIVE, no faith)
```
> Chakra (Y=5)
<details><summary>Decompiled (resultcalculate_f52) — 95 bytes</summary>

```c
PA = caster[62]; Y = ability_secondary[14];
ApplyPA_StatusMods(); // sub_1402FC87C
ZodiacCompatibility(); // sub_1402FBDDC
CalcFinalDamage(); // sub_1402FCB6C
result[8] = result[6]; // HP heal amount
result[6] = 0; // clear damage
result[12] = result[8] / 2; // MP heal = half
result[39] = 80; // flags: HP_Healing+MP_Healing
```
</details>

### F53 — Revive
```
Hit = (PA + X) × [×3/2 Berserk] × Zodiac(50-150%)
 × faith_scaling
If target dead: Heal = (Y × MaxHP + 99) / 100
then Undead reverse check
(ADDITIVE hit, but heal is HP%-based)
```
> Revive (Y=20), Squeal (Y=100)
<details><summary>Decompiled (resultcalculate_f53) — 136 bytes</summary>

```c
PA = caster[62]; X = ability_secondary[13];
ApplyPA_StatusMods(); // sub_1402FC87C
ZodiacCompatibility(); // sub_1402FBDDC
CalcTotalDamage(); // sub_1402FCBB0
ApplyFaithScaling(); // sub_1402FD06C
if (target_result[0]) {
 if (sub_140300164()) { // check dead
 damage = (Y * target[50] + 99) / 100; // Y% MaxHP
 result[39] |= 0x80;
 result[6] = damage;
 UndeadReverse(); // sub_1402FCFDC
 }
}
```
</details>

---

## Squire / Basic Skills

### F54 — Focus / Accumulate
```
Self only: PA += Y (always succeeds, no calculation)
```
> Focus (Y=1), Beef Up (Y=2)
<details><summary>Decompiled (resultcalculate_f54) — 24 bytes</summary>

```c
result = qword_141864080;
result[22] = ability_secondary[14] | 0x80; // stat boost + flag
result[39] = 1; // flags: StatChange
```
</details>

### F55 — Rush / Basic Physical
```
Hits = random(1..Y)
Damage = PA × Hits × [×3/2 Berserk] × [×2/3 target Protect]
 × [×3/2 Sleep] × Zodiac(50-150%)
+ random critical hit chance
```
> Rush, Throw Stone, Cat Scratch, Tail Sweep
<details><summary>Decompiled (resultcalculate_f55, thunk resolved) — 219 bytes</summary>

```c
// Thunk: 0x1402FF5BC → 0x14E7B232A
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 PA = caster[62]; Y = ability_secondary[14];
 ApplyPA_StatusMods(); // sub_1402FC87C
 sub_1402FC96C(); sub_1402FC9A4(); sub_1402FCA54();
 ZodiacCompatibility(); // sub_1402FBDDC
 hits = RNG() * Y / 0x8000 + 1; // random multiplier
 result[6] = hits * PA;
 result[39] = 0x80;
 // Additional RNG check for critical hit via sub_1402FBA24
}
```
</details>

### F56 — Status-Only Application
```
674-byte status engine with 4 modes:
 bit 0x80: add statuses directly from ability data
 bit 0x40: random status from target's current statuses
 bit 0x20: remove matching statuses (faith roll)
 bit 0x10: add from secondary status table
No damage component — status only
```
> Salve, Petrify, Shadowbind, Bad Breath, Grand Cross (22 total)
<details><summary>Decompiled (resultcalculate_f56, thunk resolved) — 674 bytes</summary>

```c
// Thunk: 0x1402FD5EC → 0x14E71C643
// Reads qword_1407A9F20 control byte:
// bit 0x80: direct status add from ability data
// bit 0x40: random status from target's current statuses
// bit 0x20: remove matching statuses (with faith roll)
// bit 0x10: add from secondary status table
// Merges status bytes into result[29..34]
// Calls j_change_status_adjust(0) for validation
if (status_applied) {
 result[39] |= 8; // flags: StatusChange
 if (result[30] & 0x40) result[18] |= 0x40; // special flag
} else {
 result[0] = 0; result[2] = 7; result[44] = 0; // miss
}
```
</details>

### F57 — Tailwind
```
Self only: Speed += Y (always succeeds, no calculation)
```
> Tailwind (Y=1)
<details><summary>Decompiled (resultcalculate_f57) — 24 bytes</summary>

```c
result[20] = ability_secondary[14] | 0x80; // speed boost
result[39] = 1;
```
</details>

### F58 — Steel
```
Self only: Brave += Y (always succeeds, no calculation)
```
> Steel (Y=5)
<details><summary>Decompiled (resultcalculate_f58) — 24 bytes</summary>

```c
result[24] = ability_secondary[14] | 0x80; // brave boost
result[39] = 1;
```
</details>

### F59 — Shout
```
Self only: Brave += X, PA += Y, MA += Y, Speed += Y
(always succeeds, all stats boosted at once)
```
> Shout (X=10, Y=1)
<details><summary>Decompiled (resultcalculate_f59) — 40 bytes</summary>

```c
result[24] = ability_secondary[13] | 0x80; // X → Brave
y_val = ability_secondary[14] | 0x80;
result[39] = 1;
result[22] = y_val; // Y → PA
result[23] = y_val; // Y → MA
result[20] = y_val; // Y → Speed
```
</details>

### F60 — Chant
```
HP heal = caster_MaxHP / 5 (deals as damage to target, heals undead)
MP heal = caster_MaxHP / 5 × 2 (heals caster MP)
```
> Chant, Energize
<details><summary>Decompiled (resultcalculate_f60) — 58 bytes</summary>

```c
secondary = qword_141864088;
hp_heal = caster[50] / 5; // MaxHP / 5
secondary[6] = hp_heal;
secondary[39] = 0x80; // flags: HP_Damage
secondary[0] = 1; // active
result[8] = 2 * hp_heal; // MP heal = 2× HP heal
result[39] = 64; // flags: HP_Healing
```
</details>

---

## Special / Monster Formulas

### F61 — Physical Status-Only
```
Physical hit check (no damage calculation)
On success: applies status via f56 engine
```
> Blaster, Mind Blast, Doom
<details><summary>Decompiled (resultcalculate_f61) — 32 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result) {
 // sub_1402FDCE8: physical hit check (evade-based, no damage calc)
 result = sub_1402FDCE8();
 if (!result)
 resultcalculate_f56(); // status application
}
```
</details>

### F62 — Reduce to 1 HP
```
Damage = target_CurHP - 1 (always reduces to exactly 1 HP)
No hit check, no modifiers, always succeeds
```
<details><summary>Decompiled (resultcalculate_f62) — 43 bytes</summary>

```c
hp = target[48]; // current HP
if (hp)
 result[6] = hp - 1; // reduce to 1 HP
else
 result[6] = 0;
result[39] = 0x80; // flags: HP_Damage
```
</details>

### F63 — Aimed Shot (Speed-Based)
```
Hit = (Speed + X) × [×2 dual wield] × [×3/2 Berserk/AttackUp]
 × [×2/3 target Protect] × [×3/2 Sleep] × Zodiac
 × faith_scaling
On success: inflicts status (ADDITIVE, uses SPEED not PA!)
```
> Leg Shot, Arm Shot
<details><summary>Decompiled (resultcalculate_f63) — 73 bytes</summary>

```c
PA = caster[64]; // Speed stat (not PA!)
X = ability_secondary[13];
ApplyPhysModifiers(); // sub_1402FDA94
CalcTotalDamage(); // sub_1402FCBB0
ApplyFaithScaling(); // sub_1402FD06C
if (target_result[0])
 resultcalculate_f56();
```
</details>

### F64 — Seal Evil
```
Hit = (Speed + X) × [phys modifiers] × Zodiac × faith_scaling
On success: applies status ONLY if target is Undead
(ADDITIVE, uses SPEED. Fails on non-Undead targets)
```
> Seal Evil
<details><summary>Decompiled (resultcalculate_f64) — 102 bytes</summary>

```c
PA = caster[64]; X = ability_secondary[13];
ApplyPhysModifiers(); CalcTotalDamage();
ApplyFaithScaling();
if (target_result[0]) {
 if (target[97] & 0x10) // must be Undead
 resultcalculate_f56();
 else
 { result[0] = 0; result[2] = 7; } // fail if not Undead
}
```
</details>

### F65 — Celestial Stasis
```
Physical hit check, then zodiac sign comparison:
 if caster and target have DIFFERENT zodiac signs → status applied
 if SAME sign → auto-miss
(no damage, status only)
```
> Celestial Stasis
<details><summary>Decompiled (resultcalculate_f65) — 85 bytes</summary>

```c
// sub_1402FDCE8: physical hit check (evade-based, no damage calc)
result = sub_1402FDCE8();
if (!result) {
 caster_sign = caster[8]; // zodiac from BWORK+8
 target_sign = target[8];
 if ((caster_sign ^ target_sign) & 0xF000) // different signs
 resultcalculate_f56();
 else
 { result[0] = 0; result[2] = 7; } // same sign = fail
}
```
</details>

### F66 — Construct Physical
```
Primary: Damage = PA × Y × Zodiac(50-150%)
Secondary: Damage = PA × Y / X
(two hits, no other modifiers)
```
> Destroy, Compress, Dispose, Pulverize
<details><summary>Decompiled (resultcalculate_f66) — 111 bytes</summary>

```c
PA = caster[62]; Y = ability_secondary[14];
ZodiacCompatibility(); // sub_1402FBDDC
result[6] = PA * Y; // primary damage
secondary[6] = PA * Y / ability_secondary[13]; // secondary = damage/X
secondary[0] = 1;
result[39] = 0x80; secondary[39] = 0x80;
```
</details>

### F67 — Missing HP Damage
```
Damage = MaxHP - CurHP (the more hurt the target, the more damage)
No hit check, no modifiers, always succeeds
```
> Vengeance, Blade Burst, Almagest, Karma
<details><summary>Decompiled (resultcalculate_f67) — 31 bytes</summary>

```c
result[6] = target[50] - target[48]; // MaxHP - CurHP
result[39] = 0x80;
```
</details>

### F68 — Current MP Damage
```
Damage = target's current MP (drains all MP as HP damage)
No hit check, no modifiers, always succeeds
```
> Manaburn
<details><summary>Decompiled (resultcalculate_f68) — 27 bytes</summary>

```c
result[6] = target[52]; // current MP (offset +52)
result[39] = 0x80;
```
</details>

### F69 — Missing HP (alt)
```
Damage = MaxHP - CurHP (identical to F67)
No hit check, no modifiers
```
<details><summary>Decompiled (j_CheckWeatherThing) — 31 bytes</summary>

```c
result[6] = target[50] - target[48]; // MaxHP - CurHP
result[39] = 0x80;
```
</details>

### F71 — % HP Drain
```
Damage = (Y × target_MaxHP + 99) / 100
Caster recovers MP equal to damage dealt
then status applied via f56
```
> Blood Drain
<details><summary>Decompiled (resultcalculate_f71) — 67 bytes</summary>

```c
damage = (Y * target[50] + 99) / 100; // Y% of MaxHP
result[39] |= 0x80;
result[6] = damage;
sub_1402FCF54(); // MP drain to caster
SaveAndRestoreResultFlags(); // sub_1402FD5A4 → status
```
</details>

### F76 — Magic Heal (Simplified)
```
Heal = MA × Y × [×4/3 caster boost] × Zodiac(50-150%)
capped at 32767, then Undead reverse check
(no faith scaling, no element boost, no Shell)
```
> Choco Cure, Life Nymph
<details><summary>Decompiled (resultcalculate_f76) — 60 bytes</summary>

```c
MA = caster[63]; Y = ability_secondary[14]; // MA stat
ApplyCasterMagicBoost(); // sub_1402FC914 — ×4/3
ZodiacCompatibility(); // sub_1402FBDDC
CalcFinalDamage(); // sub_1402FCB6C
UndeadReverse(); // sub_1402FCFDC
```
</details>

### F77 — Physical HP Drain
```
Hit = (MA + X) × [×3/2 Berserk] × [×3/2 Charging]
 × [×2/3 target Protect] × [×3/2 Sleep] × Zodiac × faith_scaling
On success: Damage = (Y × MaxHP + 99) / 100
Caster recovers MP equal to damage (ADDITIVE hit check)
```
> Bloodfeast, Drain Touch
<details><summary>Decompiled (resultcalculate_f77) — 113 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 MA = caster[63]; X = ability_secondary[13];
 // CalcPhysicalDamageChain (sub_1402FDD44):
 // PA_StatusMods → Charging(×3/2) → Protect(×2/3) → Sleep(×3/2)
 // → Zodiac → CalcTotalDamage(PA+X, ADDITIVE) → FaithScaling
 result = CalcPhysicalDamageChain(); // sub_1402FDD44
 if (!result) {
 damage = (Y * target[50] + 99) / 100;
 result[39] |= 0x80;
 result[6] = damage;
 sub_1402FCF54(); // MP drain
 }
}
```
</details>

### F78 — MA × Y Physical (Full Chain)
```
Damage = MA × Y × [×5/4 element] × [×4/3 caster boost]
 × [×2/3 Shell] × [×3/2 Sleep] × Zodiac(50-150%)
 × [weather] × [element absorb/weak]
capped at 32767, then counter + status check
(MULTIPLICATIVE, uses MA not PA)
```
> Breath attacks, Cloud limits (Braver→Omnislash), monster attacks (25 total)
<details><summary>Decompiled (resultcalculate_f78) — 55 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result) {
 MA = caster[63]; Y = ability_secondary[14];
 // sub_1402FDBAC (full physical chain):
 // ElementBoost(×5/4) → CasterBoost(×4/3) → Shell(×2/3) → Sleep(×3/2)
 // → Zodiac → CalcFinalDamage(PA×Y, MULTIPLICATIVE) → Weather → ElementCheck
 sub_1402FDBAC();
}
```
</details>

### F79 — Physical + Missing HP
```
Hit = (MA + X) × [phys status mods] × Zodiac × faith_scaling
On success: Damage = MaxHP - CurHP (overrides hit check value)
(ADDITIVE hit, but damage is fixed HP-based)
```
> Goblin Punch
<details><summary>Decompiled (resultcalculate_f79) — 89 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 MA = caster[63]; X = ability_secondary[13];
 // CalcPhysicalDamageChain (sub_1402FDD44):
 // PA_StatusMods → Charging(×3/2) → Protect(×2/3) → Sleep(×3/2)
 // → Zodiac → CalcTotalDamage(PA+X, ADDITIVE) → FaithScaling
 result = CalcPhysicalDamageChain(); // sub_1402FDD44
 if (!result) {
 result[6] = target[50] - target[48]; // MaxHP - CurHP
 result[39] = 0x80;
 }
}
```
</details>

### F80 — Physical + Status
```
Hit = (MA + X) × [phys status mods] × Zodiac × faith_scaling
On success: applies status via f56 engine
(ADDITIVE hit check, uses MA not PA)
```
> Doom Fist, Venom Fang, Eye Gouge, touch attacks (9 total)
<details><summary>Decompiled (resultcalculate_f80) — 64 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 MA = caster[63]; X = ability_secondary[13];
 // CalcPhysicalDamageChain (sub_1402FDD44):
 // PA_StatusMods → Charging(×3/2) → Protect(×2/3) → Sleep(×3/2)
 // → Zodiac → CalcTotalDamage(PA+X, ADDITIVE) → FaithScaling
 result = CalcPhysicalDamageChain(); // sub_1402FDD44
 if (!result)
 resultcalculate_f56(); // apply status
}
```
</details>

---

## Brave-Based Formulas

### F97 — Magic-Based Brave Modify
```
Hit check: magic chain (MA + X) × all magic modifiers × Faith²/10000
On success: target's Brave adjusted by Y & 0x7F
(uses MAGIC hit check, faith-dependent)
```
> Trepidation, Chicken
<details><summary>Decompiled (sub_1402FFF78) — 50 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result) {
 // MagicChain (sub_1402FDC88, WITH element boost):
 // MA=caster[63], X=ability_X → ElementBoost(×5/4) → CasterBoost(×4/3)
 // → Shell(×2/3) → Sleep(×3/2) → Zodiac → CalcTotal(MA+X) → Faith² → FaithScaling
 result = sub_1402FDC88(); // magic hit check
 if (!result) {
 result[24] = ability_secondary[14] & 0x7F; // brave modify
 result[39] = 1;
 }
}
```
</details>

### F98 — Physical-Based Brave Modify
```
Hit check: physical hit check (evade-based)
On success: target's Brave adjusted by Y & 0x7F
(uses PHYSICAL hit check, evade-dependent)
```
> Dread Gaze
<details><summary>Decompiled (sub_1402FFFAC) — 50 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers(); // sub_1402FD9D0
if (!result) {
 // sub_1402FDCE8: physical hit check (evade-based, no damage calc)
 result = sub_1402FDCE8(); // physical hit check
 if (!result) {
 result[24] = ability_secondary[14] & 0x7F; // brave modify
 result[39] = 1;
 }
}
```
</details>

---

## WotL Additions (F102–F106)

### F102 — WotL Physical (80% + HP Drain)
```
Damage = PA × WP × [phys modifiers] × Zodiac × [critical]
capped at 32767, then × 80% (8/10 multiplier)
Caster heals HP equal to reduced damage
```
<details><summary>Decompiled (sub_14030420C) — 107 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 PA = caster[62]; Y = byte_1407A9F1C; // weapon power
 ApplyPhysModifiers(); // sub_1402FDA94
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcFinalDamage(); // sub_1402FCB6C
 result[6] = 8 * result[6] / 10; // 80% damage
 sub_1402FD01C(); // HP drain to caster
}
```
</details>

### F103 — WotL Holy Sword (alias)
```
Identical to F45 (Holy Sword)
Damage = PA × (WP + Y) × [phys modifiers] × Zodiac × [element]
(double thunk resolves to same function)
```
<details><summary>Decompiled (j_resultcalculate_f45) — 5 bytes</summary>

```c
// Thunk: 0x140304278 → 0x1402FF124 → 0x14E76A74E
// Identical to F45 (Holy Sword)
resultcalculate_f45();
```
</details>

### F104 — WotL Distance-Scaled Physical
```
Base damage from CalcWeaponDamage (weapon-type specific)
then distance modifier:
 adjacent (1 tile): Y += 3 (bonus damage)
 near (2 tiles): Y += 1 (small bonus)
 far (3+ tiles): PA /= 2 (halved damage)
then × [phys modifiers] × Zodiac × [element]
capped at 32767 + faith adjust + status
```
<details><summary>Decompiled (sub_140304280) — 190 bytes</summary>

```c
result = CalcPhysicalEvade(); // sub_1402FD8F0
if (!result) {
 CalcWeaponDamage(); // sub_1402FC6AC
 dist = max(abs(caster[79] - target[79]),
 abs(caster[80] - target[80]));
 switch (dist - 1) {
 case 0: Y += 3; break; // adjacent: bonus
 case 1: Y += 1; break; // near: small bonus
 default: PA /= 2; break; // far: halved
 }
 sub_1402FC81C();
 ApplyPhysModifiers(); // sub_1402FDA94
 ApplyZodiacCharge(); // sub_1402FCB18
 CalcFinalDamage(); // sub_1402FCB6C
 faith_resultadjust(); // sub_1402FC1B8
 if (target_result[0]) {
 sub_1402FCE88();
 SaveAndRestoreResultFlags();
 }
}
```
</details>

### F105 — WotL Level-Scaled Physical
```
PA = MA stat, Y = PA + 3 × MaxHP / (10 × MA)
then full physical chain: element/modifiers/zodiac/PA×Y
(scales with both stats and HP pool)
```
<details><summary>Decompiled (sub_140304340) — 64 bytes</summary>

```c
MA = caster[63];
v0 = caster[62]; // PA stat
v1 = 10 * caster[63]; // 10 × MA
Y = v0 + 3 * (unsigned int)caster[50] % v1; // PA + 3×MaxHP%/(10×MA)
// sub_1402FDBAC (full physical chain):
// ElementBoost(×5/4) → CasterBoost(×4/3) → Shell(×2/3) → Sleep(×3/2)
// → Zodiac → CalcFinalDamage(PA×Y, MULTIPLICATIVE) → Weather → ElementCheck
sub_1402FDBAC();
```
</details>

### F106 — Re-Dispatch (Chain Formula)
```
Not a damage formula — re-calls the dispatch table with a different
formula ID, allowing one ability to chain into another formula.
Then applies post-dispatch modifiers.
```
<details><summary>Decompiled (RESUME_SET_BCALC) — 31 bytes</summary>

```c
off_14067D130[byte_1407A9F1A - 1](); // re-dispatch formula
PostDispatch_ApplyModifiers(); // post-processing
```
</details>

---

## Monster & Special Formulas (F81–F95)

Decompiled from binary. Ability parameters verified from `AbilitySecondaryData` at `0x1407852F0`.

### F81 — Monster Buff/Heal (Magic Hit → Status)
```
Hit = (MA + X) × [×5/4 element] × [×4/3 MagicAttackUp]
    × Zodiac(50-150%) × faith_scaling
On success: apply status via f56 engine
(Uses CalcTotalDamage — additive base, same as F10/F11)
```
> Choco Esuna (X=65, ST=100), Guardian Nymph (X=45, ST=35), Shell Nymph (X=45, ST=36)
<details><summary>Decompiled (sub_1402FFAF0) — 83 bytes</summary>

```c
MA = caster[63];
X = ability_secondary[13];                       // ability X param
ApplyElementBoost();                             // sub_1402FC84C — ×5/4
ApplyCasterMagicBoost();                         // sub_1402FC914 — ×4/3
ZodiacCompatibility();                           // sub_1402FBDDC
CalcTotalDamage();                               // sub_1402FCBB0 — MA + X (ADDITIVE)
ApplyFaithScaling();                             // sub_1402FD06C
if (target_result[0])
    resultcalculate_f56();                       // apply status
```
</details>

### F82 — Self-Destruct (HP-Based Damage)
```
If caster == source (self-target): Damage = CurHP
If caster ≠ source (AoE target):  Damage = MaxHP - CurHP
Then: status applied via f56
```
> Self-Destruct (ST=101)
<details><summary>Decompiled (sub_1402FFB44) — 67 bytes</summary>

```c
if (caster == source)
    damage = source[48];                         // CurHP (suicide)
else
    damage = source[50] - source[48];            // MaxHP - CurHP
result[39] = 0x80;                               // flags: HP_Damage
result[6] = damage;
if (caster != source)
    SaveAndRestoreResultFlags();                 // sub_1402FD5A4 → status
```
</details>

### F83 — Monster % HP Damage (Physical Chain)
```
Evade check → physical hit check
Damage = (Y × caster_MaxHP + 99) / 100
    → post-damage modifiers (sub_FCD98, sub_FCE2C)
    → post-processing (sub_FCE88, sub_FD870, sub_FD5A4)
```
> Twister (X=50, Y=34, Elem=Wind), Tri-Breath (X=120, Y=50)
<details><summary>Decompiled (sub_1402FFB88) — 117 bytes</summary>

```c
result = sub_1402FD9D0();                        // evade/equip modifier check
if (!result) {
    result = sub_1402FDCE8();                    // physical hit check
    if (!result) {
        damage = (ability_Y * caster[50] + 99) / 100; // Y% of caster MaxHP
        result[39] |= 0x80;                     // flags: HP_Damage
        result[6] = damage;
        sub_1402FCD98();                         // post-damage modifier
        sub_1402FCE2C();                         // post-damage modifier
        if (target_result[0]) {
            sub_1402FCE88();                     // post-damage processing
            result = sub_1402FD870();            // counter/reaction check?
            if (!result)
                sub_1402FD5A4();                 // status application?
        }
    }
}
```
</details>

### F84 — MP Restoration (Magic-Based)
```
Heal MP = MA × Y × [×4/3 MagicAttackUp] × Zodiac(50-150%)
(No hit check — always succeeds. Heals MP, not HP)
```
> Magick Nymph (X=0, Y=1)
<details><summary>Decompiled (sub_1402FFC00) — 85 bytes</summary>

```c
MA = source[63];                                 // qword_141864098 + 63
WORD1(attack_params) = ability_secondary[14];    // Y param (BYTE14)
LOWORD(attack_params) = MA;
ApplyCasterMagicBoost();                         // sub_1402FC914 — ×4/3
ZodiacCompatibility();                           // sub_1402FBDDC
CalcFinalDamage();                               // sub_1402FCB6C — MA × Y (multiplicative)
result[12] = result[6];                          // move to MP heal slot
result[6] = 0;                                   // clear HP damage
result[39] = 16;                                 // flags: MP_Healing
```
</details>

### F85 — Peck (Physical Hit → PA Drain)
```
Evade check → physical hit check
On success: target PA reduced by Y
(Y & 0x7F = amount without direction bit. Compare F54 Focus which uses Y | 0x80 for increase)
```
> Peck (X=45, Y=2)
<details><summary>Decompiled (sub_1402FFC58) — 50 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
    result = sub_1402FDCE8();                    // physical hit check
    if (!result) {
        result[22] = ability_Y & 0x7F;           // PA drain (no 0x80 = decrease)
        result[39] = 1;                          // flags: StatChange
    }
}
```
</details>

### F86 — Beam (Physical Hit → MA Drain)
```
Evade check → physical hit check
On success: target MA reduced by Y
(Y & 0x7F = amount without direction bit. Compare F54 Focus which uses Y | 0x80 for increase)
```
> Beam (X=55, Y=2)
<details><summary>Decompiled (sub_1402FFC8C) — 50 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
    result = sub_1402FDCE8();                    // physical hit check
    if (!result) {
        result[23] = ability_Y & 0x7F;           // MA drain (no 0x80 = decrease)
        result[39] = 1;                          // flags: StatChange
    }
}
```
</details>

### F87 — Bequeath Bacon (Self-Sacrifice)
```
Sets result[6] = caster MaxHP, result[12] = caster MaxMP
Initial flags: 0x90 (HP_Damage | MP_Healing)
Then sub_1402FCFDC processes the values
If caster level < 99: flags OVERWRITTEN to 1 (StatChange)
    Swaps pointers → applies status (ST=96) to CASTER via f56
    Then restores pointers
If caster level ≥ 99: auto-miss
Note: the 0x90 flag is overwritten before engine reads it,
so HP/MP fields may only matter for sub_1402FCFDC processing.
```
> Bequeath Bacon (ST=96)
<details><summary>Decompiled (sub_1402FFCC0) — 146 bytes</summary>

```c
result[6] = caster[50];                          // caster MaxHP → hp_dmg slot
result[12] = caster[54];                         // caster MaxMP → mp_heal slot
result[39] = 0x90;                               // flags: HP_Damage(0x80) | MP_Healing(0x10)
sub_1402FCFDC();                                 // processes result (undead reverse?)
if (caster[41] < 99) {                           // level check
    result[39] = 1;                              // OVERWRITES to: StatChange
    result[18] = 128;                            // attack_type
    // Swap pointers: apply status to CASTER (self-kill)
    qword_141864090 = source;
    qword_141864080 = secondary;
    secondary[0] = 1;
    resultcalculate_f56();                       // apply status (ST=96) to caster
    // Restore pointers
    qword_141864090 = caster;
    qword_141864080 = result;
} else {
    // Level 99+: auto-miss
    result[0] = 0; result[2] = 7; result[44] = 0;
}
```
</details>

### F88 — Malboro Spores (Magic Hit → Recruitment)
```
Hit = (MA + X) × [×5/4 element] × [×4/3 MagicAttackUp]
    × Zodiac(50-150%) × faith_scaling
On success: validates CASTER (not target) for recruitment eligibility
    Fails if: caster[5] bit 2 set, caster[436] nonzero,
    or (caster[0] + 0x80) > 2, or (caster[3] + 126) <= 2
    (exact meaning of these fields is unclear)
On valid: attack_type = 2 (recruit/charm)
```
> Malboro Spores (X=5)
<details><summary>Decompiled (sub_1402FFD54) — 149 bytes</summary>

```c
MA = caster[63];
X = ability_secondary[13];
ApplyElementBoost();                             // sub_1402FC84C — ×5/4
ApplyCasterMagicBoost();                         // sub_1402FC914 — ×4/3
ZodiacCompatibility();                           // sub_1402FBDDC
CalcTotalDamage();                               // sub_1402FCBB0 — MA + X
ApplyFaithScaling();                             // sub_1402FD06C
if (target_result[0]) {
    // Caster validation (checks caster, NOT target):
    if ((caster[5] & 4) || caster[436] ||
        (caster[0] + 0x80) > 2 || (caster[3] + 126) <= 2) {
        // Invalid: auto-miss
        result[0] = 0; result[2] = 7; result[44] = 0;
    } else {
        result[18] = 2;                          // attack_type: recruit
        result[39] = 1;                          // flags: StatChange
    }
}
```
</details>

### F89 — Level Drain (Physical Hit → Level Steal)
```
Evade check → physical hit check
If caster level ≤ 1: auto-miss (can't go lower)
On success: attack_type = 256 (level drain flag)
```
> Level Drain (X=60)
<details><summary>Decompiled (sub_1402FFDEC) — 75 bytes</summary>

```c
result = LoadEvadeAndEquipModifiers();           // sub_1402FD9D0
if (!result) {
    result = sub_1402FDCE8();                    // physical hit check
    if (!result) {
        if (caster[41] <= 1) {                   // caster level check
            result[0] = 0; result[2] = 7;        // auto-miss if level 1
            result[44] = 0;
        }
        result[39] = 1;                          // flags: StatChange
        result[18] = 256;                        // attack_type: level drain
    }
}
```
</details>

### F90 — Dragon's Charm (Species-Gated Status)
```
No hit check — always succeeds
Species gate: caster[398] must be 15 or 16 (Dragon type)
    If not dragon: auto-miss
On success: apply status via f56 engine
```
> Dragon's Charm (ST=63)
<details><summary>Decompiled (sub_1402FFE38) — 58 bytes</summary>

```c
species = caster[398];
if (species != 15 && species != 16) {            // not a dragon
    result[0] = 0; result[2] = 7; result[44] = 0; // auto-miss
}
if (target_result[0])
    resultcalculate_f56();                       // apply status (charm)
```
</details>

### F91 — Dragon's Gift (Species-Gated HP/MP Gift)
```
Species gate: caster[398] must be 15 or 16 (Dragon type)
    If not dragon: auto-miss
On success: secondary[6] = caster_MaxHP / 5 (damage to self)
            result[8] = 2 × (MaxHP/5)           (HP heal to target)
Then: status applied via f56
(Structure identical to F60 Chant — self-damage + target heal)
```
> Dragon's Gift (ST=94)
<details><summary>Decompiled (sub_1402FFE74) — 114 bytes</summary>

```c
if ((caster[398] - 15) > 1) {                    // species gate
    result[0] = 0; result[2] = 7; result[44] = 0;
}
if (target_result[0]) {
    hp_gift = source[50] / 5;                    // MaxHP / 5
    secondary[6] = hp_gift;                      // damage to caster
    secondary[39] = 0x80;                        // flags: HP_Damage (on caster)
    secondary[0] = 1;                            // active
    result[8] = 2 * hp_gift;                     // HP heal = 2× gift
    result[39] = 64;                             // flags: HP_Healing
    SaveAndRestoreResultFlags();                  // sub_1402FD5A4 → status
}
```
</details>

### F92 — Dragon's Might (Species-Gated All-Stat Boost)
```
Species gate: caster[398] must be 15 or 16 (Dragon type)
    If not dragon: auto-miss
On success: Brave += X, PA += Y, MA += Y, Speed += Y
(Structure identical to F59 Shout)
```
> Dragon's Might (X=5, Y=2)
<details><summary>Decompiled (sub_1402FFEE8) — 77 bytes</summary>

```c
if ((caster[398] - 15) > 1) {                    // species gate
    result[0] = 0; result[2] = 7; result[44] = 0;
}
if (target_result[0]) {
    result[24] = ability_X | 0x80;               // Brave += X
    y_val = ability_Y | 0x80;
    result[39] = 1;                              // flags: StatChange
    result[22] = y_val;                          // PA += Y
    result[23] = y_val;                          // MA += Y
    result[20] = y_val;                          // Speed += Y
}
```
</details>

### F93 — Dragon's Speed (Species-Gated All-Buff)
```
Species gate: caster[398] must be 15 or 16 (Dragon type)
    If not dragon: auto-miss
On success: applies ALL status buffs (result[21] = 0xFF)
```
> Dragon's Speed
<details><summary>Decompiled (sub_1402FFF38) — 53 bytes</summary>

```c
if ((caster[398] - 15) > 1) {                    // species gate
    result[0] = 0; result[2] = 7; result[44] = 0;
}
if (target_result[0]) {
    result[21] = 0xFF;                           // all status buff flags
    result[39] = 1;                              // flags: StatChange
}
```
</details>

### F94 — Tri-Element (re-dispatches to F30)
```
Address: 0x1402FE870 (23 bytes — same function as F30 Iaido Heaven)
Uses F30 pipeline: Evade → sub_1402FDBFC full physical chain
Element and damage come from ability data, not formula logic
```
> Tri-Thunder (X=2, Y=12, Thunder), Tri-Flame (X=2, Y=24, Fire), Dark Whisper (X=5, Y=1, Dark, ST=113)

### F95 — Nanoflare (re-dispatches to F30)
```
Address: 0x1402FE870 (same as F30/F94)
```
> Nanoflare (Y=5)

---

## Abilities Outside the Formula Dispatch

The formula dispatch table (`resultcalculate_fXX` at `qword_14067D128`) handles formulas 1–106. However, two major ability categories bypass this system entirely:

### Throw (Ninja — Item Throwing)
The Throw command does not use a formula ID. Instead, `SetupSkillDataAndDispatch` (`0x140300610`) detects the action type as **category 7** (via `byte_140678FB0` lookup) and routes it through dedicated item-use logic before the formula dispatch is ever reached. Damage is calculated from the thrown item's stats, not from a `resultcalculate_fXX` function.

### Jump (Dragoon — Vertical Attack)
Jump is handled as a **two-phase action**: the launch phase removes the unit from the battlefield, and the landing phase calculates damage through a separate routine that factors in jump height, PA, and weapon power. This occurs outside the standard formula dispatch table.

Neither Throw nor Jump has a `resultcalculate_fXX` entry. To hook these abilities, you must intercept the parent dispatcher (`SetupSkillDataAndDispatch`) or the specific item-use / jump-landing subroutines.

---

## Modifier Reference

These modifiers are applied by the shared subroutines in various formula pipelines.

### Defensive — Target's buffs that reduce incoming damage

| Modifier | Who Has It | What It Does | Net Effect |
|----------|-----------|--------------|------------|
| Protect | Target | Reduces physical damage taken | **−33%** (×2/3) |
| Shell | Target | Reduces magical damage taken | **−33%** (×2/3) |
| Reflect | Target | Bounces spell back at caster | **No damage to target** |

### Offensive — Caster's buffs that increase outgoing damage

| Modifier | Who Has It | What It Does | Net Effect |
|----------|-----------|--------------|------------|
| Attack Up | Caster | Boosts physical damage dealt | **+50%** (×3/2) |
| MagicAttackUp | Caster | Boosts magic damage (sub_FC914, caster byte 153 bit 2) | **+33%** (×4/3) |
| Magic Up | Caster | Boosts magical damage dealt | **+50%** (×3/2) |
| Berserk | Caster | Boosts physical damage (but lose control) | **+50%** (×3/2) |
| Dual Wield | Caster | Two weapons = two hits | **×2** (double) |
| Element Boost | Caster | Equipment amplifies matching element | **+25%** (×5/4) |

### Situational — Based on target's vulnerable state

| Modifier | Who Has It | What It Does | Net Effect |
|----------|-----------|--------------|------------|
| Sleeping | Target | Asleep targets take more damage | **+50%** (×3/2) |
| Charging | Target | Mid-cast targets take more damage | **+50%** (×3/2) |
| Performing | Target | Mid-song/dance targets take more damage | **+50%** (×3/2) |

### Scaling — Always applied to magic formulas

| Modifier | What It Does | Net Effect |
|----------|--------------|------------|
| Faith (caster) | Higher faith = stronger spells cast | × caster_faith / 100 |
| Faith (target) | Higher faith = more affected by magic | × target_faith / 100 |
| Zodiac compat | Sign pairing between caster & target | **×50%** (worst) to **×150%** (best) |
