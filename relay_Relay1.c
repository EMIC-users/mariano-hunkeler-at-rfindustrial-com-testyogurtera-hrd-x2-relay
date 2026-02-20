#include <xc.h>
#include "inc/relay_Relay1.h"
#include "inc/gpio.h"


void initRelay_Relay1(void)
{
    HAL_GPIO_PinCfg(Rele1, GPIO_OUTPUT);
    HAL_GPIO_PinSet(Rele1, GPIO_LOW);
}


void relay_Relay1(uint8_t stateRelay)
{
	switch (stateRelay)
    {
    case 0:
        HAL_GPIO_PinSet(Rele1, GPIO_LOW);
        break;
    case 1:
        HAL_GPIO_PinSet(Rele1, GPIO_HIGH);
        break;
    case 2:
        HAL_GPIO_PinSet(Rele1, !HAL_GPIO_PinGet(Rele1));
        break;
    default:
        break;
    }
}


