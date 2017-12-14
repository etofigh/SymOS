#include "interrupt.h"

INTERRUPT_TypeDef* const INTERRUPT = (INTERRUPT_TypeDef*)(INTERRUPT_BASE);

void INTERRUPT_EnableIRQInterrupts()
{
    uint32_t myCPSR;
    asm volatile("MRS %[myCPSR], CPSR				\n\t" /* Get current program status */
                 "BIC %[myCPSR], %[myCPSR], #0x80	\n\t" /* Clear IRQ disable bit flag */
                 "MSR CPSR_c, %[myCPSR]				\n\t" /* Store updated program status */
                 : [myCPSR] "=r"(myCPSR));
}

void INTERRUPT_DisableIRQInterrupts()
{
    uint32_t myCPSR;
    asm volatile("MRS %[myCPSR], CPSR				\n\t" /* Get current program status */
                 "ORR %[myCPSR], %[myCPSR], #0x80	\n\t" /* Set IRQ disable bit flag */
                 "MSR CPSR_c, %[myCPSR]				\n\t" /* Store updated program status */
                 : [myCPSR] "=r"(myCPSR));
}

void __attribute__((interrupt("UNDEF"))) undefined_instruction(void)
{

}

void __attribute__((interrupt("SWI"))) software_interrupt(void)
{

}

void __attribute__((interrupt("ABORT"))) prefetch_abort(void)
{

}

void __attribute__((interrupt("ABORT"))) data_abort(void)
{

}

void __attribute__((interrupt("IRQ"))) irq(void)
{

}

void __attribute__((interrupt("FIQ"))) fiq(void)
{

}
