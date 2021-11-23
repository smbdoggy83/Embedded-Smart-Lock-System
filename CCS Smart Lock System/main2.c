/*
 * main2.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Seth
 */

/*
#include "MSP430.h"

int main2(void) {

WDTCTL = WDTPW | WDTHOLD;

TA0CCTL0 = CCIE;

TA0CTL = TASSEL_2 + MC_1 + ID_3;

TA0CCR0 = 10000

P1DIR |= 0X01;

P1OUT |= 0X00;

_BIS_SR(CPUOFF + GIE);
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
P1OUT ^= 0X01;
}
*/
