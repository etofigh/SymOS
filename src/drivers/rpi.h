#pragma once

/* Processor constants */
#define PERIPHERAL_BASE 	0x20000000UL
#define SYS_FREQ			250000000UL

/* Hardware constant */
#define GPIO_LED			16
#define GPIO_UART_TX		14
#define GPIO_UART_RX		15
#define GPIO_EMMC_CD    	47
#define GPIO_EMMC_CLK   	48
#define GPIO_EMMC_CMD   	49
#define GPIO_EMMC_DAT0  	50
#define GPIO_EMMC_DAT1  	51
#define GPIO_EMMC_DAT2  	52
#define GPIO_EMMC_DAT3  	53

/* Assembly macros */
#define SVC(code) 			asm volatile("SVC %0\n" : : "I" (code))
#define ReadCPSR(reg)		asm volatile("MRS %0, CPSR\n" : "=r" (reg) :)
#define ReadSCTRL(reg)		asm volatile("MRC p15, 0, %0, c1, c0, 0\n" : "=r" (reg) :)
#define ReadVBAR(reg)		asm volatile("MRC p15, 0, %0, c12, c0, 0\n" : "=r" (reg) :)

/* Type definitions */
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

typedef enum {
	true				= 1,
	false				= 0
} bool;

/* Peripheral headers */
// #include "stdio.h"
#include "gpio.h"
// #include "systimer.h"
// #include "timer.h"
// #include "interrupt.h"
// #include "auxiliaries.h"
// #include "emmc.h"
