#include <xc.h>
#include "inc/systemConfig.h"

#include "inc/systemTimer.h"
#include "inc/led_LED1.h"
#include "inc/led_LED2.h"
#include "inc/led_LED3.h"
#include "inc/relay_Relay1.h"
#include "inc/relay_Relay2.h"
#include "inc/timer_api1.h"
#include "inc/EMICBus.h"
#include "inc/system.h"
#include "inc/userFncFile.h"

#include "system.c"

int main(void)
{
	initSystem();
	systemTimeInit();
	LEDs_LED1_init();
	LEDs_LED2_init();
	LEDs_LED3_init();
	initRelay_Relay1();
	EMICBus_init();
	do
	{
		poll_EMICBus();
	}
	while(1);
}

