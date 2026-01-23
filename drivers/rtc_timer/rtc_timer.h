#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <stdbool.h>

void RTC_Timer_Init(uint32_t compare);
void RTC_Timer_Start(void);
void RTC_Timer_SetCompare(uint32_t value);
bool RTC_Timer_Expired(void);
uint32_t APP_GetTick(void);

#endif
