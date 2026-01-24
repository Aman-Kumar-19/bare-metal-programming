# Why Clocks Are Fundamental
Clocks drive:
- CPU execution speed
- Peripheral timing
- Baud rates
- Timers

❌ No clock = nothing works

---

## Typical Clock Tree
- Internal oscillator
- External crystal
- PLL
- Generic clock generators
- Peripheral clock channels
  
Each peripheral:
- Needs a clock source
- Must be explicitly enabled

---

## Clock Enable Rule (COMMON BUG)
Peripheral registers may be:
- Writable
- But non-functional if clock is disabled

📌 Always:
1. Configure clock source
2. Enable peripheral clock
3. Configure peripheral
4. Enable peripheral

---

## Clock Impact on Debugging
Wrong clock causes:
- UART baud mismatch
- Timer drift
- Missed interrupts
- “Code looks right but doesn’t work”
