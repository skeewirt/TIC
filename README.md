# Final Fantasy Tactics: The Ivalice Chronicles

Community research repository for **Final Fantasy Tactics** across all versions — binary analysis, formula documentation, table layouts, and modding references.

## Structure

```
TIC/
├── remaster/              # FFT: War of the Lions Remaster (Steam/PC)
│   ├── formulas/          # Combat formula engine — fully decompiled
│   ├── tables/            # NXD data table layouts (Ability, Job, etc.)
│   └── docs/              # Engine references, modding guides
├── psp/                   # FFT: War of the Lions (PSP) — future
└── psx/                   # FFT (PlayStation) — future
```

## Remaster Research

### [Formula Cheatsheet](remaster/formulas/FORMULA_CHEATSHEET.md)
Complete documentation of all 72 combat formulas (F01–F106), verified against decompiled x86-64 routines from the game executable. Every formula includes:
- Human-readable math with all conditional modifiers
- Decompiled C pseudocode with resolved subroutine addresses
- Additive vs. multiplicative classification
- Ability mappings from the binary dispatch table

### [Formula Reference](remaster/formulas/FORMULA_REFERENCE.md)
Technical companion covering the dispatch table architecture, BWORK unit structure, shared modifier subroutines, and hooking entry points.

### [Ability Table Layout](remaster/tables/Ability.layout.md)
Byte-level documentation of the Ability NXD table — 68 bytes per row, 512 rows. Every offset traced from binary consumers through disassembly decompilation.

### [Engine Reference](remaster/docs/ENGINE_REFERENCE.md)
NXD container format, runtime data flow, and key singleton addresses.

## Methodology

All research is derived from static analysis of the game binary. No behavioral guesses — every formula and table field is traced to its decompiled subroutine. Key findings:
- **Obfuscation**: The remaster uses anti-tamper protection, which scatters function entry points across the binary via JMP thunks. Several formulas (e.g., F49) were previously listed as "unknown" because auto-analysis failed to follow obfuscated entry points.
- **Additive vs. Multiplicative**: The engine uses two distinct damage routines — `CalcTotalDamage` (additive: `PA + Y`) and `CalcFinalDamage` (multiplicative: `PA × Y`). Correctly identifying which formula uses which is critical for accurate modding.

## License

Research documentation only. No game assets or copyrighted material is included in this repository.
