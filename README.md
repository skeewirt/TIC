# Final Fantasy Tactics: The Ivalice Chronicles

Community research repository for **Final Fantasy Tactics** across all versions — binary analysis, formula documentation, table layouts, event scripting tools, and modding references.

## Structure

```
TIC/
├── remaster/
│   ├── event_tool/        # Event script toolkit — disasm/compile/diff/pack
│   ├── formulas/          # Combat formula engine — fully decompiled
│   ├── tables/            # NXD data table layouts (Ability, Job, etc.)
│   └── docs/              # Engine references, modding guides
├── reference/             # IDA output, decompiled functions, game data
│   ├── event_scripts/     # Extracted .e event scripts (560 files)
│   ├── ida_output/        # Decompiled dispatcher (ProcessEventInstructions)
│   └── Dicenes_Names/     # WotL symbol cross-reference
├── psp/                   # FFT: War of the Lions (PSP) — future
└── psx/                   # FFT (PlayStation) — future
```

## Remaster Research

### [Event Script Tools](remaster/event_tool/)
Complete CLI toolkit for event script modding — the first tools ever built for TIC event editing:

- **Disassembler**: Binary → human-readable text or structured JSON with inline dialogue
- **Assembler**: JSON → byte-identical binary (560/560 scripts verified)
- **Diff**: Instruction-level comparison between event scripts
- **List**: Catalog all 560 events with dialogue counts and first-line preview
- **Pack**: One-command Reloaded-II mod packaging

All 243 opcodes in the VM are identified and named, verified via IDA decompilation of `ProcessEventInstructions`. Compatible with [Nenkai's FFTIVC Mod Loader](https://github.com/Nenkai/fftivc.utility.modloader).

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

All research is derived from static analysis of the game binary (`FFT_enhanced.exe`). No behavioral guesses — every formula, table field, and opcode is traced to its decompiled subroutine via IDA Pro.

Key findings:
- **Obfuscation**: The remaster uses anti-tamper protection, which scatters function entry points across the binary via JMP thunks. Several formulas (e.g., F49) were previously listed as "unknown" because auto-analysis failed to follow obfuscated entry points.
- **Additive vs. Multiplicative**: The engine uses two distinct damage routines — `CalcTotalDamage` (additive: `PA + Y`) and `CalcFinalDamage` (multiplicative: `PA × Y`). Correctly identifying which formula uses which is critical for accurate modding.
- **Event VM**: TIC reuses the PSX event bytecode VM with operands widened from 8/16-bit to 32-bit. The dispatcher (`ProcessEventInstructions` at `0x14022674C`, 19KB) was fully decompiled to resolve all opcodes.

## License

Research documentation only. No game assets or copyrighted material is included in this repository.
