/*
 * ledLight.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Seth
 */

#include <msp430.h>
#define RedLED BIT6
#define GreenLED BIT0
#define BUTTON BIT3

int data = 0;

void uart_init(void);

void ledLight(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR = 0x41; //output set to ((something))
    P1IE = BUTTON; //interrupt enable is set to button (port 1)
    P1IES = BUTTON; //interrupt edge select from high to low
    P1IFG = 0x00; //clear the interrupt flag
    P1SEL = BIT1|BIT2;
    P1SEL2 = BIT1|BIT2;
    uart_init();
    _enable_interrupts(); //enable all interrupts

    while(1); //keep running, wait for an interrupt
}

#pragma vector = PORT1_VECTOR       //define the interrupt service vector. where to go when i/o port 1 is interrupted.
__interrupt void PORT1_ISR(void) {   // interrupt service routine (ISR). Run this code when interrupt has occurred.
       data ^= 0x40;          //toggle LEds to show that Port interupt has occured
       P1IFG    = 0x00;
}

#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIA0TX_ISR(void) {
    UCA0TXBUF =  data;
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIA0RX_ISR(void) {
    P1OUT = UCA0RXBUF;
}

void uart_init(void){
    //clock//baudrate//modulation//sw rest//TXRX interrupt
    UCA0CTL1 |= UCSSEL_2;                    //Select SMCLK as the baud rate generator source
    UCA0BR1 = 0; //high byte
    UCA0BR0 = 104;  //low byte                         //Produce a 9,600 Baud UART rate
    UCA0MCTL = UCBRS_1;                         //Second modulation select stage is 1
    UCA0STAT |= UCLISTEN;
    UCA0CTL1 &= ~UCSWRST;                    //clear software reset, resume operaion
    IE2 |= UCA0RXIE | UCA0TXIE;                         //Enable the UART Transmit receiver Interrupt

}
