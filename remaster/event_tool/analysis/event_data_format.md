# TIC Event Data Architecture

## Key Finding: Two-Layer Event System

TIC separates event data into two layers:

### Layer 1: Event Instructions (bytecode)
- **Source**: `eventid.nxd` (46KB, 887 entries)
- **Format**: Each entry is a 36-byte binary record with 9 x uint32 fields
- **Purpose**: Maps event ID → instruction data (unit movement, camera, branching, timing)
- **Enhancement**: `enhancedbattleevent.nxd` (196KB, 1283 entries) for TIC-only battle events
- **Enhancement**: `enhancedworldevent.nxd` (45KB) for TIC-only world events

### Layer 2: Event Text/Dialogue (PZD files)
- **Source**: `scionfiles.nxd` → 498 PZD file paths
- **Location**: `nxd/text/scenario/scenarioXXXX.pzd` (346 scenario files)
- **Format**: PZDF magic, UTF-8 text with HTML markup + voice file references (SAB)
- **Categories**: battlelines (40), battlevoice (79), facilitylines (37), movie (9), scenario (346), unitlines (66)
- **Engine type**: `DevEnv.Panzer.Models.Binary.Pzd.PzdFile` (FF16 "Panzer" framework)

### Layer 3: Event Scheduling
- `scenarioid.nxd` (10KB, 350 entries) - maps scenario IDs to event conditions
- `scionlabels.nxd` (67KB) - labels for cutscene timeline markers
- `gameprogress.nxd` (14KB) - story progress tracking
- `sortieconfirm.nxd` (21KB) - battle entry conditions

## What's Still Needed
1. **Extract the raw event data from the big PAC files** (0000.pac or 0003.pac) - we only have PAC 0008 extracted (UI)
2. **Parse the eventid.nxd 36-byte records** - need to map the 9 fields to the PSX event format
3. **Cross-reference eventid records with the WotL `event_maincommon` switch cases** to confirm opcode mapping

## Files on Disk
- `reference/nxd_extract/nxd/eventid.nxd` (46KB) - event instruction records
- `reference/nxd_extract/nxd/enhancedbattleevent.nxd` (196KB) - TIC-only events 
- `reference/nxd_extract_en/nxd/text/scenario/*.en.pzd` (346 files) - dialogue/text
- `Game_Files/wotl_extract/wotl_symbols_merged.json` (530KB) - 176 event symbol mappings
- `Game_Files/wotl_extract/psx_fft/BATTLE.BIN` (1.4MB) - PSX event reference
