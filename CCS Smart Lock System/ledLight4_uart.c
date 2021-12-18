#include <msp430.h>

// INPUTS
#define RF BIT3     // RF Receiver, MSP430 Button
#define TOUCH BIT4  // Touch Button

// OUTPUTS
//#define LED BIT0    // Green LED
#define EMLOCK BIT5   // Electromagnetic Lock
//#define GREENLED BIT6

// VARIABLES

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    // Define Inputs
    P1IE = RF + TOUCH; // enable interrupt from port P1
    P1IES = RF + TOUCH; // interrupt edge select from high to low

    // Define Outputs
    P1DIR = EMLOCK; // Initialize ports and data
    P1OUT ^= EMLOCK; // It starts out ON, so we just turn it off real quick
    P1IFG &= ~RF + ~TOUCH; //clear the interrupt flag

    /* Configure Pin Muxing P1.1 RXD and P1.2 TXD */
    P1SEL = BIT1 | BIT2;
    P1SEL2 = BIT1 | BIT2;

    /* Use Calibration values for 1MHz Clock DCO*/
    DCOCTL = 0;             // Lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_1MHZ;  // Set DCO
    DCOCTL = CALDCO_1MHZ;

    uart_init();

    _enable_interrupts(); // enable all interrupts
    __bis_SR_register(LPM0_bits + GIE);                                       // Enter LPM0 w/ interrupt
    while(1); // wait for an interrupt, don't exit program
}

void uart_init(void){
    /* Place UCA0 in Reset to be configured */
    UCA0CTL1 = UCSWRST;
    /* Baud Rate configuration */
    UCA0CTL1 |= UCSSEL_2; // UART Clock -> SMCLK
    UCA0BR0 = 8; // 1MHz / 115200 baud rate = 8
    UCA0BR1 = 0; // 1MHz / 115200 baud rate = 8
    UCA0MCTL = UCBRS1; // Modulation UCBRSx = 1
    /* Take UCA0 out of reset */
    UCA0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**
    IE2 |= UCA0RXIE; //Enable USCI_A0 RX interrupt

}

#pragma vector = PORT1_VECTOR // define the interrupt vector
__interrupt void PORT1_ISR(void) // interrupt service routine
{
    unlockDoor();
    P1IFG &= ~RF + ~TOUCH; // clear the interrupt flag before exiting
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
// Detect if 'U' is sent, also necessary because rx might constantly get a 'high' state
//     if (UCA0RXBUF == 0x8A || UCA0RXBUF == 0x6A || UCA0RXBUF == 'U' || UCA0RXBUF == 'L') // 'U' ascii = 0x55 hex. both work
    if (UCA0RXBUF >= 0x01)
    {
         unlockDoor();
     }
     //    while (!(IFG2&UCA0TXIFG));          // Check if TX is ongoing
     //    UCA0TXBUF = 0x00;          // TX -> Received Char + 1

    // interrupt automatically clears
}

void unlockDoor(void)
{
    P1OUT ^= EMLOCK; // toggle LED
    __delay_cycles(1500000);
    P1OUT ^= EMLOCK; // toggle LED
}
