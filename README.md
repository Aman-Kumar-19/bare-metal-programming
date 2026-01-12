# Bare-Metal Programming Guide 🧠⚙️

A practical, step-by-step guide to **bare-metal firmware development**, written from real industry experience and implemented on **independent, NDA-safe hardware setups**.

This repository focuses on **how firmware actually works under the hood** — not just HAL usage.

---

## 🎯 Purpose of This Repository

- Build **strong bare-metal fundamentals**
- Explain *why* things work, not just *how*
- Create a reusable reference for:
  - MCU bring-up
  - Debugging
  - Register-level programming
- Share clean engineering workflows used in industry

> ⚠️ No proprietary or company-specific code is included.

---

## 🧱 Target Audience

- Embedded / firmware engineers
- ECE students transitioning to firmware roles
- Engineers preparing for **low-level embedded interviews**
- Anyone tired of copy-paste HAL code 😄

---

## 🧩 Hardware Platforms (Planned)

- PIC32CX (primary reference)
- STM32 (where concepts overlap)
- Generic Cortex-M concepts where applicable

> Concepts are MCU-agnostic unless explicitly stated.

---

## 📚 Planned Content Roadmap

### 1️⃣ MCU Boot & Startup
- Reset vector flow
- Startup code responsibilities
- Memory initialization (BSS / DATA)
- Role of linker script

### 2️⃣ Clock System
- Clock tree overview
- Internal vs external clocks
- PLL concepts
- Common clock misconfiguration bugs

### 3️⃣ Linker Script Fundamentals
- FLASH vs RAM layout
- Stack & heap placement
- Sections explained
- How linker scripts break firmware (and how to debug)

### 4️⃣ Register-Level Programming
- Reading datasheets effectively
- Bit masks, shifts, and ownership
- Safe register write patterns

### 5️⃣ Interrupts & NVIC
- Interrupt flow
- Vector tables
- Priority configuration
- Debugging interrupt issues

### 6️⃣ ADC Deep Dive
- Polling vs DMA
- Trigger sources
- Timing & accuracy pitfalls
- Debugging real ADC issues

### 7️⃣ Debugging Techniques
- Startup hangs
- Clock-related failures
- Peripheral not responding
- DMA & interrupt traps

### 8️⃣ Clean Firmware Architecture
- Folder structure
- Driver layering
- Naming conventions
- Scalable project layout

---

## 🛠️ How This Repo Is Structured

```text
bare-metal-programming-guide/
├── docs/              # Theory, explanations, diagrams
├── examples/          # Minimal working examples
├── notes/             # Debugging notes & lessons learned
├── tools/             # Scripts, helper utilities
└── README.md
