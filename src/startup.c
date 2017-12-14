extern int __bss_start__;
extern int __bss_end__;

extern void kernel_main(unsigned int r0, unsigned int r1, unsigned int atags);

void _cstartup(unsigned int r0, unsigned int r1, unsigned int r2)
{
    // __bss_start__ and __bss_end__ are defined in the linker script
    int *bss = &__bss_start__;
    int *bss_end = &__bss_end__;

    // Clear the BSS section
    while (bss < bss_end)
        *bss++ = 0;

    kernel_main(r0, r1, r2);

    // We should never return from main, but if we do safely trap here
    while (1);
}