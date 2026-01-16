#include "sercom7_usart.h"

int main(void)
{
    /* Initialize SERCOM7 USART at 115200 baud */
    SERCOM7_USART_Init(115200);

    /* Send startup message */
    SERCOM7_USART_WriteString("SERCOM7 USART Initialized\r\n");

    while (1)
    {
        /* Echo received character */
        uint8_t ch = SERCOM7_USART_ReadByte();
        SERCOM7_USART_WriteByte(ch);
    }
}
