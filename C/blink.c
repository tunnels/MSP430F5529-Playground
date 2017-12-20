#include <msp430.h>				

void turnOffBothLEDs();
void main(void)
 {
	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;
	
	// P1.1 and P2.1 are the buttons
	P1DIR &= ~BIT1;
	P2DIR &= ~BIT1;
	
	// P1.0 = red LED; P4.7 = green LED
	P1DIR |= BIT0;
	P4DIR |= BIT7;
	
	// set button1 and button2 as pull-up resistors
	P2REN = P1REN = BIT1;
	P2OUT = P1OUT = BIT1;

	turnOffBothLEDs();

	while (1) {
		// if button2 is pressed
		if ((P2IN & BIT1) != BIT1) {
			alternateLights();
		}
	}
}

void alternateLights()
{	
	while (1) {
		P1OUT ^= BIT0;
		__delay_cycles(100000);
		P4OUT ^= BIT7;
		__delay_cycles(100000);

		// if button1 is pressed
		if ((P1IN & BIT1) != BIT1) {
			turnOffBothLEDs();
			return;
		}
	}
}

void turnOffBothLEDs()
{
	P1OUT &= ~BIT0;
	P4OUT &= ~BIT7;	
}
