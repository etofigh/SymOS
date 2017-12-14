OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SEARCH_DIR("=/usr/local/lib");
SEARCH_DIR("=/lib");
SEARCH_DIR("=/usr/lib");

ENTRY(_start)

SECTIONS
{
	. = 0x8000;
	__stack_top__ = .;
	
	.text : { *(.text.startup) *(.text) }
	.data : { *(.data) }
	
	__bss_start__ = .;
	.bss : { *(.bss) }
	__bss_end__ = .;
}
