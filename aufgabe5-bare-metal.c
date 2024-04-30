#include <avr/io.h>
#include <stdbool.h>
#include "wait.h"

#define BLUE0_MASK (1 << 7)
#define BLUE1_MASK (1 << 2)
#define BUTTON0_MASK (1 << 2)

void main(void) {
	// set pins for BLUE0 (PORT D) and BLUE1 (PORT C) to output
	DDRD |= BLUE0_MASK;
	DDRC |= BLUE1_MASK;

	// initialize BUTTON0
	DDRD &= ~BUTTON0_MASK; // input
	PORTD |= BUTTON0_MASK; // activate pullup

	while (true) {
		if (PIND & BUTTON0_MASK) {
			PORTD |= BLUE0_MASK;
			PORTC |= BLUE1_MASK;
			wait_1s();
		} else {
			PORTD &= ~BLUE0_MASK;
			PORTC |= BLUE1_MASK;
			wait_1s();
			PORTD |= BLUE0_MASK;
			PORTC &= ~BLUE1_MASK;
			wait_1s();
		}
	}
}
