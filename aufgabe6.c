#include <avr/interrupt.h>
#include <button.h>
#include <led.h>
#include <timer.h>
#include <stdbool.h>

volatile bool button0_pressed = false;

void button0_callback(BUTTON button, BUTTONEVENT event) {
	if (button == BUTTON0) {
		switch (event) {
			case ONPRESS:
				button0_pressed = true;
				break;
			case ONRELEASE:
				button0_pressed = false;
				break;
		}
	}
}

void main(void) {
	sei();
	sb_button_registerCallback(BUTTON0, ONPRESS, button0_callback);
	sb_button_registerCallback(BUTTON0, ONRELEASE, button0_callback);
	while (true) {
		if (button0_pressed) {
			sb_led_on(BLUE0);
			sb_led_off(BLUE1);
			sb_timer_delay(1000);
			sb_led_off(BLUE0);
			sb_led_on(BLUE1);
			sb_timer_delay(1000);
		} else {
			sb_led_off(BLUE0);
			sb_led_off(BLUE1);
			sb_timer_delay(1000);
		}
	}
}
