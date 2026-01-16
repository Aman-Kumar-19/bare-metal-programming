# SERCOM7 USART Echo Example
This example demonstrates basic USART communication using
the SERCOM7 driver layer.

## Hardware
- MCU: PIC32CX1025SG61128
- SERCOM Instance: SERCOM7
- TX Pin: PC12 (PAD0, Function C)
- RX Pin: PC13 (PAD1, Function C)
- Baud Rate: 115200

## Concepts Covered
- SERCOM peripheral configuration
- USART asynchronous communication
- Clock configuration (GCLK & APBD)
- Pin multiplexing (PMUX)
- Blocking transmit and receive
- Application-level abstraction over registers

## Driver APIs Used
- `SERCOM7_USART_Init(uint32_t baudrate)`  – USART initialization
- `SERCOM7_USART_WriteByte(uint8_t data)`  – Transmit single byte
- `SERCOM7_USART_ReadByte(void)`  – Receive single byte
- `SERCOM7_USART_WriteString(const char *str)`  – Transmit string

## Files
- `main.c`– Application code using SERCOM7 USART APIs
- `sercom7_usart.c` – SERCOM7 USART driver implementation
- `sercom7_usart.h` – SERCOM7 USART driver interface
