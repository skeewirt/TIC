# Event Conditionals

> How the engine selects which event to run for a given story beat.  
> Populated from decompiling `ask_event` (`0x14022470C`).

---

## NXD Tables Involved

| Table | Global | Address | Role |
|-------|--------|---------|------|
| `eventid` | `NEXTable_eventid` | `0x143CD3DF8` | Event ID → script lookup |
| `scenarioid` | `NEXTable_scenarioid` | `0x143CD3FE0` | Scenario conditionals (chapter/progress) |
| `enhancedbattleevent` | `NEXTable_enhancedbattleevent` | `0x143CD42E8` | TIC-only battle events |
| `enhancedworldevent` | `NEXTable_enhancedworldevent` | `0x143CD4348` | TIC-only world events |
| `gameprogress` | `NEXTable_gameprogress` | `0x143CD3ED8` | Story progress flags |
| `sortieconfirm` | `NEXTable_sortieconfirm` | `0x143CD3E10` | Battle confirmation |

---

## Conditional Flow

*Awaiting `ask_event` decompilation*

```
ask_event(scenario_id, map_id?)
  → lookup NEXTable_scenarioid
  → check gameprogress flags
  → return event_id to execute
  → event_call(event_id)
```
