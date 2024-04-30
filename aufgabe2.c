#include <led.h>
#include <stdbool.h>
#include "wait.h"

void main(void) {
	sb_led_on(BLUE0);
	while (true) {
		wait_1s();
		sb_led_toggle(BLUE0);
		sb_led_toggle(BLUE1);
	}
}
