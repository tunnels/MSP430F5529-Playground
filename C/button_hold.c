#include <msp430.h>

void main(void)
{
	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// set P1.0 to be output and P1.1 to be input
	P1DIR = BIT0 & ~BIT1;

	// set P1.1 as a pull-up resistor
	P1REN = BIT1;
	P1OUT = BIT1;

	while (1 > 0) {
		// if P1.1 is not pressed; if P1.1 is high voltage
		if ((P1IN & 0002) == BIT1)
			P1OUT &= ~BIT0;
		else 
			P1OUT |= BIT0;
	}
}
