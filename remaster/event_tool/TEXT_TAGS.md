# FFT:TIC Text Tag Reference

> Extracted from `FFT_enhanced.exe` tag lookup table at `0x6F8140–0x6F8354`
> **In-game verified** against Orbonne Monastery intro (scenario0010, event002)

## Verified Working Tags

These tags are confirmed functional in dialogue balloons:

| Tag | Effect | Notes |
|-----|--------|-------|
| `<b>...</b>` | **Bold text** | Entire region rendered bold |
| `<i>...</i>` | *Italic text* | Confirmed working |
| `<center>...</center>` | Center-justify | Used in vanilla (37 lines) |
| `<scale=N>...<scale>` | Scale text size | 0.8 = smaller, 1.4 = narrator, 2.0 = huge (clips top) |
| `<x=N>` | X-axis offset | Shifts text horizontally |
| `<speaker="Name">` | Override speaker name | Shows custom name on balloon |
| `<hidespeaker>` | Hide speaker name | No name plate shown |
| `<stoplip>` | Stop lip-sync | Prevents mouth animation |
| `<icon=N>` | Inline icon | `101` = zodiac mark, `102` = symbol |
| `<crossicon>` | WASD/action icons | Shows keyboard control glyphs |
| `<upicon>` | Up/W key icon | Shows "W" key glyph |
| `<hero>` | Player's hero name | **Works** but blank until name is set (Chapter 1 naming screen) |
| `<player>` | Player name | Same as `<hero>` — blank before naming |
| `<br>` | Line break | Used in vanilla (1 line) |

## NXD-Only Tags (NOT available in dialogue)

These tags work in **NXD UI text** (menus, guides, item descriptions) but render as **raw literal text** in PZD dialogue balloons. The game has **two separate text renderers** — the NXD renderer supports all 53 tags, while the PZD dialogue renderer only supports the 14 above.

| Tag | NXD Usage | Why It Fails in Dialogue |
|-----|-----------|-------------------------|
| `<color=N>` | 438 uses across 5 NXD files | Dialogue renderer has no color palette lookup |
| `<left>` | 1 use in `ui.en.nxd` (Job EXP display) | Balloon alignment set by opcode, not tag |
| `<right>` | Never used in any file | Same — opcode controls alignment |
| `<just>` | Never used in any file | Same |
| `<xy=N,N>` | Never used in any file | Use `<x=N>` instead (that works) |
| `<moveicon>` | 1 use in `guidepage.en.nxd` | Tutorial UI only |
| `<upperall>` | Never used in any file | Localization build-time transform |
| `<lowerall>` | Never used in any file | Localization build-time transform |
| `<head>` / `<headall>` | Never used in any file | Localization build-time transform |
| `<keyicon>` | Never used in any file | May need param, or tutorial-only |
| `<date>` / `<time>` | Never used in any file | Likely debug/dev tags |
| `<invisible>` | Never used in any file | Not implemented in either renderer |

### `<color>` Syntax (NXD Only)

Color values are **palette indices** or **named constants**, NOT hex RGB:

```
<color=100>highlighted text</color>    ← palette index
<color=151>Range:</color>               ← item stat highlight
<color=111>Rainy</color>                ← weather type color
<color=guide_notice>text</color>        ← named constant
<color=critical_damage>text</color>     ← named constant
```

### Why `<invisible>` "Travels"

The "traveling" effect is the **dialogue typewriter animation** progressively revealing the raw `<invisible>` characters. Since the dialogue renderer doesn't recognize the tag, it renders it as literal text, and the normal character-by-character display animation makes the raw tag text appear to "move" across the screen.

## Key Rules

1. **`<color>` is NXD-only** — the dialogue renderer doesn't have a color palette. Using it causes the entire string to render as raw text (parser fallback).
2. **Tags that take `=value`**: Only `<scale=N>`, `<x=N>`, `<y=N>`, `<icon=N>`, and `<speaker="...">` are confirmed working with values in dialogue.
3. **Positioning**: Use `<x=N>` for horizontal offset (works). Don't use `<xy>` (NXD-only). Vertical positioning is controlled by the `DisplayMessage` opcode's Y-offset parameter.
4. **`<hero>` / `<player>`**: Work but resolve to blank until the player names their character (first naming screen). Will show the custom name in later scenes.
5. **Icon tags**: `<crossicon>` and `<upicon>` work and show keyboard glyphs. `<keyicon>` is NXD-only.

## Modder's Quick Reference

**Safe to use in PZD dialogue:**
```
<b>bold text</b>
<i>italic text</i>
<center>centered text</center>
<scale=1.4>bigger text<scale>
<scale=0.8>smaller text<scale>
<x=50>offset text
<speaker="Custom Name">dialogue
<hidespeaker>anonymous dialogue
<stoplip>...
<icon=101>
<crossicon>
<upicon>
<hero>
<br>
```

**NXD UI text only (NOT dialogue):**
```
<color=100>palette color</color>     ← palette index or named constant
<color=critical_damage>red</color>   ← named constant
<left>  <right>  <just>  <xy=N,N>
<upperall>  <lowerall>  <head>  <headall>
<moveicon>  <keyicon>  <date>  <time>
```

## Binary Location

Tag lookup table: `FFT_enhanced.exe` at file offset `0x6F8140`
- 53 tag strings in a null-terminated array
- 4-byte aligned entries
- Followed by title-case stop words (`of`, `the`, `to`, `and`, etc.)

