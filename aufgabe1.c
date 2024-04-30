#include <led.h>
#include <stdbool.h>
#include "wait.h"

void all_on(void) {
	for (uint8_t i = 0; i < 8; i++) {
		sb_led_on(i);
	}
}

void all_off(void) {
	for (uint8_t i = 0; i < 8; i++) {
		sb_led_off(i);
	}
}

void main(void) {
	while (true) {
		all_on();
		wait_1s();
		all_off();
		wait_1s();
	}
}
