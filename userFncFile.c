#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_LED1.h"
#include "inc/led_LED2.h"
#include "inc/led_LED3.h"
#include "inc/relay_Relay1.h"
#include "inc/relay_Relay2.h"
#include "inc/timer_api1.h"
#include "inc/EMICBus.h"

void eI2C(char* tag, const streamIn_t* const msg)
{
    if (strncmp(tag, "TEMP", 4) == 0)
    {
        Actual = streamIn_t_ptr_to_int16_t((streamIn_t*)msg);
        if (Actual > Maximo)
        {
            relay_Relay1(0);
            pI2C("STATUS\tOFF");
        }
        else
        {
            if (Actual < Minimo)
            {
                relay_Relay1(1);
                pI2C("STATUS\tON");
            }
        }
    }
    else if (strncmp(tag, "SET_MAX", 7) == 0)
    {
        Maximo = streamIn_t_ptr_to_int16_t((streamIn_t*)msg);
    }
    else if (strncmp(tag, "SET_MIN", 7) == 0)
    {
        Minimo = streamIn_t_ptr_to_int16_t((streamIn_t*)msg);
    }
    else
    {
        /* default case - no action */
    }
}



