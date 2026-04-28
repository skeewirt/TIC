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

## Confirmed NOT Working in Dialogue

These tags exist in the binary but render as **raw text** in dialogue balloons.
They may only work in other UI contexts (menus, tutorials, system text):

| Tag | Renders As | Likely Context |
|-----|-----------|----------------|
| `<color=RRGGBB>` | Raw `<color=ff0000>` | **Poisons the entire parser** — breaks all tags in same string |
| `<right>` | Raw `<right>` | May be menu/UI only |
| `<left>` | Raw `<left>` | May be menu/UI only |
| `<just>` | Raw (no close tag tested) | Justify — may need `</just>` or menu-only |
| `<xy=N,N>` | Raw `<xy=50,20>` | Dialogue balloons use opcode positioning instead |
| `<upperall>` | Raw | Case transform — localization pipeline only? |
| `<lowerall>` | Raw | Case transform — localization pipeline only? |
| `<head>` | Raw | Capitalize first — localization only? |
| `<headall>` | Raw | Title case — localization only? |
| `<keyicon>` | Raw | May need a parameter (e.g. `<keyicon=N>`) |
| `<date>` | Raw | System/menu text only? |
| `<time>` | Raw | System/menu text only? |

## Special Behavior

| Tag | Behavior |
|-----|----------|
| `<invisible>` | Does NOT hide text. Appears to create a **scrolling/traveling animation** effect — the tag text physically moves across the string. Bleeds across message boundaries. |
| `<cmt>` | Unknown — no visible effect observed |

## Key Rules

1. **`<color>` is TOXIC** — using `<color=...>` in a string breaks the tag parser for the ENTIRE string, causing all tags (even working ones like `<center>`, `<scale>`) to render as raw text.
2. **Tags that take `=value`**: Only `<scale=N>`, `<x=N>`, `<y=N>`, `<icon=N>`, and `<speaker="...">` are confirmed working with values.
3. **Positioning**: Use `<x=N>` for horizontal offset (works). Don't use `<xy>` (broken). Vertical positioning is controlled by the `DisplayMessage` opcode's Y-offset parameter.
4. **`<hero>` / `<player>`**: Work but resolve to blank until the player names their character. Would show the custom name in later scenes.
5. **Icon tags**: `<crossicon>` and `<upicon>` work and show keyboard glyphs. `<keyicon>` may require a parameter.

## Modder's Quick Reference

**Safe to use in dialogue:**
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

**DO NOT USE in dialogue:**
```
<color=anything>   ← breaks ALL tags in the string
<right>  <left>  <just>  <xy=N,N>
<upperall>  <lowerall>  <head>  <headall>
<keyicon>  <date>  <time>
```

## Binary Location

Tag lookup table: `FFT_enhanced.exe` at file offset `0x6F8140`
- 53 tag strings in a null-terminated array
- 4-byte aligned entries
- Followed by title-case stop words (`of`, `the`, `to`, `and`, etc.)

