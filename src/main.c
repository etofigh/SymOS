#include "rpi.h"

#define LED_PIN 	16

#define JTAG_TRST 	22
#define JTAG_TDI	4
#define JTAG_TDO	24
#define JTAG_TMS	27
#define JTAG_TCK	25

void enable_jtag(void)
{
	gpio_set_pin_pull(JTAG_TRST, GPIO_PULL_DISABLED);
	gpio_set_pin_pull(JTAG_TDI, GPIO_PULL_DISABLED);
	gpio_set_pin_pull(JTAG_TDO, GPIO_PULL_DISABLED);
	gpio_set_pin_pull(JTAG_TMS, GPIO_PULL_DISABLED);
	gpio_set_pin_pull(JTAG_TCK, GPIO_PULL_DISABLED);

	gpio_set_function(JTAG_TRST, GPIO_FSEL_ALT4);
	gpio_set_function(JTAG_TDI, GPIO_FSEL_ALT5);
	gpio_set_function(JTAG_TDO, GPIO_FSEL_ALT4);
	gpio_set_function(JTAG_TMS, GPIO_FSEL_ALT4);
	gpio_set_function(JTAG_TCK, GPIO_FSEL_ALT4);
}

int kernel_main(unsigned int r0, unsigned int r1, unsigned int atags)
{
	enable_jtag();

	gpio_set_function(LED_PIN, GPIO_FSEL_OUTPUT);
	
	while (1) {
		gpio_clr_pin(LED_PIN);
		for(volatile int i = 0; i < 1000000; i++);
		gpio_set_pin(LED_PIN);
		for(volatile int i = 0; i < 1000000; i++);
	}

	return 0;
}
