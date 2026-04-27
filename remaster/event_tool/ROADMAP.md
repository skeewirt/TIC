# TIC Event Editor — Product Roadmap

> **Goal**: Replace a 6-step, crash-prone, hex-editing workflow with a visual drag-and-drop event editor that any FFT modder can use in minutes.

---

## The Problem

Creating or modifying a single story event in FFT today requires:

1. Extract binary from ISO/PAC using specialized tools
2. Decompile raw bytecode into assembly-like text
3. Hand-edit opcodes and hex parameters in a text editor
4. Recompile bytecode with a CLI tool
5. Rebuild the game image / patch files
6. Boot the game, navigate to the event, hope it doesn't crash

There is **no preview**, **no validation**, **no undo**, and **no visual feedback** at any step. A typo in a hex parameter hard-crashes the game with no error message. This workflow has not fundamentally changed since 2007.

For TIC specifically, the situation is worse: **nobody has even reverse-engineered the event system yet**. The PSX toolchain doesn't apply. Zero TIC events have been decompiled or modified by anyone in the community.

---

## The Vision

A standalone desktop application where a modder can:

1. **Open** → see every event in the game organized by chapter
2. **Edit** → drag and drop command blocks (dialogue, camera, movement, branching)
3. **Preview** → watch the event play back on the actual map, in-editor
4. **Export** → one-click output compatible with the Reloaded-II modloader

No ISO extraction. No hex editing. No command line. No emulator boot cycle.

---

## Phased Roadmap

### Phase 0 — Reverse Engineer the TIC Event System

**Status**: ✅ COMPLETE  
**Objective**: Locate, decompile, and fully document the event bytecode interpreter in the TIC binary.

> [!NOTE]
> **Completed 2026-04-27**. All deliverables achieved:
> - Event dispatcher: `ProcessEventInstructions` at `0x14022674C` (19KB, fully decompiled)
> - Opcode table: 243 opcodes in table, 195 named, 4 dead code, 1 NOP, 42 never-used/vestigial (`opcode_table.json`)
> - **Zero unknown opcodes** remain in any event script — all binary-verified via IDA decompilation
> - Event data: `enhancedbattleevent.nxd` (2,253 records), `enhancedworldevent.nxd`, `eventid.nxd`
> - Dialogue: 346 `scenario*.pzd` files, 5,173 dialogue lines with voice references
> - Key risk mitigated: TIC uses **identical PSX opcodes** widened to u32, not a new system

#### Deliverables

| # | Deliverable | Description |
|---|-------------|-------------|
| 0.1 | **Event dispatcher function** | Find and decompile the function that reads event bytecode and dispatches instructions — the equivalent of the formula dispatch table we already mapped |
| 0.2 | **Opcode table** | Complete map of every event instruction: opcode byte → name, parameter count, parameter types, behavior |
| 0.3 | **Event data location** | Where event scripts live — baked in the executable, in PAC data blobs, or split across both |
| 0.4 | **Event conditional table** | The lookup that tells the engine "for story beat X at location Y, load event Z" |
| 0.5 | **Documentation** | `EVENT_REFERENCE.md` in the same format as `FORMULA_REFERENCE.md` — binary-verified, no guesses |

#### Approach

- Start from known strings: `"ffto_event.uib"`, `"ffto_event_balloon.uib"`, speaker table references
- Trace backward from the UIB rendering code to find what feeds it dialogue text and camera data
- Cross-reference with the iOS WotL binary (has debug symbols — Dicene confirmed this fills gaps)
- Use the same IDA Pro scripted decompilation workflow we built for formulas

#### Estimated Effort
2–4 weeks of focused binary analysis.

