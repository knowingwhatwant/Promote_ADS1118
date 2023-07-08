#include "msp430fr2355.h"
#include "INC/ADS1118.h"

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;
        ADS1118_Init();

        volatile uint16_t AdcValue = 0;
        volatile float adc;
        while(1)
        {
            AdcValue = ADS1118_ConfigAndConversion(PGA_0);
            adc =((int)AdcValue)*6.144/ 32767;
        }
}
