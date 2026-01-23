#include "rtc_timer.h"
#include <pic32cx1025sg61128.h>

static volatile bool rtcExpired = false;
static volatile uint32_t app_tick_ms = 0;  

void RTC_Timer_Init(uint32_t compare)
{
    /* Enable RTC clock */
    MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_RTC_Msk;

    /* Reset RTC */
    RTC_REGS->MODE0.RTC_CTRLA |= RTC_MODE0_CTRLA_SWRST_Msk;
    while (RTC_REGS->MODE0.RTC_SYNCBUSY);

    /* Configure RTC MODE0 */
    RTC_REGS->MODE0.RTC_CTRLA =
        RTC_MODE0_CTRLA_MODE_COUNT32 |
        RTC_MODE0_CTRLA_PRESCALER_DIV1024;

    while (RTC_REGS->MODE0.RTC_SYNCBUSY);

    /* Clear counter */
    RTC_REGS->MODE0.RTC_COUNT = 0;
    while (RTC_REGS->MODE0.RTC_SYNCBUSY);

    /* Set compare value */
    RTC_REGS->MODE0.RTC_COMP[0] = compare;
    while (RTC_REGS->MODE0.RTC_SYNCBUSY);

    /* Enable compare 0 interrupt flag (polling only) */
    RTC_REGS->MODE0.RTC_INTENSET = RTC_MODE0_INTENSET_CMP0_Msk;
}

void RTC_Timer_Start(void)
{
    RTC_REGS->MODE0.RTC_CTRLA |= RTC_MODE0_CTRLA_ENABLE_Msk;
    while (RTC_REGS->MODE0.RTC_SYNCBUSY);
}

void RTC_Timer_SetCompare(uint32_t value)
{
    RTC_REGS->MODE0.RTC_COUNT = 0;
    while (RTC_REGS->MODE0.RTC_SYNCBUSY);

    RTC_REGS->MODE0.RTC_COMP[0] = value;
    while (RTC_REGS->MODE0.RTC_SYNCBUSY);

    /* Clear compare flag */
    RTC_REGS->MODE0.RTC_INTFLAG = RTC_MODE0_INTFLAG_CMP0_Msk;
}

bool RTC_Timer_Expired(void)
{
    if (RTC_REGS->MODE0.RTC_INTFLAG & RTC_MODE0_INTFLAG_CMP0_Msk)
    {
        RTC_REGS->MODE0.RTC_INTFLAG = RTC_MODE0_INTFLAG_CMP0_Msk;

        app_tick_ms++;
        
        return true;
    }
    return false;
}

uint32_t APP_GetTick(void)
{
    return app_tick_ms;
}
