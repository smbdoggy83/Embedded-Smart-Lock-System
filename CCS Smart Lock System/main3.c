/*
 * main3.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Seth
 */


#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; //Stop watchdog timer to Prevent PUC Reset
    P1DIR &= ~BIT3 ; //explicitly making P1.3 as Input - even though by default its Input
    P1DIR &= ~BIT4;
    P1REN = BIT3; //Enable Pullup/down
    P1REN = BIT4;
    P1OUT = BIT3; //Select Pullup
    P1OUT = BIT4;

    P1DIR |= BIT6; //Configuring P1.6(LED2) as Output
    P1OUT |= BIT6; //drive output HIGH initially

    while(1)
    {
        if( !(P1IN & (BIT3 || BIT4))) //Evaluates to True for a 'LOW' on P1.3
        {
            P1OUT ^= BIT6; //Toggle the state of P1.6
            while( !(P1IN & (BIT3 || BIT4)) ); //wait until button is released
        }
    }
    //return 0; //this won't execute normally
}

