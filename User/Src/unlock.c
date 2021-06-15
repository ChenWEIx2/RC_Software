
#include "unlock.h"

uint8_t Unlock(volatile uint16_t* adc_result)
{
    uint8_t flag = (adc_result[0]>4000) && (adc_result[1]<4000) && (adc_result[2]>4000) && (adc_result[3]>4000);
    UNLOCK_BEEP;
    return flag;
}