# Event Opcode Table

> Maps every event instruction: opcode byte → handler function → parameters → behavior.  
> Populated from decompiling `set_event_table` (`0x1402F1E6C`).

---

## Battle Event Opcodes (`eventot` @ `0x140D3A430`)

| Opcode | Handler Address | Name | Params | Description |
|--------|----------------|------|--------|-------------|
| | | | | *Awaiting `set_event_table` decompilation* |

---

## World Event Opcodes (`weventot` @ `0x141843A08`)

| Opcode | Handler Address | Name | Params | Description |
|--------|----------------|------|--------|-------------|
| | | | | *Awaiting decompilation* |

---

## Notes

- PSX had ~80 unique opcodes across battle + world events
- TIC may have more (enhanced events) or the same set with new handler implementations
- Each entry in `eventot`/`weventot` is a function pointer to the handler
- `set_event_table` writes these pointers, so decompiling it gives us the complete map
