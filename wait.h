#include <stdint.h>

void wait_1s(void) {
	for (volatile uint32_t i = 0; i < 400000; i++);
}
