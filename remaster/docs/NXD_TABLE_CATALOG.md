# FFT:TIC — NXD Data Table Catalog

> Complete listing of all 245 NXD data tables in the game.
> Layout definitions from [Nenkai/fftivc-nex-layouts](https://github.com/Nenkai/fftivc-nex-layouts).
> Use `FF16Tools.CLI` with `-g fft` flag to extract/convert these tables.

---

## Quick Reference

```powershell
# Extract all tables from a PAC archive
FF16Tools.CLI pac-extract -i "$gameDir\data\enhanced\0002.pac" -o "extracts\0002"

# Convert NXD tables to SQLite for editing
FF16Tools.CLI nxd-to-sqlite -i "extracts\0002\nxd" -g fft

# Edit in SQLiteStudio, then convert back
FF16Tools.CLI sqlite-to-nxd -i "databases\tables.sqlite" -g fft
```

---

## Core Game Systems

### Character & Job System
| Table | Description |
|---|---|
| **Job** | Job class definitions (name, type, commands, egg link) |
| **JobCommand** | Command sets available per job |
| **JobType** | Job category classification |
| **GeneralJob** | Extended job parameters |
| **Ability** | All abilities — stats, costs, effects |
| **Chara** | Character template definitions |
| **CharaName** | Character name strings |
| **CharacterSortInfo** | Roster sorting parameters |
| **CharaControlId** | Character controller bindings |

### Items & Equipment
| Table | Description |
|---|---|
| **Item** | All items — name, category, sort order, damage type |
| **PoachItem** | Poaching reward item mapping |

### Battle System
| Table | Description |
|---|---|
| **Battle** | Battle encounter definitions |
| **BattleObjective** | Win/loss conditions per battle |
| **BattleEventOpcode** | Scripted battle event opcodes |
| **BattleSignal** | Battle event triggers |
| **ContinuousBattleTimeline** | Multi-stage battle sequences |
| **OverrideAbilityActionData** | Battle-specific ability overrides |
| **OverrideEntryData** | Battle-specific unit overrides |
| **DeepDungeon** | Deep Dungeon floor definitions |

### World & Navigation
| Table | Description |
|---|---|
| **Map** | Map/location definitions |
| **MapRouteTable** | Travel route connections |
| **MapVariationEvent** | Map event triggers |
| **MapVariationRandomBattle** | Random battle encounter tables per map |
| **Land** | Region/territory definitions |
| **LandscapeHeight** | Terrain height data |
| **Route** | Travel route definitions |
| **Town** | Town facility definitions |
| **TownImage** | Town visual assets |
| **PlaceName** | Location name strings |
| **WorldMapProgressInfo** | World map unlock progression |

### Story & Events
| Table | Description |
|---|---|
| **Chapter** | Chapter definitions |
| **ChapterFile** | Chapter-associated file paths |
| **EventId** | Event identifiers |
| **EventFlag** | Event state flags |
| **EventCharaDraw** | Character rendering during events |
| **EnhancedBattleEvent** | Enhanced-mode battle events |
| **EnhancedWorldEvent** | Enhanced-mode world events |
| **GameProgress** | Story progress tracking |
| **GameFlag** | Global game state flags |
| **ScenarioId** | Scenario identifiers |
| **SortieConfirm** | Pre-battle confirmation data |
| **ContinuousSortieConfirm** | Multi-battle sortie confirmations |
| **UserSituation** | Player situation state |
| **WorldSituationBalloon** | Map event speech bubbles |

### Achievements & Collection
| Table | Description |
|---|---|
| **Achievement** | Achievement definitions |
| **AchievementArray** | Achievement group arrays |
| **Collection** | Collectible item tracking |
| **ZodiacStone** | Zodiac stone collection |
| **ZodiacStoneOwnerTimeline** | Zodiac stone ownership history |

---

## Side Content

### BraveStory & Lore
| Table | Description |
|---|---|
| **Book** | In-game book entries |
| **Journal** | Journal entries |
| **Gossip** | Rumor/gossip entries |
| **Guide** | Guide page data |
| **GuideCategory** | Guide categories |
| **GuidePage** | Individual guide pages |
| **LoreDictionary** | Glossary/dictionary entries |
| **LoreDictionaryCategory** | Glossary categories |
| **LoreAffiliation** | Character faction affiliations |
| **LoreNameAlias** | Character name aliases |
| **BraveStoryVoice** | BraveStory voice data |

### Novels
| Table | Description |
|---|---|
| **Novel00–04** | Novel text data (5 novels) |
| **NovelIcon** | Novel illustration icons |

### Errands/Dispatches
| Table | Description |
|---|---|
| **Profit** | Errand/dispatch definitions |
| **ProfitBonusItem** | Bonus items from errands |
| **ProfitClientName** | Errand client names |
| **ProfitType** | Errand type classifications |
| **EntryArea** | Errand entry locations |
| **EntryNo** | Errand entry numbers |

---

## UI System

### Core UI
| Table | Description |
|---|---|
| **UI** | Base UI parameters |
| **UISystemParam** | UI system configuration |
| **UIColor** | UI color palette |
| **UIFontSet** | Font set definitions |
| **UIFontType** | Font type classifications |
| **UIDialog** | Dialog box definitions |
| **UIModal** | Modal popup definitions |
| **UIAnnounce** | Announcement display |
| **UIButton** | Button definitions |
| **UIButtonGuide** | Button guide displays |

### Menu System
| Table | Description |
|---|---|
| **UIMenuTab** | Menu tab definitions |
| **UIMenuButtonLeft** | Menu left panel buttons |
| **UIMenuSortList** | Menu sort options |
| **UISubMenu** | Submenu definitions |
| **UISubTab** | Sub-tab definitions |
| **UIItemCategory** | Item category display |

### Unit/Character UI
| Table | Description |
|---|---|
| **UIUnitStatusNumParam** | Unit status number display params |
| **UIEquipAbilitySlot** | Equipment/ability slot display |
| **UIEquipDetailNumParam** | Equipment detail number params |
| **UIAbilityIcon** | Ability icon mappings |
| **UIJobAbilityHelp** | Job ability help text |
| **UIStatusEffect** | Status effect display |
| **UIStatusEffectCategory** | Status effect categories |

### Input & Controls
| Table | Description |
|---|---|
| **UIKeyAssign** | Key assignment definitions |
| **UIKeyConfig** | Key configuration |
| **UIKeyDefine** | Key definitions |
| **UIKeyboardKeyIcon** | Keyboard key icons |
| **UIKeyboardLayout** | Keyboard layout |
| **UIKeyboardType** | Keyboard type |
| **UIMouseCollision** | Mouse collision areas |
| **UIPadDefine** | Gamepad button definitions |
| **UIPadGuide** | Gamepad button guides |

### Text & Subtitles
| Table | Description |
|---|---|
| **UISubtitles** | Subtitle text data |
| **UISubtitlesComponent** | Subtitle components |
| **UISubtitlesTimeline** | Subtitle timing |
| **UIClassicSubtitles** | Classic mode subtitles |
| **UISituationSubtitles** | Situation-based subtitles |
| **UISituationSubtitlesShowtime** | Subtitle display duration |

### Other UI
| Table | Description |
|---|---|
| **UIAddon** | UI addon system |
| **UIAddonPriority** | Addon priority ordering |
| **UIAttributive** | UI attribute display |
| **UIChronicleCharaList** | Chronicle character listing |
| **UIChroniclePeriod** | Chronicle time periods |
| **UICreditLineArt** | Credits line art |
| **UICreditRow** | Credits rows |
| **UIEndCredit** | End credits |
| **UIOpCredit** | Opening credits |
| **UITitleCredit** | Title credits |
| **UIFilePathExchange** | UI file path mapping |
| **UILoadTexturePath** | Texture loading paths |

---

## Audio & Visuals

### Sound
| Table | Description |
|---|---|
| **BGMMode** | BGM playback modes |
| **BGMTransition** | BGM transition rules |
| **Jingle** | Jingle/fanfare definitions |
| **SeadEvent** | Sound event definitions |
| **SeadStateParameter** | Sound state parameters |
| **SeDefine** | Sound effect definitions |
| **SeSystem** | System sound effects |
| **SoundEnhanced** | Enhanced mode sound parameters |
| **SoundEnhancedResource** | Enhanced sound resources |

### Voices
| Table | Description |
|---|---|
| **BattleVoice** | Battle voice line definitions |
| **BattleVoiceGroupRate** | Voice group probability |
| **AbilityReactionVoiceType** | Ability reaction voice types |
| **FacilityVoicePattern** | Facility voice patterns |
| **ShopVoice** | Shop voice lines |
| **Speaker** | Speaker definitions |
| **UnitVoice** | Unit voice line data |
| **VoicePattern** | Voice pattern definitions |
| **VoicePatternSituation** | Situational voice patterns |

### Messages
| Table | Description |
|---|---|
| **Caption** | Caption text |
| **CaptionFreeWord** | Free-form caption text |
| **SpellMessage** | Spell cast messages |
| **SubQuestMessage** | Sub-quest messages |
| **UnitBarProfitResultMessage** | Errand result messages |
| **UnitCommunMessage** | Unit communication |
| **UnitHelpMessage** | Unit help text |
| **UnitPartMessage** | Unit departure messages |
| **UnitWarnMessage** | Unit warning messages |
| **MessageWindowAnimationType** | Message animation types |
| **C_MES_ID_SAMPLE** | Message ID samples |

### Visual Effects & Rendering
| Table | Description |
|---|---|
| **PostEffect** | Post-processing effects |
| **PostEffectDepthLUT** | Depth LUT tables |
| **PostEffectDOF** | Depth of field parameters |
| **PostEffectGlare** | Glare effect parameters |
| **PostEffectLUT** | Color LUT tables |
| **Brightness** | Brightness settings |
| **DepthBias** | Depth bias parameters |
| **RefinedPermanentVFX** | Permanent VFX definitions |
| **RefinedVFXCameraControl** | VFX camera control |
| **RefinedVFXTexture** | VFX texture references |

### Character Rendering
| Table | Description |
|---|---|
| **CharAnimSeq0–7** | Character animation sequences (8 sets) |
| **CharaColorSkin** | Character skin color definitions |
| **CharaPartsDrawParam** | Character part draw parameters |
| **CharaZodiacStoneCLUT** | Zodiac stone color lookup |
| **CharCLUT** | Character color lookup tables |
| **CharMouseCollision** | Character mouse collision |
| **CharShape** | Character shape definitions |
| **CharShapeLUTParam** | Shape lookup parameters |
| **CharShapeShadowSize** | Character shadow sizes |
| **CharTacticalViewParam** | Tactical view parameters |

### Background Rendering
| Table | Description |
|---|---|
| **RefinedBgAnim** | Background animations |
| **RefinedBgMeshNode** | Background mesh nodes |
| **RefinedBgMeshNodeInvisType** | Invisible mesh types |
| **RefinedBgMeshPolygon** | Background mesh polygons |
| **RefinedBgMeshPolygonCond** | Polygon conditions |
| **RefinedBgSystemTexture** | Background system textures |
| **RefinedBgTexture** | Background textures |
| **RefinedBgUITexture** | Background UI textures |
| **RefinedBgUITextureFrames** | UI texture frame data |

---

## Configuration

### Settings
| Table | Description |
|---|---|
| **ConfigCategory** | Settings categories |
| **Configitem** | Individual settings |
| **ConfigItemButtonType** | Button type options |
| **ConfigItemCursorMoveType** | Cursor movement options |
| **ConfigItemDifficultyLevel** | Difficulty level options |
| **ConfigItemEnableDOF** | DOF toggle |
| **ConfigItemForwardEnabledType** | Forward movement options |
| **ConfigItemResolution** | Resolution options |
| **ConfigItemScreenMode** | Screen mode options |
| **ConfigItemTextLanguage** | Text language options |
| **ConfigItemVoiceLanguage** | Voice language options |
| **ConfigPadAssign** | Gamepad assignment |
| **ConfigPadList** | Gamepad listings |
| **CursorMoveType** | Cursor movement types |
| **DifficultyLevel** | Difficulty levels |
| **FloorCursorSpeed** | Floor cursor speeds |
| **ForwardEnabledType** | Forward movement types |
| **Resolution** | Resolution definitions |
| **ScreenMode** | Screen mode definitions |

### System
| Table | Description |
|---|---|
| **DLCPathList** | DLC file paths |
| **GameModeTypes** | Game mode definitions |
| **Icon** | Icon definitions |
| **IconGroup** | Icon group definitions |
| **Language** | Language definitions |
| **LauncherGuide** | Launcher help text |
| **LoadingSettings** | Loading screen settings |
| **MovieData** | FMV movie definitions |
| **Pause** | Pause menu data |
| **PSPMovieFile** | Classic PSP movie files |
| **ScionFiles** | Scion asset files |
| **ScionLabels** | Scion labels |
| **SystemParam** | System parameters |
| **Transition** | Scene transition data |
| **UDSActivity** | User activity tracking |
| **SystemBonusEntitlement** | System bonus entitlements |
| **SystemBonusItem** | System bonus items |
| **SystemBonusItemContents** | Bonus item contents |
| **SystemBonusSpecialItem** | Special bonus items |

### Telemetry
| Table | Description |
|---|---|
| **TelemetryAchievement** | Telemetry achievement tracking |
| **TelemetryAchievementGrade** | Achievement grade levels |
| **TelemetryEvent** | Telemetry events |
| **TelemetryEventDefinition** | Event definitions |
| **TelemetryObject** | Tracked objects |
| **TelemetryProperty** | Tracked properties |
| **TelemetryPropertyValue** | Property values |
| **TelemetryStat** | Statistical tracking |
| **TelemetryStatExtraction** | Stat extraction rules |

### Debug (Development)
| Table | Description |
|---|---|
| **DebugFIdG2D** | Debug 2D asset IDs |
| **DebugFIdSound** | Debug sound IDs |
| **DebugGameFlowSettings** | Debug game flow |
| **DebugMap** | Debug map selector |
| **DebugNovelPageDefine** | Debug novel pages |
| **DebugRefinedBgAnim** | Debug background animations |
| **DebugRefinedBgTexture** | Debug background textures |
| **DebugSceneSelect** | Debug scene selector |
| **DebugSceneSelectCategory** | Debug scene categories |

---

## Egg System
| Table | Description |
|---|---|
| **Egg** | Monster egg definitions (linked from Job table) |

---

*245 total tables • Layouts: [fftivc-nex-layouts](https://github.com/Nenkai/fftivc-nex-layouts) • Tooling: [FF16Tools v1.13.0](https://github.com/Nenkai/FF16Tools/releases)*
