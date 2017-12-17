#include <msp430.h>				

void main(void)
 {
	WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
	P1DIR = BIT0;
	P4DIR = BIT7;               // set P1.0 and P4.7 to output

	volatile unsigned int i;

	// activate both lights/outputs
	P1OUT = BIT0;
	P4OUT = BIT7;

	// alternates the green and red lights between on and off
	for (;;) {
	    P1OUT ^= BIT0;              // set P1.0 (output/light) to on
	    for(i = 20000; i > 0; i--); // delay
	    P4OUT ^= BIT7;              // set P4.7 (output/light) to on
	}
}
