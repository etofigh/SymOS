#include "gpio.h"

gpio_typedef *const gpio = (gpio_typedef*)(GPIO_BASE);

/**
 * @brief Set the function of the GPIO pin to fsel
 * @param pin			The GPIO pin number
 * @param fsel			Function
 */
void gpio_set_function(uint32_t pin, gpio_fsel_typedef fsel)
{
    uint32_t reg = pin / 10;
    uint32_t field = (pin % 10) * 3;

    gpio->GPFSEL[reg] = (gpio->GPFSEL[reg] & ~(0x07UL << field)) | (fsel << field);
}

/**
 * @brief Set the output value of the GPIO pin to 1
 * @param pin		The GPIO pin number
 */
void gpio_set_pin(uint32_t pin)
{
    uint32_t reg = pin / 32;
    uint32_t field = pin % 32;

    gpio->GPSET[reg] |= (1 << field);
}

/**
 * @brief Set the output value of the GPIO pin to 0
 * @param pin		The GPIO pin number
 */
void gpio_clr_pin(uint32_t pin)
{
    uint32_t reg = pin / 32;
    uint32_t field = pin % 32;

    gpio->GPCLR[reg] |= (1 << field);
}

/**
 * @brief Get the current state of the GPIO pin
 * @param pin		The GPIO pin number
 * @return 			The current pin state
 */
bool gpio_get_pin(uint32_t pin)
{
	uint32_t reg = pin / 32;
    uint32_t field = pin % 32;
	
	return ((gpio->GPLEV[reg] >> field) & 0x1);
}

/**
 * @brief Enables or disable the pull-up/down resistor on the selected GPIO pin
 * @param pin		The GPIO pin number
 * @param pull		Disable, enable pull-up, enable pull-down
 */
void gpio_set_pin_pull(uint32_t pin, gpio_pull_typedef pull)
{
    uint32_t reg = pin / 32;
    uint32_t field = pin % 32;
	
	// Select the required control signal
	gpio->GPPUD = pull;
	
	// Wait 150 cycles to provide enough setup-time
	for(volatile int i = 0; i < 150; i++);
	
	// Clock the selected control signal into the specified pin
	gpio->GPPUDCLK[reg] = (1 << field);
	
	// Wait 150 cycles to provide enough hold-time
	for(volatile int i = 0; i < 150; i++);
	
	// Clear clock and control signals
	gpio->GPPUD = 0;
	gpio->GPPUDCLK[reg] = 0;
}