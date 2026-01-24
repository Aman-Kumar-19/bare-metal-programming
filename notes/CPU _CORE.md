# What the CPU Core Is

The CPU core:
- Fetches and executes instructions
- Does not understand GPIO / USART / I2C
- Only understands:
  - Instructions
  - Registers
  - Memory addresses

📌 Peripherals are external hardware, not CPU features.

----

## Programmer’s Model 

| Register	| Meaning	| Why it matters |
|-----------|---------|----------------|
|R0–R12	| General purpose	| Arguments, temp storage |
| SP	| Stack Pointer	| Function calls, locals |
| LR	| Link Register	| Return address |
| PC	| Program Counter	| Next instruction |
| xPSR	| Status register	| Flags, interrupt state |

----

## Program Counter (PC)
- Holds address of next instruction
- Auto-increments
- Modified by:
  - Branches
  - Function calls
  - Interrupts

👉 PC change = execution flow change

----

## Stack Pointer (SP)
Two stacks:
- MSP → used after reset & inside ISRs
- PSP → used by threads (RTOS)
Stack stores:
- Local variables
- Saved registers
- Return addresses

📌 Stack grows downward

⚠ Stack overflow → random crashes

---

## Link Register (LR)
- Stores return address on function call
- On ISR entry:
  - LR contains a special EXC_RETURN value
- CPU uses LR to exit ISR correctly

Explains why return; is meaningful even in void ISRs

---

## Reset Sequence
After reset:
1. SP loaded from vector table
2. PC loaded from reset vector
3. Reset handler executes
4. .data copied to RAM
5. .bss cleared
6. main() called

📌 You did not call main()

📌 CPU did
