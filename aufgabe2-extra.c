#include <led.h>
#include <stdbool.h>
#include "wait.h"

void toggle_leds(LED led1, LED led2) {
	sb_led_toggle(led1);
	sb_led_toggle(led2);
}

void main(void) {
	while (true) {
		toggle_leds(RED0, RED1);
		wait_1s();
		toggle_leds(YELLOW0, YELLOW1);
		wait_1s();
		toggle_leds(RED0, RED1);
		toggle_leds(YELLOW0, YELLOW1);
		toggle_leds(GREEN0, GREEN1);
		wait_1s();
		toggle_leds(GREEN0, GREEN1);
		toggle_leds(YELLOW0, YELLOW1);
		wait_1s();
		toggle_leds(YELLOW0, YELLOW1);
	}
}
