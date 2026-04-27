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

**Status**: Not started  
**Objective**: Locate, decompile, and fully document the event bytecode interpreter in the TIC binary.

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

**Status**: Blocked on Phase 0  
**Objective**: Build command-line tools that can round-trip event data: binary → human-readable → binary.

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

**Status**: Blocked on Phase 1  
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

## Open Questions

1. **Is the TIC event bytecode a direct port of PSX/WotL, or was it rewritten for the FF16 engine?** This determines whether PSX opcode documentation transfers or we start from scratch. Phase 0 answers this.

2. **Are event scripts stored contiguously or scattered?** PSX stores all events in a single `TEST.EVT` file. TIC might distribute them across PAC files per-chapter.

3. **Can events be hot-loaded via the modloader?** If yes, we can offer live-reload during editing. If no, we need a restart-game workflow.

4. **Should we support PSX event import?** If the opcodes are compatible, modders could port PSX mod events to TIC. Huge community value if feasible.

5. **Who owns the map renderer?** TIC map data parsing is a separate RE challenge. We could ship Phase 2 without it and add Phase 3's preview later, or find someone already working on map data.

---

## Next Step

**Phase 0.1**: Find the event dispatcher in the TIC binary. Start from the `speaker.en.nxd` table consumers and the `ffto_event_balloon.uib` rendering code, trace backward to the function that feeds dialogue text into the display system. That function reads from the event bytecode.
