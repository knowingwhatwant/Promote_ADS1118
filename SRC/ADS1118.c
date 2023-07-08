
#include "INC/ADS1118.h"

// #define CONF 0b0011000011101011

void ADS1118_Init()
{
    P1DIR |= BIT0 + BIT2 + BIT3;
    P1DIR &= ~BIT1;
    P1OUT &= ~(BIT0 + BIT2 + BIT3);
    P1REN |= BIT1;
    SET_CS();
    CLR_SCLK();
    CLR_DIN();
}

uint16_t ADS1118_WR(uint16_t wdata)
{
    uint16_t data = wdata;
    uint16_t rdata = 0;
    uint8_t i = 0;
    CLR_CS();
    __delay_cycles(2000); // CSSC
    for (i = 0; i < 16; i++)
    {
        if (data & 0x8000)
        {
            SET_DIN();
        }
        else
        {
            CLR_DIN();
        }
        data <<= 1;
        __delay_cycles(300); //
        SET_SCLK();
        __delay_cycles(30000); // DIN
        rdata <<= 1;
        if (P1IN & BIT1)
            rdata |= 0x0001;
        __delay_cycles(300);
        CLR_SCLK(); //
        __delay_cycles(300);
    }
    __delay_cycles(2000); //
    CLR_DIN();
    return rdata;
}

uint16_t ADS1118_ConfigAndConversion(uint8_t PGA)
{
    uint16_t ConfigRegister = MUX_3 | PGA_0 | DR_7 | PULL_UP_EN | NOP_1 ;
    uint16_t Sum = 0;
    switch (PGA)
    {
    case PGA_0:

        ConfigRegister |= PGA_0;
        break;
    case PGA_1:

        ConfigRegister |= PGA_1;
        break;
    case PGA_2:

        ConfigRegister |= PGA_2;
        break;
    case PGA_3:

        ConfigRegister |= PGA_3;
        break;
    case PGA_4:

        ConfigRegister |= PGA_4;
        break;
    case PGA_5:

        ConfigRegister |= PGA_5;
        break;
    case PGA_6:

        ConfigRegister |= PGA_6;
        break;
    case PGA_7:

        ConfigRegister |= PGA_7;
        break;

    default:
        break;
    }

    Sum = ADS1118_WR(ConfigRegister);
    __delay_cycles(200);
    return (uint16_t)Sum;
}
