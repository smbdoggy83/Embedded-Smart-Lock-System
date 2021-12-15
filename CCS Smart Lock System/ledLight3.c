/*
 * ledLight2.c
 *
 *  Created on: Dec 12, 2021
 *      Author: Seth
 */

#include <msp430.h>

// INPUTS
#define RF BIT3     // RF Receiver, MSP430 Button
#define TOUCH BIT4  // Touch Button

// OUTPUTS
#define LED BIT0    // Green LED
#define EMLOCK BIT5   // Electromagnetic Lock
#define GREENLED BIT6

// VARIABLES
int count = 0;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    // Define Inputs
    P1IE = RF + TOUCH; // enable interrupt from port P1
    P1IES = RF + TOUCH; // interrupt edge select from high to low

    // Define Outputs
    P1DIR = LED; // Initialize ports and data
//    P1OUT = LED;
    P1IFG &= ~RF + ~TOUCH; //clear the interrupt flag

    _enable_interrupts(); // enable all interrupts

    while(1); // wait for an interrupt, don't exit program
}

#pragma vector = PORT1_VECTOR // define the interrupt vector
__interrupt void PORT1_ISR(void) // interrupt service routine
{
    /*
    if (count % 2 = 0)
    {
        P1OUT |= 0x00;
    }
    else if (count % 2 = 1)
    {
        P1OUT |= 0x01;
    }
    */
    if (count == 12)
    {
        P1OUT = 0x01; // turn on LED
    }
    else
    {
        P1OUT = 0x00; // turn off LED
    }
//    P1OUT ^= 0x01; // toggle LED
    count++; // this works
    P1IFG &= ~RF + ~TOUCH; // clear the interrupt flag before exiting
}
