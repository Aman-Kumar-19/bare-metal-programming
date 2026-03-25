# 🧠⚙️ Bare-Metal Programming

A practical, industry-oriented guide to **bare-metal firmware development**, focused on understanding **how embedded systems actually work under the hood**.

> ⚡ No abstraction-heavy shortcuts. No blind HAL usage. Just real firmware engineering.

---

## 🚀 What This Repository Teaches

This repository is designed to help you:

* Build **strong low-level fundamentals**
* Understand **what happens before `main()`**
* Write **clean, scalable firmware**
* Debug **real-world embedded issues**
* Think like a **firmware engineer — not just a coder**

---

## 🧱 Target Audience

* Embedded / Firmware Engineers
* ECE students transitioning to firmware roles
* Engineers preparing for **low-level embedded interviews**
* Developers who want to move beyond **copy-paste HAL usage**

---

## 🧩 Hardware Platforms

* PIC32CX (primary reference)
* STM32 (concept mapping)
* Generic Cortex-M architecture

> Most concepts are **MCU-agnostic** unless explicitly stated.

---

## 🧠 Boot Flow — From Reset to `main()`

Before your firmware runs, the MCU executes a precise sequence of **hardware + startup logic**.

### 🖼️ Overview

![Boot Flow](notes/images/boot_flow.png)

---

### ⚡ Execution Flow

```
RESET
  ↓
Vector Table Read
  ↓
Reset_Handler
  ↓
SystemInit()
  ↓
Memory Init (.data / .bss)
  ↓
C Runtime Setup
  ↓
main()
```

---

### 💡 Key Insight

> **`main()` is NOT the entry point.**
> Execution begins at **Reset_Handler**, controlled directly by hardware.

👉 Deep dive:

* [`notes/BOOT_FLOW.md`](notes/BOOT_FLOW.md)
* [`notes/RESET_TO_MAIN_FLOW.md`](notes/RESET_TO_MAIN_FLOW.md)

---

## 📚 Technical Content Roadmap

### 1️⃣ MCU Boot & Startup

* Reset vector flow
* Startup code responsibilities
* Memory initialization (`.data`, `.bss`)
* Linker script interaction

---

### 2️⃣ Clock System

* Clock tree architecture
* Internal vs external clocks
* PLL configuration
* Real debugging cases

---

### 3️⃣ Linker Script Fundamentals

* FLASH vs RAM layout
* Section mapping
* Stack & heap placement
* Debugging linker-related issues

---

### 4️⃣ Register-Level Programming

* Reading datasheets effectively
* Bit manipulation techniques
* Safe register write patterns

---

### 5️⃣ Interrupts & NVIC

* Interrupt execution flow
* Vector table mapping
* Priority configuration
* Debugging interrupt failures

---

### 6️⃣ ADC Deep Dive

* Polling vs DMA
* Trigger sources
* Accuracy and timing issues
* Real debugging scenarios

---

### 7️⃣ Debugging Techniques

* Startup failures (before `main()`)
* Clock-related bugs
* Peripheral failures
* DMA and interrupt traps

---

### 8️⃣ Clean Firmware Architecture

* Layered design (App → Drivers → Hardware)
* Driver abstraction principles
* Scalable folder structure
* Maintainable coding practices

---

## 🛠️ Repository Structure

```
bare-metal-programming-guide/
├── drivers/               # Register-level peripheral drivers
│   ├── gpio/
│   ├── timer_counter/
│   ├── sercom_drv/
│   ├── i2c_drv/
│   └── rtc_timer_drv/
│
├── examples/              # Minimal, focused application examples
│   ├── gpio_blink/
│   └── sercom7_usart_echo/
│
├── notes/                 # Deep technical explanations
│   ├── BOOT_FLOW.md
│   ├── RESET_TO_MAIN_FLOW.md
│   ├── CLOCK_SYSTEM.md
│   ├── CPU_CORE.md
│   ├── INTERRUPTS_&_NVIC.md
│   ├── SYSTEM_ARCHITECTURE_&_MEMORY_MAP.md
│   ├── debugging-peripherals.md
│   ├── nvram-manager.md
│   └── Can_Bus–Bare-metal_Learning_Notes.md
│
├── tools/                 # Diagrams, helper scripts, utilities
└── README.md
```

---

## ⚙️ Drivers (Register-Level Design)

All drivers are:

* Implemented using **direct register access**
* Designed for **clarity and reuse**
* Structured for **scalable firmware systems**

### Example APIs

```c
gpio_configure_pin();
gpio_write_high();
gpio_write_low();
```

---

## 📂 Examples

### 🔹 GPIO Blink

**Location:**
`examples/gpio_blink/main.c`

**Demonstrates:**

* Driver-based GPIO configuration
* Clean application-to-driver interaction
* Hardware validation using simple delay

---

### 🔹 USART Echo

**Location:**
`examples/sercom7_usart_echo/main.c`

**Demonstrates:**

* Serial communication
* Peripheral initialization
* Data flow validation

---

## 🧠 Engineering Philosophy

This repository follows **real firmware engineering principles**:

* Clear separation of layers:

  * Application
  * Drivers
  * Hardware
* Minimal abstraction — maximum clarity
* Debug-first mindset
* Readability over cleverness

---

## ⚠️ Problems This Repository Helps You Solve

* Code not reaching `main()`
* Clock misconfiguration issues
* Interrupts not triggering
* Peripheral failures
* Memory corruption bugs

---

## 🔬 Real-World Relevance

These concepts directly apply to:

* Automotive ECUs
* Industrial control systems
* IoT devices
* Telematics platforms

---

## 🛠️ Future Enhancements

* Startup code (`startup.s`) breakdown
* Linker script deep dive
* DMA and advanced peripherals
* RTOS vs Bare-metal comparison
* Real debugging case studies

---

## 🤝 Contributing

Contributions are welcome if they:

* Improve clarity
* Add real debugging insights
* Follow clean firmware practices

---

## ⭐ Support

If this repository helped you, consider giving it a ⭐

---

## 📌 Final Thought

> Bare-metal programming is not about writing code.
> It’s about **understanding how the machine truly works**.
