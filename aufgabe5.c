#include <button.h>
#include <led.h>
#include <stdbool.h>
#include "wait.h"

void main(void) {
	while (true) {
		switch (sb_button_getState(BUTTON0)) {
			case PRESSED:
				sb_led_on(BLUE0);
				sb_led_off(BLUE1);
				wait_1s();
				sb_led_off(BLUE0);
				sb_led_on(BLUE1);
				wait_1s();
				break;

			case RELEASED:
				sb_led_off(BLUE0);
				sb_led_off(BLUE1);
				wait_1s();
				break;

			case UNKNOWN: break;
		}
	}
}
