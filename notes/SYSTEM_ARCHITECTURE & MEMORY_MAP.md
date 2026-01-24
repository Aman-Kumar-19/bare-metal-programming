# What the System Architecture Really Means
The MCU consists of:
-A CPU core
- Memories (Flash, SRAM)
- Peripherals (GPIO, SERCOM, timers, etc.)
- All connected via address and data buses

📌 The CPU does not know peripherals by name — it only knows addresses.

---
## Memory-Mapped Peripheral Concept
When you write:
```
SERCOM7_REGS->USART_CTRLA = 0x01;
```
What actually happens:
- CPU places the register address on the bus
- CPU places data (0x01) on the data bus
- Write control signal asserted
- SERCOM hardware detects the address
- Hardware logic reacts

-  CPU never “calls” peripherals
-  CPU only reads/writes memory

--- 

## Typical Memory Map Regions


| Region       | Purpose |
|--------------|------|
| Flash | Program code |
| SRAM | Stack, heap, global variables |
| Peripheral region |  GPIO, SERCOM, timers |
| System region | NVIC, SysTick, core registers |

---

## Why This Matters in Bare-Metal
- Register access = pointer dereference
- Wrong address = undefined behavior
- No HAL safety net
- Understanding this = true firmware control


