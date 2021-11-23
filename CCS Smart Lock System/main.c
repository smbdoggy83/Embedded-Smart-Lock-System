
#include <msp430.h> 
#define LED BIT0
#define BUTTON BIT3


// main.c
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//To declare pin mode: pinMode(Pin_Number, INPUT/OUTPUT)
	//To send out a signal from an output: digitalWrite(pin, HIGH/LOW)
	//digitalRead(Pin_number or variable or whatever)

	//P1.1 and P1.2: UCA0/RXD input and UCA0/TXD output for ESP
	//P1.3 General I/O input for RF Receiver

	//P1.4: General I/O input, or A4 input for Touch Button if its output is analog
	P1DIR &= ~BIT4;
	P1REN = BIT4;

	//Analog Stuff: https://electronics.stackexchange.com/questions/87182/external-sensor-interfaced-with-msp430

	//P1.5: General I/O output for Door
	P1DIR |= BIT5;
	P1OUT |= BIT5; //High-Driven Outputs


//	ledLight();

	P1DIR = LED;
	P1OUT = 0x00;

	while(1) {
	    if ((P1IN & BUTTON) == 0x00)
	        P1OUT = LED;
	    else
	        P1OUT = 0x00;
	}

}

