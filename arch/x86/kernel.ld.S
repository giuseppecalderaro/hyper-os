/* GNU linker script  */
OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")

#include <config.h>

ENTRY(_start)
SECTIONS
{
   /* kernel code */
   .text KERNEL_PHYSICAL : AT(KERNEL_PHYSICAL)
   {
	_init = .;
	*(.init*)
	. = ALIGN(1 << PAGE_SHIFT);
	_end_init = .;

	_text = .;
	*(.text)
	_end_text = .;

	_rodata = .;
	*(.rodata*)
	. = ALIGN(1 << PAGE_SHIFT);
	_end_rodata = .;
   }

   .data : AT(KERNEL_PHYSICAL + (_data - _init))
   {
	_data = .;
	*(.data*);
	. = ALIGN(1 << PAGE_SHIFT);
	_end_data = .;

	_pgd = .;	
	. += (1 << PAGE_SHIFT);
	_end_pgd = .;
   }

   .bss : AT(KERNEL_PHYSICAL + (_bss - _init))
   {
	_end_stack = .;
	. += KERNEL_STACK_SIZE;
	_stack = .;

	. = ALIGN(1 << PAGE_SHIFT);
	_bss = .;
	*(.bss*)
	*(COMMON*)
	. = ALIGN(1 << PAGE_SHIFT);
	_end_bss = .;
   }
   . = ALIGN(1 << PAGE_SHIFT);
   _end_kernel = .;
}
