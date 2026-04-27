# TIC Event Tool — Starting Points & Prior Art

> We use community work as **starting points** for our own RE. We verify everything ourselves.

---

## Community Intel: BATTLE.BIN / WORLD.BIN

**Talcall (4/24/2026):**
> "TIC still attempts to open the BATTLE.BIN and WORLD.BIN overlays."

On PSX, `BATTLE.BIN` and `WORLD.BIN` were mutually exclusive RAM overlays:
- `BATTLE.BIN` = all battle code + **event scripting engine**
- `WORLD.BIN` = world map + shops

TIC's engine attempts to load these despite not needing overlay swapping (it has full 64-bit address space). This means:
1. The event bytecode interpreter is likely in the code section that maps to `BATTLE.BIN`
2. String references to "BATTLE.BIN" or "WORLD.BIN" in the TIC binary are **entry points** for finding event code
3. The event system architecture likely mirrors PSX's internal structure even in the remaster

**RE Action**: Search the IDB for xrefs to "BATTLE" and "WORLD" strings. The loader that opens BATTLE.BIN will sit adjacent to the event dispatcher.

---

## GitHub Repos — Starting Points

### 1. adamrt/heretic (★64, C99, 457 commits)
**URL**: https://github.com/adamrt/heretic

A **PSX FFT toolkit** that parses the original ISO and renders maps/sprites. Written in C99 with sokol + imgui + cglm.

**Relevance**: Contains event instruction parsing code for PSX format. Useful as a reference for opcode mapping, but our RE must be independent since TIC may have a different format.

**Key files to study**:
- `src/` — event bytecode parsing logic
- `lib/` — data structure definitions for PSX event format
- Uses WebGPU for browser rendering — relevant for our Phase 3 preview

### 2. adamrt/libfft (C99 header library)
**URL**: https://github.com/adamrt/libfft

Single-header C99 library for parsing PSX FFT ISO data including event instructions. More focused than heretic — pure parsing, no rendering.

**Relevance**: Clean reference implementation of PSX event opcode table. Useful for comparing against what we find in TIC binary.

### 3. Nenkai/FaithFramework (★5, C#, 124 commits, MIT)
**URL**: https://github.com/Nenkai/FaithFramework

**Mod framework for the Faith Engine** (FFXVI/FFT). Reloaded-II based. Features:
- ImGui API (debug overlays)
- **Nex Runtime Interface API** (edit NXD tables at runtime)
- Camera Manager (WorldToScreen / Camera Pos)
- Resource Manager (API TODO)

**Relevance**: This is our **output target**. Whatever event compiler we build, its output must work through this framework or the modloader. Also: the Camera Manager API means Nenkai already has camera position/rotation data accessible at runtime — useful for Phase 3 preview.

**Dicene credited** for the Doom sample (running Doom inside FFT via ImGui). Confirms Dicene is collaborating with Nenkai directly.

### 4. Nenkai/fftivc.utility.modloader (v1.7.1, C#)
**URL**: https://github.com/Nenkai/fftivc.utility.modloader

The standard modloader. Handles NXD table diffing, PAC file replacement, string/locale patching, and binary engine patches.

**Relevance**: Our event tool must output in a format this loader can consume. Currently supports `.diff.pac` for file replacement — event script diffs would need this path.

### 5. Nenkai/FF16Tools
**URL**: https://github.com/Nenkai/FF16Tools

CLI for packing/unpacking PAC containers. Required for extracting event data files from TIC.

**Relevance**: Phase 0 dependency. We use `FF16Tools.CLI unpack-all -g fft` to extract PAC contents and search for event bytecode blobs.

### 6. cipherxof/FFTGenericJobs
**URL**: https://github.com/cipherxof/FFTGenericJobs

TriggerHappy's runtime patcher. Contains **engine function signatures** for battle code, including hooks near event-adjacent code.

**Relevance**: The sig patterns in this repo can guide us to battle-phase functions. Since events run during battle (in the BATTLE.BIN equivalent), his hooks may be near event dispatcher code.

### 7. mullerdane85-hash/FFTIvaliceEditor
**URL**: https://github.com/mullerdane85-hash/FFTIvaliceEditor

Community GUI editor for TIC. Has Job Editor + Ability Editor with named dropdowns.

**Relevance**: Demonstrates the UI patterns the community is already comfortable with. No event editing capability.

---

## PSX Event System Architecture (Reference Only)

From community documentation, the PSX event system works as:

```
ATTACK.OUT (conditionals table)
    → maps (scenario_id, map_id) → event_index
    → stored in BATTLE.BIN overlay

EVENT/ folder in ISO
    → per-event bytecode files
    → ~500 events, ~300KB total bytecode
    → custom VM with ~80 opcodes

Event VM registers:
    - Unit IDs (0x00–0x0F)
    - Camera state (position, rotation, zoom)
    - Message buffer (dialogue text pointer)
    - Event flags (persistent state bits)
    - Stack (for subroutine calls)
```

We use this as a **hypothesis** for what TIC's system looks like, but we verify independently.

---

## iOS WotL Binary (Debug Symbols)

**Dicene (4/7/2026):**
> "An iOS binary was shared that has even more debug symbols than the Android release"
> "There are a LOT of gaps that it is filling in my IDB"
> "Like original formula names"

**URL**: `https://debugging.games/_files/iOS/[iOS] FINAL FANTASY TACTICS - THE WAR OF THE LIONS [v1.0.0].7z`

This binary contains original developer symbol names. If event functions are named (e.g., `EventManager::Execute`, `EventVM::Dispatch`), this would dramatically accelerate Phase 0.

**RE Action**: Download and cross-reference event-related symbols against our TIC IDB.

---

## Phase 0 RE Entry Points (Prioritized)

| # | Approach | Starting Point | Expected Yield |
|---|----------|---------------|----------------|
| 1 | **String search: "BATTLE"/"WORLD"** | IDB string xrefs | Find the overlay loader, adjacent to event dispatcher |
| 2 | **speaker.en.nxd consumers** | NXD table 37 xrefs | Trace from portrait/name display back to what feeds dialogue |
| 3 | **ffto_event_balloon.uib** | UIB string xrefs | Find the speech balloon renderer, trace back to text source |
| 4 | **iOS binary symbols** | Cross-reference | Get original function names for event VM |
| 5 | **FaithFramework Camera API** | Nenkai's code | Find camera control functions, adjacent to event camera commands |
| 6 | **TriggerHappy's battle hooks** | FFTGenericJobs sigs | Locate battle-phase code near event execution |
| 7 | **heretic/libfft opcode table** | PSX reference | Compare against TIC bytecode patterns |
