/*
 * ledLight.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Seth
 */

#include <msp430.h>
#define RedLED BIT6
#define BUTTON BIT3 //BIT 3 = port 1.3 and on-board button. BIT 4 = port 1.4 (touch button)
#define TOUCH BIT4 //touch button

int data = 0;

void uart_init(void);

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    if (CALBC1_1MHZ==0xFF)                    // If calibration constant erased
    {
      while(1);                               // do not load, trap CPU!!
    }

    P1OUT = RedLED;
    P1DIR = 0x41; //output set to ((something))
//    P1IE = BUTTON; //interrupt enable is set to button (port 1)
//    P1IES = BUTTON; //interrupt edge select from high to low
    P1IE = TOUCH;
    P1IES = TOUCH;
    P1IFG = 0x00; //clear the interrupt flag
//    P1SEL = BIT1|BIT2;
//    P1SEL2 = BIT1|BIT2;
//    uart_init();

    _enable_interrupts(); //enables all interrupts by setting the Global Interrupt Enable (GIE) bit

    while(1); //keep running, wait for an interrupt
}

void unlock_door() // no input should be able to just unlock the door. they should do this which updates thingspeak info and unlocks it for 60s and stuff. would be intersting if the physical components had a faster method than the phone app though (might not have to use thingspeak for those)
{
    // Do stuff
}

#pragma vector = PORT1_VECTOR       //define the interrupt service vector. where to go when i/o port 1 is interrupted.
__interrupt void PORT1_ISR(void) {   // interrupt service routine (ISR). Run this code when interrupt has occurred.
       data ^= 0x40;          //toggle LEds to show that Port interupt has occured
       P1OUT ^= 0x01;
       P1IFG    = 0x00;
}
/*
#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIA0TX_ISR(void)
{
    UCA0TXBUF =  data;
}


#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIA0RX_ISR(void)
{
    P1OUT = UCA0RXBUF;
}
*/
void uart_init(void){
    //clock//baudrate//modulation//sw rest//TXRX interrupt
    UCA0CTL1 |= UCSSEL_2;                    //Select SMCLK as the baud rate generator source
    UCA0BR0 = 8;  //low byte                 // 1MHz / 115200 Baud UART rate = 8.7
    UCA0BR1 = 0; //high byte                 // 1MHz / 115200 Baud UART rate = 8.7
    UCA0MCTL = UCBRS_1;                      //Second modulation select stage is 1
    UCA0STAT |= UCLISTEN;
    UCA0CTL1 &= ~UCSWRST;                    //clear software reset, resume operation // **Initialize USCI state machine**
    IE2 |= UCA0RXIE | UCA0TXIE;              //Enable the UART Transmit receiver Interrupt

}
