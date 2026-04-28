# FFT:TIC Text Tag Reference

> Extracted from `FFT_enhanced.exe` tag lookup table at `0x6F8140–0x6F8354`

## Complete Tag Table (53 tags)

All tags use XML-style syntax: `<tagname>`, `<tagname=value>`, or `</tagname>` to close.

### Text Formatting

| Tag | Category | Description | Used in PZD? |
|-----|----------|-------------|:---:|
| `<b>` | **Bold** | Bold text | ❌ Unused |
| `<i>...</i>` | **Italic** | Italic emphasis | ✅ 17 uses |
| `<left>` | Alignment | Left-justify (default) | ❌ Unused |
| `<center>...</center>` | Alignment | Center-justify text | ✅ 37 uses |
| `<right>` | Alignment | Right-justify text | ❌ Unused |
| `<just>` | Alignment | Full-justify (stretch) | ❌ Unused |
| `<color=?>` | **Color** | Change text color | ❌ Unused |
| `<scale=N>...<scale>` | **Size** | Scale text (1.4 = 140%) | ✅ 24 uses |
| `<xy=?,?>` | Position | Set X,Y position | ❌ Unused |
| `<x=?>` | Position | Set X position only | ❌ Unused |
| `<y=?>` | Position | Set Y position only | ❌ Unused |

### Icons & Graphics

| Tag | Category | Description | Used in PZD? |
|-----|----------|-------------|:---:|
| `<icon=N>` | Icon | Inline icon by ID | ✅ 2 uses |
| `<keyicon>` | Icon | Controller button icon | ❌ Unused |
| `<moveicon>` | Icon | Movement direction icon | ❌ Unused |
| `<moveicon2>` | Icon | Alt movement icon | ❌ Unused |
| `<cameraicon>` | Icon | Camera control icon | ❌ Unused |
| `<aimicon>` | Icon | Targeting/aim icon | ❌ Unused |
| `<crossicon>` | Icon | Cross/X button icon | ❌ Unused |
| `<upicon>` | Icon | Up arrow/D-pad icon | ❌ Unused |

### Dialogue System

| Tag | Category | Description | Used in PZD? |
|-----|----------|-------------|:---:|
| `<speaker="Name">` | Speaker | Override speaker name | ✅ 9 uses |
| `<hidespeaker>` | Speaker | Hide speaker name | ✅ 1 use |
| `<cursor>...<cursorend>` | Choice | Player dialogue choices | ✅ 6 uses |
| `<forced>` | Choice | Force-select choice | ✅ 6 uses |
| `<stoplip>` | Animation | Stop lip-sync animation | ✅ 20 uses |
| `<invisible>` | Display | Make text invisible? | ❌ Unused |
| `<sp>` | Spacing | Space/spacing control? | ❌ Unused |
| `<br>` | Break | Line break | ✅ 1 use |

### Dynamic Text Substitution

| Tag | Category | Description | Used in PZD? |
|-----|----------|-------------|:---:|
| `<ch>` | Variable | Character name? | ❌ Unused |
| `<hero>` | Variable | Player's hero name (Ramza) | ❌ Unused |
| `<player>` | Variable | Player name | ❌ Unused |
| `<date>` | Variable | Current in-game date | ❌ Unused |
| `<time>` | Variable | Current in-game time | ❌ Unused |
| `<subtitlestime>` | Variable | Subtitle timing marker | ❌ Unused |
| `<noset>` | Variable | No-set flag? | ❌ Unused |
| `<valset>` | Variable | Value-set flag? | ❌ Unused |
| `<jobname>` | Variable | Unit's job class name | ❌ Unused |
| `<jobhelp>` | Variable | Job description text | ❌ Unused |

### Text Case/Grammar (Localization)

| Tag | Category | Description | Used in PZD? |
|-----|----------|-------------|:---:|
| `<head>` | Case | Capitalize first letter | ❌ Unused |
| `<headall>` | Case | Capitalize all words | ❌ Unused |
| `<lower>` | Case | Lowercase | ❌ Unused |
| `<lowerall>` | Case | Lowercase everything | ❌ Unused |
| `<upperall>` | Case | UPPERCASE everything | ❌ Unused |
| `<disp>` | Display | Display control | ❌ Unused |
| `<hide>` | Display | Hide text | ❌ Unused |
| `<cmt>` | Comment | Comment (non-displayed?) | ❌ Unused |
| `<gen>` | Grammar | Gender marker? | ❌ Unused |
| `<ennoun>` | Grammar | English noun form | ❌ Unused |
| `<denoun>` | Grammar | German noun form | ❌ Unused |
| `<frnoun>` | Grammar | French noun form | ❌ Unused |
| `<esnoun>` | Grammar | Spanish noun form | ❌ Unused |
| `<janoun>` | Grammar | Japanese noun form | ❌ Unused |
| `<softold>` | Legacy | Legacy/compat tag? | ❌ Unused |
| `<->` | Grammar | Hyphen handling? | ❌ Unused |

### Title Case Stop Words (at end of table)

The table ends with common English stop words, likely used by `<headall>` for title-casing:
`of`, `the`, `to`, `and`, `a`, `an`, `or`, `at`, `by`, `for`, `in`, `on`, `with`, `from`

## Newly Discovered (Not in PZD Data)

These tags exist in the game engine but **none** of the 4,102 dialogue lines use them:

| Tag | Potential Use |
|-----|--------------|
| **`<b>`** | Bold text — standard formatting |
| **`<color=?>`** | Text color — value format unknown (hex? name?) |
| **`<right>`** | Right-align text |
| **`<just>`** | Full-justify text |
| **`<hero>`** | Dynamically insert player/hero name |
| **`<player>`** | Insert player name |
| **`<xy=?,?>`** / **`<x=?>`** / **`<y=?>`** | Position text at specific coordinates |
| **`<invisible>`** | Render invisible text (placeholder spacing?) |
| **`<keyicon>`** | Show controller button glyph |
| **`<cameraicon>`** | Show camera control glyph |
| **`<date>`** / **`<time>`** | Dynamic date/time display |
| **`<jobname>`** | Dynamic unit job class name |
| **`<head>`** / **`<headall>`** | Auto-capitalize |
| **`<upperall>`** / **`<lowerall>`** | Case transforms |

## Key Takeaways

1. **`<color=?>` exists** — color-changing text is supported by the engine
2. **`<b>` for bold** — available but never used in vanilla dialogue
3. **`<right>` and `<just>`** — additional alignment modes beyond center
4. **`<hero>`** — could dynamically insert the player's name
5. **`<xy>`, `<x>`, `<y>`** — pixel-level text positioning
6. **Icon system is rich** — `keyicon`, `moveicon`, `cameraicon`, `aimicon`, `crossicon`, `upicon`
7. **Localization system** — noun gender/form tags for EN/DE/FR/ES/JA

