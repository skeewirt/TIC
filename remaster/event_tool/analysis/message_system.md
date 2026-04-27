# Message / Dialogue System

> How event scripts display dialogue, speech bubbles, and portraits.  
> Populated from decompiling the message pipeline functions.

---

## Pipeline

```
Event bytecode (dialogue opcode)
  → serchmessagepointer (0x14CDB69E1) — find text in message data
  → makemessagestructure (0x14D0F0640) — build display struct
  → makemessagepacket (0x1402DA28C) — construct render packet
  → drawmessagepolygons (0x14020BDE8) — render speech bubble
```

## NXD Tables

| Table | Global | Purpose |
|-------|--------|---------|
| `speaker` | `NEXTable_speaker` (`0x143CD3E98`) | Speaker portrait/name |
| `spellmessage` | `NEXTable_spellmessage` (`0x143CD3DD0`) | Spell incantation text |
| `caption` | `NEXTable_caption` (`0x143CD3E78`) | Caption display |

## Global State

| Address | Name | Purpose |
|---------|------|---------|
| `0x143CD37D8` | `pEventMessageResourceManager` | Message resource manager |
| `0x143CD3818` | `pMessageFrameManager` | Speech bubble frame manager |
| `0x143CD3828` | `pMessageGroupManager` | Message group manager |
| `0x143CD3840` | `pMessageBufferManager` | Text buffer manager |
| `0x143D13C50` | `aLastConverseMessage` | Last conversation text |

---

## Detailed Analysis

*Awaiting decompilation*
