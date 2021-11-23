/*
#include <msp430.h> 
#define LED BIT0
#define UART_RX BIT1
#define UART_TX BIT2
//#define RF BIT3
#define BUTTON BIT3
#define TOUCH BIT4
#define DOOR BIT5

// main.c
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//P1.1 and P1.2: UCA0/RXD input and UCA0/TXD output for ESP

	//P1.3 General I/O input for RF Receiver
//	P1DIR &= ~RF;
//	P1REN = RF;

	//P1.4: General I/O input (Button)
//	P1DIR = TOUCH;
//	P1REN = TOUCH;
	//Analog Stuff: https://electronics.stackexchange.com/questions/87182/external-sensor-interfaced-with-msp430

	//P1.5: General I/O output for Door
//	P1DIR |= DOOR;
//	P1OUT |= DOOR; //High-Driven Outputs

	ledLight();

	P1DIR = LED; //setting bit0 / P1.0 as output
	P1OUT = 0x00; //puts p1 in pull-up mode

	P1SEL &= (~TOUCH);
	P1OUT = TOUCH;

	while(1) {
	    if ((P1IN & BUTTON) == 0x00 || (P1IN & TOUCH) == 0x00) // 0 = high input
	        P1OUT = LED; //Force BIT0 (output) to be high = turn on led
	    else
	        P1OUT = 0x00; //turn led off
	}

}
*/

