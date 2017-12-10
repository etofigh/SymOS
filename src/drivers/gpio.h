#pragma once

#include "rpi.h"

#define GPIO_BASE (PERIPHERAL_BASE + 0x00200000UL)

typedef struct {
	volatile uint32_t GPFSEL[6];
	volatile uint32_t RESV0;
	volatile uint32_t GPSET[2];
	volatile uint32_t RESV1;
	volatile uint32_t GPCLR[2];
	volatile uint32_t RESV2;
	volatile uint32_t GPLEV[2];
	volatile uint32_t RESV3;
	volatile uint32_t GPEDS[2];
	volatile uint32_t RESV4;
	volatile uint32_t GPREN[2];
	volatile uint32_t RESV5;
	volatile uint32_t GPFEN[2];
	volatile uint32_t RESV6;
	volatile uint32_t GPHEN[2];
	volatile uint32_t RESV7;
	volatile uint32_t GPLEN[2];
	volatile uint32_t RESV8;
	volatile uint32_t GPAREN[2];
	volatile uint32_t RESV9;
	volatile uint32_t GPAFEN[2];
	volatile uint32_t RESV10;
	volatile uint32_t GPPUD;
	volatile uint32_t GPPUDCLK[2];
} gpio_typedef;

typedef enum {
	GPIO_FSEL_INPUT 		= 0,
	GPIO_FSEL_OUTPUT 		= 1,
	GPIO_FSEL_ALT0 			= 4,
	GPIO_FSEL_ALT1 			= 5,
	GPIO_FSEL_ALT2 			= 6,
	GPIO_FSEL_ALT3 			= 7,
	GPIO_FSEL_ALT4 			= 3,
	GPIO_FSEL_ALT5 			= 2
} gpio_fsel_typedef;

typedef enum {
	GPIO_PULL_DISABLED 		= 0,
	GPIO_PULL_DOWN	 		= 1,
	GPIO_PULL_UP 			= 2
} gpio_pull_typedef;

extern gpio_typedef *const gpio;

extern void gpio_set_function(uint32_t pin, gpio_fsel_typedef fsel);
extern void gpio_set_pin(uint32_t pin);
extern void gpio_clr_pin(uint32_t pin);
extern bool gpio_get_pin(uint32_t pin);
extern void gpio_set_pin_pull(uint32_t pin, gpio_pull_typedef pull);
