#include <msp430.h>

void main(void)
{
	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// set P1.0 to be LED1 (red) and P1.1 to be button1
	P1DIR = BIT0 & ~BIT1;

	// set P2.1 as button2
	P2DIR &= ~BIT1;

	// set P4.7 as LED2 (green)
	P4DIR |= BIT7;

	// set button1 and button2 as a pull-up resistors
	P2REN = P1REN = BIT1;
	P2OUT = P1OUT = BIT1;

	while (1) {
		// if button1 is not pressed; if P1.1 is high voltage
		if ((P1IN & 0002) == BIT1)
			P1OUT &= ~BIT0;
		else {
			P1OUT |= BIT0;
		}

		// likewise for button2
		if ((P2IN & 0002) == BIT1)
			P4OUT &= ~BIT7;
		else 
			P4OUT |= BIT7;		
	}
}
