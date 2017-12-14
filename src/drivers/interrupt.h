#pragma once

#include "rpi.h"

#define INTERRUPT_BASE (PERIPHERAL_BASE + 0x0000B200UL)

typedef struct {
	volatile uint32_t IRQ_BASIC_PENDING;
	volatile uint32_t IRQ_PENDING[2];
	volatile uint32_t FIQ_CTRL;
	volatile uint32_t IRQ_EN[2];
	volatile uint32_t IRQ_BASIC_EN;
	volatile uint32_t IRQ_DIS[2];
	volatile uint32_t IRQ_BASIC_DIS;
} INTERRUPT_TypeDef;

typedef enum {
	IRQ_TIMER        		= (1 << 0),
    IRQ_MAILBOX      		= (1 << 1),
    IRQ_DOORBELL_0   		= (1 << 2),
    IRQ_DOORBELL_1   		= (1 << 3),
    IRQ_GPU_0_HALTED     	= (1 << 4),
    IRQ_GPU_1_HALTED 		= (1 << 5),
    IRQ_ILLEGAL_ACCESS_1 	= (1 << 6),
    IRQ_ILLEGAL_ACCESS_0 	= (1 << 7)
} INTERRUPT_BASIC_TypeDef;

extern INTERRUPT_TypeDef *const INTERRUPT;

#define INTERRUPT_EnableBasicIRQ(irq)		INTERRUPT->IRQ_BASIC_EN = (irq)
#define INTERRUPT_DisableBasicIRQ(irq)		INTERRUPT->IRQ_BASIC_DIS = (irq)
#define INTERRUPT_IsBasicIRQPending(irq)	(INTERRUPT->IRQ_BASIC_PENDING & (irq))

void INTERRUPT_EnableIRQInterrupts();
void INTERRUPT_DisableIRQInterrupts();
