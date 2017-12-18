#include <msp430.h>				

void alternateLights(void);
void main(void)
 {
	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// set P1.0 to LED_1 (red) and P1.1 to be button1
	// set P2.1 as button2
	// set P4.7 as LED_2 (green)
	P1DIR = BIT0 & ~BIT1;
	P2DIR &= ~BIT1;
	P4DIR |= BIT7;
	
	// set button1 and button2 as pull-up resistors
	P2REN = P1REN = BIT1;
	P2OUT = P1OUT = BIT1;

	while (1) {
		// turn off LEDs at each loop start
		P1OUT &= ~BIT1;
		P4OUT &= ~BIT7;

		// P2.1 is low-voltage, which means button2 was pressed
		if ((P2IN & 0x0002) != BIT1) {
			alternateLights();
		}
	}
}

// alternates between lights 5 times
void alternateLights(void)
{
	volatile unsigned int blink_lights = 1;
	int i = 0;

	while (blink_lights) {
		// alternate LED_1
		P1OUT ^= BIT0;

		// delay
		for(i = 30000; i > 0; i--);
		
		// alternate LED_2
		P4OUT ^= BIT7;

		// // if button1 is pressed
		// if ((P1IN & 0x0002) == BIT1) {
		// 	blink_lights = 0;
		// }
	}
}
