#include <led.h>
#include <stdbool.h>
#include "wait.h"

void main(void) {
	uint8_t mask = 1 << BLUE0;
	while (true) {
		sb_led_setMask(mask);
		wait_1s();
		mask ^= ((1 << BLUE0) | (1 << BLUE1));
	}
}
