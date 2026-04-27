# Event VM State

> Documents the event virtual machine: registers, stack, memory layout.  
> Populated from decompiling `event_init_memory` (`0x1402E578C`) and `eventwork` (`0x140D39C60`).

---

## VM Memory Layout (`eventwork` @ `0x140D39C60`)

| Offset | Size | Name | Description |
|--------|------|------|-------------|
| | | | *Awaiting decompilation* |

---

## Event Buffer (`eventbuffer` @ `0x140D37460`)

- Where event bytecode is loaded for execution
- Size: TBD
- Format: TBD (raw bytecode? structured blocks?)

---

## Event Flags

- Read via `read_eventflag` (`0x14021F2E0`)
- Written via `write_eventflag` (`0x14021F360`)
- Persistent across saves (story progress tracking)
- Total flag count: TBD
