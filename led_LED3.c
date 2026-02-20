#include <xc.h>
#include "inc/led_LED3.h"
#include "inc/gpio.h"
#include "inc/systemTimer.h"

void LEDs_LED3_init (void)
{
	HAL_GPIO_PinCfg(Led3, GPIO_OUTPUT);
}




