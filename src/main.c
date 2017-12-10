#include "rpi.h"

int kernel_main(void)
{
	while(1) {
		gpio_clr_pin(16);

		for(volatile int i = 0; i < 10000; i++);

		gpio_set_pin(16);

		for(volatile int i = 0; i < 10000; i++);
	}

	return 0;
}

void exit(int code)
{
    while(1);
}