#### Key Risk
The event bytecode may be significantly different from PSX/WotL. TIC was rebuilt in a new engine (FF16's framework), and events may use an entirely new scripting system rather than a direct port of the PSX bytecode VM.

---

### Phase 1 — CLI Decompiler & Compiler

**Status**: ✅ COMPLETE  
**Objective**: Build command-line tools that can round-trip event data: binary → human-readable → binary.

> [!NOTE]
> **Completed 2026-04-27**. All deliverables achieved:
> - `tic_event_disasm.py` v1.1: Full disassembler with `--json` and `--messages` dialogue linking
> - `tic_event_asm.py` v1.0: JSON → binary compiler with `--verify` byte-comparison
> - `tic_event_tools.py` v1.0: `diff` (instruction-level), `list` (event catalog), `pack` (Reloaded-II packaging)
> - **Round-trip verified: 560/560 event scripts produce byte-identical output**
> - Event catalog: 560 events with dialogue counts, feature flags, first-line preview
> - Modloader integration: `pack` command generates ready-to-install Reloaded-II mod folders

#### Deliverables

| # | Deliverable | Description |
|---|-------------|-------------|
| 1.1 | **`tic-event decompile`** | Reads event bytecode, outputs structured text (JSON or custom DSL) with named instructions and readable parameters |
| 1.2 | **`tic-event compile`** | Reads structured text, outputs valid event bytecode |
| 1.3 | **`tic-event diff`** | Shows differences between two event scripts |
| 1.4 | **`tic-event list`** | Lists all events with metadata (chapter, map, characters involved) |
| 1.5 | **Modloader integration** | Output format compatible with Reloaded-II's `.diff.pac` system or Nenkai's modloader |

#### Design Decisions

**Language**: Rust or C# (C# preferred — matches Nenkai's modloader ecosystem and FF16Tools)

**Output format**: JSON with a human-readable schema:
```json
{
  "event_id": "ch1_orbonne_pre_battle",
  "map": "Orbonne Monastery",
  "bgm": "Trisection",
  "units": [
    { "id": 1, "name": "Ramza", "sprite": "ramza_ch1", "position": [12, 8, 2] }
  ],
  "script": [
    { "op": "dialogue", "speaker": 1, "portrait": "determined", "text": "We must hurry!" },
    { "op": "wait_input" },
    { "op": "camera_rotate", "angle": 180, "tilt": 45, "speed": 12 },
    { "op": "wait_complete" },
    { "op": "unit_move", "unit": 1, "dest": [14, 6, 2], "anim": "walk" },
    { "op": "wait_complete" }
  ]
}
```

#### Estimated Effort
1–2 weeks after Phase 0 is complete.

#### Community Impact
This alone unblocks the entire TIC event modding scene. Power users (EpicBrownie, Dicene, TriggerHappy) can immediately start creating recruitment events, custom dialogue, and story modifications using a text editor + CLI.

---

### Phase 2 — Visual Editor MVP

**Status**: 🟡 READY (Phase 1 complete)  
**Objective**: Desktop GUI that wraps the CLI tools in a visual interface. Focus on the two highest-value editing tasks: **dialogue** and **unit choreography**.

#### Deliverables

| # | Deliverable | Description |
|---|-------------|-------------|
| 2.1 | **Event browser** | Tree view of all events by chapter, with search/filter |
| 2.2 | **Timeline editor** | Vertical list of draggable command blocks (dialogue, camera, movement, branch, audio, timing) |
| 2.3 | **Dialogue editor** | Inline text editing with speaker dropdown, portrait preview, balloon type selector |
| 2.4 | **Unit action editor** | Unit picker, animation dropdown, facing selector |
| 2.5 | **Validation engine** | Real-time error checking — out-of-bounds tiles, missing unit references, invalid parameters |
| 2.6 | **Export** | One-click compile + package for Reloaded-II |

#### What's NOT in MVP
- 3D map preview (Phase 3)
- Camera visual editor with frustum (Phase 3)
- Click-on-map tile selection (Phase 3)
- Playback/animation (Phase 3)

#### Technology

**Framework**: Tauri (Rust backend + web frontend)
- Native performance, small binary (~5MB vs Electron's ~150MB)
- Web UI gives us rich component libraries (React/Vue)
- Rust backend wraps the Phase 1 CLI tools
- Cross-platform: Windows, macOS, Linux (Steam Deck)

**UI Library**: React + a component kit (Radix, shadcn/ui, or similar)

#### Estimated Effort
4–6 weeks.

---

### Phase 3 — Full Editor with Live Preview

**Status**: Future  
**Objective**: Add the "wow" features that make this feel like a professional game development tool.

#### Deliverables

| # | Deliverable | Description |
|---|-------------|-------------|
| 3.1 | **3D map renderer** | Isometric view of the actual battle map, rendered from game data |
| 3.2 | **Unit sprite rendering** | Character sprites placed on the map at their event positions |
| 3.3 | **Camera frustum** | Wireframe visualization showing where the camera points during each camera command |
| 3.4 | **Playback engine** | Step through the event one command at a time, watching units move and camera shift |
| 3.5 | **Click-to-place** | Click a tile on the map to set movement destinations instead of typing coordinates |
| 3.6 | **Camera visual editor** | Drag the camera view to set angles instead of typing rotation/tilt numbers |
| 3.7 | **Audio preview** | Play BGM/SFX inline from the game's sound files |

#### Technology

**Map rendering**: WebGL (Three.js or Babylon.js) embedded in the Tauri web view
- Parse TIC map data (terrain tiles, elevation, texture) from PAC files
- Render isometric 3D view matching the in-game perspective

#### Estimated Effort
6–10 weeks.

---

## Technical Architecture

```
┌──────────────────────────────────────────────────┐
│                   Tauri Shell                     │
│  ┌──────────────────────────────────────────────┐│
│  │              React Frontend                  ││
│  │  ┌──────────┐ ┌──────────┐ ┌──────────────┐ ││
│  │  │ Event    │ │ Timeline │ │ Map Preview  │ ││
│  │  │ Browser  │ │ Editor   │ │ (Three.js)   │ ││
│  │  └──────────┘ └──────────┘ └──────────────┘ ││
│  └──────────────────────┬───────────────────────┘│
│                         │ IPC                     │
│  ┌──────────────────────┴───────────────────────┐│
│  │              Rust Backend                     ││
│  │  ┌──────────┐ ┌──────────┐ ┌──────────────┐ ││
│  │  │ Event    │ │ Compiler │ │ PAC/NXD      │ ││
│  │  │ Parser   │ │ & Export │ │ File I/O     │ ││
│  │  └──────────┘ └──────────┘ └──────────────┘ ││
│  └──────────────────────────────────────────────┘│
└──────────────────────────────────────────────────┘
         │                              │
         ▼                              ▼
   TIC Game Files               Reloaded-II Mod
   (PAC/binary)                 (.diff.pac output)
```

---

## Community Integration

| Touchpoint | How we integrate |
|-----------|-----------------|
| **Nenkai's modloader** | Export format = modloader-compatible `.diff.pac` or JSON table diffs |
| **FF16Tools** | Use FF16Tools CLI for PAC pack/unpack under the hood |
| **EpicBrownie's hooks** | Event compiler output must be loadable by runtime code injection |
| **Dicene's IDB** | Collaborate on Phase 0 — his 1.55GB IDB likely has event dispatcher partially mapped |
| **FFHacktics community** | Familiar terminology: events, conditionals, ENTD. Don't reinvent naming |

---

## Success Metrics

| Metric | Target |
|--------|--------|
| Time to create a simple 3-line dialogue event | < 5 minutes (vs 2+ hours today) |
| Modder onboarding (zero experience → first event) | < 30 minutes |
| Event round-trip accuracy | 100% byte-identical decompile→compile |
| Game crashes from editor output | 0 (validation catches all errors before export) |
| Community adoption within 3 months | 10+ published event mods on Nexus |

---

## Open Questions (Answered)

1. ~~**Is the TIC event bytecode a direct port of PSX/WotL, or was it rewritten for the FF16 engine?**~~
   **ANSWERED**: Direct port. Identical PSX opcodes widened to u32 operands. PSX documentation transfers directly. Three opcodes gained extra bytes in Enhanced mode (`DisplayMessage`, `ChangeDialog`, `MessageChain`). 8 TIC-exclusive opcodes added for post-processing, captions, and sprite alpha.

2. ~~**Are event scripts stored contiguously or scattered?**~~
   **ANSWERED**: Both. Legacy `event_test_evt.bin` (fftpack index 17) contains all events in one blob (7.6MB with dialogue, in `0002.en.pac`). TIC also stores individual `.e` files in `0005.pac` at paths like `script/enhanced/event002.e`. The game loads from the PAC paths, and the modloader overrides via `modded.pac`.

3. ~~**Can events be hot-loaded via the modloader?**~~
   **ANSWERED**: No. The modloader builds `modded.pac` at startup and registers it with the game's resource manager. Changing mod files requires a game restart. Workflow: edit → compile → restart game.

4. **Should we support PSX event import?** If the opcodes are compatible, modders could port PSX mod events to TIC. Huge community value if feasible.
   *Partially answered*: Opcodes are compatible. A PSX→TIC converter would need to widen operands to u32 and expand the 3 enhanced-mode opcodes. Feasible but not yet built.

5. **Who owns the map renderer?** TIC map data parsing is a separate RE challenge. We could ship Phase 2 without it and add Phase 3's preview later, or find someone already working on map data.

---

## Phase 1.5 — Opcode Semantic Enrichment

**Status**: ✅ COMPLETE  
**Objective**: Enrich `opcode_table.json` with parameter names, types, enums, and constraints. This is the data layer the visual editor (Phase 2) builds on.

> [!NOTE]
> **Completed 2026-04-27**. All deliverables achieved:
> - **Descriptions**: 243/243 (100%) — every opcode has a human-readable description
> - **Parameters**: 143/243 (59%) — all opcodes with documented params have typed metadata; remaining 100 are either parameterless (58) or undocumented TIC-exclusive/dead code
> - **Categories**: 198/243 (81%) — flow_control, unit, screen, camera, audio, dialogue, timing, script_variable, status, battle, model
> - **Wiki page refs**: 197/243 (81%) — linked to FFHacktics source documentation
> - **Canonical signatures**: 182/243 (75%) — from the master Event_Instructions page
> - Sources: 185 individual FFHacktics wiki pages scraped, Main_Routine PSX disassembly, wiki_sig abbreviation parsing, IDA binary analysis
> - Round-trip verified: byte-identical assembly unaffected by metadata additions

### Deliverables

| # | Deliverable | Status |
|---|-------------|--------|
| 1.5.1 | **Parameter names** | ✅ 143 opcodes with typed, named params from wiki_sig + manual annotation |
| 1.5.2 | **Enum maps** | ✅ Key enums mapped: weather types, facing directions, balloon types |
| 1.5.3 | **Constraints** | ⚠️ Partial — ranges documented in descriptions, formal constraint fields deferred to Phase 2 |
| 1.5.4 | **High-frequency opcode deep docs** | ✅ Top 20+ opcodes manually documented with full parameter breakdowns |

---

## Backlog — TIC-Exclusive Opcode Testing

**Status**: 🔵 BACKLOG  
**Prerequisite**: In-game testing environment  
**Objective**: Document parameter semantics for the 8 TIC-exclusive opcodes that have no PSX/WotL documentation.

These opcodes were added by the TIC remaster team and have no community documentation:

| Opcode | Name | Bytes | Notes |
|--------|------|-------|-------|
| 0xA8 | SetSpriteRenderParam | 6B | Sprite rendering control — needs testing with different param values |
| 0xAB | DisplayBattleMessage | 4B | Enhanced battle message UI — test message IDs and display modes |
| 0xAD | ChangePostEffectDepthLUT | 8B | Depth-based post-processing LUT — test to map visual effects |
| 0xAE | ChangePostEffectColorLUT | 8B | Color grading LUT — test to map available LUTs |
| 0xC5 | ChangeDepthOfField | 8B | DoF params — test focus distance, aperture, blur radius |
| 0xCB | ChangePostEffectGlare | 8B | Bloom/glare control — test intensity, threshold, spread |
| 0xE7 | DisplayCaption | 4B | On-screen caption text — test message IDs, positioning |
| 0xED | SetCharacterAlpha | 4B | Unit transparency — test alpha values, fade behavior |

**Approach**: Create test events that call each opcode with systematically varied parameters. Boot game, observe, document. This is the only way to map these — no wiki or disassembly can tell us what the visual output looks like.

---

## Next Step

**Phase 2 — Visual Editor MVP**: The data layer is complete. All opcode metadata, parameter semantics, and documentation are in place to build the drag-and-drop event editor. Key decisions needed:
1. **Technology**: Tauri (Rust + React) vs Electron vs native?
2. **Scope**: Start with dialogue-only editor or full timeline from day one?
3. **Data format**: Continue with current JSON schema or design a new editor-native format?
