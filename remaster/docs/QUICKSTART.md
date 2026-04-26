# FFT: The Ivalice Chronicles — Modding Quick Start

## Prerequisites

1. **Game installed** via Steam (should land in the standard library path)
2. **Reloaded-II** mod manager — [download latest release](https://github.com/Reloaded-Project/Reloaded-II/releases)
3. **FF16Tools** — [download latest release](https://github.com/Nenkai/FF16Tools/releases)
4. **SQLiteStudio** — [download](https://sqlitestudio.pl) (for editing `.nxd` tables)

## First-Time Setup

### 1. Locate the Game

```
C:\Program Files (x86)\Steam\steamapps\common\FINAL FANTASY TACTICS - The Ivalice Chronicles\
```

Verify executables exist:
- `FFT_enhanced.exe` — Enhanced graphics mode
- `FFT_classic.exe` — Classic (PSX-style) mode

### 2. Configure Reloaded-II

1. Launch Reloaded-II
2. **Add Application** → browse to `FFT_enhanced.exe`
3. (Optionally repeat for `FFT_classic.exe`)
4. Download and enable the **fftivc.utility.modloader** mod from the Reloaded-II mod repository

### 3. Set Up FF16Tools

Place `FF16Tools.CLI.exe` somewhere on your PATH (e.g., `c:\Projects\TIC\tools\FF16Tools\`).

Verify it works:
```powershell
FF16Tools.CLI --help
```

> **Important:** Always use the `-g fft` flag when running FF16Tools commands against TIC files. Without it, the tool defaults to FFXVI layouts and will misinterpret the data.

---

## Core Workflows

### Exploring Game Data (Read-Only)

```powershell
# Pick a .pac file from the game directory to inspect
$gameDir = "C:\Program Files (x86)\Steam\steamapps\common\FINAL FANTASY TACTICS - The Ivalice Chronicles"

# Extract a pack archive
FF16Tools.CLI pac-extract -i "$gameDir\data\<archive>.pac" -o "c:\Projects\TIC\extracts\<archive>"

# Browse the extracted contents
Get-ChildItem "c:\Projects\TIC\extracts\<archive>" -Recurse | Select-Object FullName, Length
```

### Editing Database Tables

```powershell
# Convert .nxd files to SQLite
FF16Tools.CLI nxd-to-sqlite -i "c:\Projects\TIC\extracts\<archive>\path\to\nxd\dir" -g fft

# Open the resulting .sqlite file in SQLiteStudio
# Edit tables (items, jobs, abilities, stats, text...)

# Convert back to .nxd
FF16Tools.CLI sqlite-to-nxd -i "c:\Projects\TIC\databases\<name>.sqlite" -g fft
```

### Creating a Mod (.diff.pac)

```powershell
# After editing files in the extracted structure, repack as a diff overlay
FF16Tools.CLI pac-repack -i "c:\Projects\TIC\extracts\<modified_archive>" -o "c:\Projects\TIC\mods\my-mod\<archive>.diff.pac"
```

The `.diff.pac` file layers on top of the base archive at runtime — no original files are modified.

### Loading a Mod via Reloaded-II

1. Place your mod folder (containing the `.diff.pac`) under Reloaded-II's mod directory
2. Enable the mod in Reloaded-II
3. Launch the game through Reloaded-II

---

## What's Safe to Mod (Current Community Status)

| Area | Status | Notes |
|---|---|---|
| Item stats & properties | ✅ Working | Via `.nxd` table edits |
| Job/class data | ✅ Working | Via `.nxd` table edits |
| Ability data | ✅ Working | Via `.nxd` table edits |
| Text / localization | ✅ Working | Via `.nxd` string tables |
| Textures | ✅ Working | Replace in `.pac` archives |
| 3D Models | 🔬 Research | `.mdl` format partially documented |
| Audio | 🔬 Research | `.vatb` tooling in development |
| Collision data | 🔬 Research | `.ccb` format under investigation |

---

## Documentation Resources

- [FF16Tools Documentation](https://nenkai.github.io/FF16Tools/) — Table layouts, asset paths, ID formats
- [Reloaded-II Wiki](https://reloaded-project.github.io/Reloaded-II/) — Mod manager usage
- FFHacktics Discord — Live community research (most active hub)
- This workspace: `docs/` for our own research notes, `reference/` for community-sourced schemas

---

## Important Reminders

- ⚠️ **Always back up saves** before testing mods
- ⚠️ **Never modify executables** — all modding is data-level via `.diff.pac` overlays
- ⚠️ **Never commit extracted game assets** to version control (the `.gitignore` handles this)
- ⚠️ **anti-tamper is present** — the modding approach (Reloaded-II + mod loader + `.diff.pac`) works *alongside* DRM, not against it
