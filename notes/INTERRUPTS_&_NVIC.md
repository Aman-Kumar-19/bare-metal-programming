# What Interrupts Really Are
Internally called exceptions.
Types:
- Reset
- HardFault
- SysTick
- Peripheral IRQs (USART, I2C, timers)

---

## Hardware Interrupt Entry Sequence
When an interrupt occurs:
- Current instruction completes
- Registers pushed to stack
- ISR address loaded into PC
- ISR executes
- Registers restored
- Execution resumes

📌 Entirely hardware-managed

---

## NVIC — Nested Vectored Interrupt Controller
NVIC handles:
- Interrupt enable/disable
- Priority
- Pending status
- Nesting
Key rules:
- Lower priority number → higher priority
- Supports preemption
- Vector table maps IRQ → ISR

---

## Why ISRs Must Be Short
Because:
- Main code is halted
- Stack usage increases
- Nested interrupts possible
- Timing becomes unpredictable
  
Correct design pattern:
```
ISR → capture event / set flag
Main loop → process data
```
---

## volatile (INTERRUPT REASON)
Hardware and ISRs can change variables without CPU knowledge.
```
volatile uint8_t rxHead;
```
Means:
- Always read from memory, never cache
📌 Mandatory for:
- ISR-shared variables
- Peripheral registers
- Hardware flags
