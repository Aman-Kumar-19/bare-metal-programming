# Debugging Peripherals (UART / I2C) in VS Code

This guide explains **how to debug embedded peripherals** such as UART and I2C using **VS Code** and a standard development environment for microcontrollers (e.g., Arduino, ESP32, PIC32CX).

---

## 1. Prerequisites

Before starting, ensure you have:

- **VS Code** installed
- **PlatformIO** or **Arduino extension** installed in VS Code
- Hardware connected (Arduino/ESP32/other MCU)
- USB or SWD/JTAG debugger (if available)
- Terminal/Serial Monitor for UART debugging

---

## 2. General Debugging Steps

1. **Check Connections**
   - UART: TX → RX, RX → TX, GND connected
   - I2C: SDA → SDA, SCL → SCL, pull-up resistors if required
   - Power/GND properly connected

2. **Check Peripheral Initialization**
   - Ensure the peripheral is initialized correctly in your code
   - Example (UART):
     ```c
     SERCOM7_USART_Init(9600);
     ```
   - Example (I2C):
     ```c
     I2C_Init(I2C_BAUD_100KHZ);
     ```

3. **Enable Debug Logging**
   - Use `Serial.print()` for UART
   - Log I2C read/write values
   - Example:
     ```c
     uint8_t data = I2C_ReadRegister(TEMP_SENSOR_ADDR, TEMP_SENSOR_REG);
     Serial.print("Temperature Data: ");
     Serial.println(data);
     ```

---

## 3. Using VS Code Debug Features

1. **Open the Serial Monitor**
   - Arduino Extension: `Ctrl+Shift+M` or click **Serial Monitor**
   - PlatformIO: `PlatformIO > Monitor`

2. **Set Breakpoints (if using Debugger)**
   - Open `.c` / `.cpp` file
   - Click left of line numbers to set a breakpoint
   - Launch debugger: `Run > Start Debugging` (F5)
   - Step through peripheral code (init, read/write, interrupts)

3. **Inspect Variables**
   - Watch peripheral registers
   - Inspect buffer content (UART/I2C)
   - Verify flags (RX ready, TX complete, NACK, BUSSTATE)

4. **Check Interrupts**
   - Enable NVIC interrupt logging
   - Print interrupt flags when they occur
   - Example:
     ```c
     if (USART_RX_INT_FLAG)
         Serial.println("RX Interrupt Triggered");
     ```

---

## 4. Debugging UART

- **Problem:** No data received
  - Check TX/RX wiring
  - Check baud rate match
  - Ensure `Serial.begin()` or `USART_Init()` called

- **Problem:** Garbage data
  - Wrong baud rate
  - Voltage mismatch (5V vs 3.3V)
  - Check line termination (CR/LF)

- **Steps to debug:**
  1. Print data before sending
  2. Print received bytes in ISR
  3. Use logic analyzer if available

---

## 5. Debugging I2C

- **Problem:** NACK received
  - Check slave address
  - Pull-up resistors on SDA/SCL
  - Check bus voltage (3.3V or 5V)

- **Problem:** Bus stuck
  - Reset bus (toggle SCL 9–10 times)
  - Check for SDA held low

- **Steps to debug:**
  1. Read/write single register
  2. Print register value via UART
  3. Step through code with debugger

---

## 6. Tips & Best Practices

- Always start simple: test one peripheral at a time
- Use **Serial.print()** liberally to log status
- Keep wiring diagrams in the repo for reference
- Version control your debug logs and findings
- Use **LED indicators** for real-time debugging if UART is busy

---

## 7. References / Tools

- [VS Code Official](https://code.visualstudio.com/)
- [PlatformIO Debugging](https://docs.platformio.org/en/latest/ide/vscode.html)
- [Arduino Debugging](https://www.arduino.cc/en/Guide/Debugging)
- Logic Analyzer for I2C/UART

---


