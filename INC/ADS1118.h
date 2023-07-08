/*
 * ADS1118.h
 *
 *  Created on: 2023年7月8日
 *      Author: 24811
 */

#ifndef INC_ADS1118_H_
#define INC_ADS1118_H_


#include<stdint.h>
#include "D:/CCS/ccs/ccs_base/msp430/include/msp430fr2355.h"


#define SET_DIN()   P1OUT |=  BIT0
#define CLR_DIN()   P1OUT &= ~BIT0
#define SET_CS()    P1OUT |=  BIT2
#define CLR_CS()    P1OUT &= ~BIT2
#define SET_SCLK()  P1OUT |=  BIT3
#define CLR_SCLK()  P1OUT &= ~BIT3
#define DOUT        P1IN

//config registers
#define SS          BITF
#define MUX2        BITE
#define MUX1        BITD
#define MUX0        BITC
#define PGA2        BITB
#define PGA1        BITA
#define PGA0        BIT9
#define MODE        BIT8
#define DR2         BIT7
#define DR1         BIT6
#define DR0         BIT5
#define TS_MODE     BIT4
#define PULL_UP_EN  BIT3
#define NOP1        BIT2
#define NOP0        BIT1
#define Reserved    BIT0

#define MUX_0       0x0000
#define MUX_1       0x1000
#define MUX_2       0x2000
#define MUX_3       0x3000
#define MUX_4       0x4000
#define MUX_5       0x5000
#define MUX_6       0x6000
#define MUX_7       0x7000
#define PGA_0       0x0000
#define PGA_1       2*0x0100
#define PGA_2       2*0x0200
#define PGA_3       2*0x0300
#define PGA_4       2*0x0400
#define PGA_5       2*0x0500
#define PGA_6       2*0x0600
#define PGA_7       2*0x0700
#define DR_0        2*0x0000
#define DR_1        2*0x0010
#define DR_2        2*0x0020
#define DR_3        2*0x0030
#define DR_4        2*0x0040
#define DR_5        2*0x0050
#define DR_6        2*0x0060
#define DR_7        2*0x0070
#define NOP_0       2*0x0000
#define NOP_1       2*0x0001
#define NOP_2       2*0x0002
#define NOP_3       2*0x0003





void ADS1118_Init();
uint16_t ADS1118_WR(uint16_t wdata);
uint16_t ADS1118_ConfigAndConversion(uint8_t PGA);






#endif /* INC_ADS1118_H_ */
