.section ".text.startup"

.global _start
.global _get_stack_pointer

_exception_handlers:
    ldr 	pc, _reset_vector
    ldr 	pc, _undefined_vector
    ldr 	pc, _swi_vector
    ldr 	pc, _prefetch_vector
    ldr 	pc, _data_vector
    ldr 	pc, _reserved_vector
    ldr 	pc, _irq_vector
    ldr 	pc, _fiq_vector

_reset_vector:     .word _start
_undefined_vector: .word undefined_instruction
_swi_vector:       .word software_interrupt
_prefetch_vector:  .word prefetch_abort
_data_vector:      .word data_abort
_reserved_vector:  .word _start
_irq_vector:       .word irq
_fiq_vector:       .word fiq
	
_start:
    // Copy the exception handlers to 0x0000
    ldr 	r0, =_exception_handlers
    mov 	r1, #0x0000
    ldmia 	r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
    stmia 	r1!,{r2,r3,r4,r5,r6,r7,r8,r9}
    ldmia 	r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
    stmia 	r1!,{r2,r3,r4,r5,r6,r7,r8,r9}

	// Set the stack pointer, which progresses downwards through memory
    mov 	sp, #0x8000

    // Run the c startup function. It should not return and will call kernel_main
    b 		_cstartup

_inf_loop:
    b		_inf_loop

_get_stack_pointer:
    // Return the stack pointer value
    str		sp, [sp]
    ldr		r0, [sp]

    // Return from the function
    mov		pc, lr
