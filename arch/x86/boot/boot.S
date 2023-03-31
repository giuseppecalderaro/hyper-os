#include <config.h>
#include <multiboot.h>
	
.global _start
.extern _stack
	
.section .init
_start:
	jmp multiboot_entry
	.align 4

multiboot_header:
	.long MULTIBOOT_HEADER_MAGIC
	.long MULTIBOOT_HEADER_FLAGS
	.long -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
	.long multiboot_header
	.long _start
	.long _end_data
	.long _end_kernel
	.long multiboot_entry

	.align 4
multiboot_entry:
	movl $_stack, %esp
	pushl $0
	popf
	pushl %ebx
	pushl %eax
	call core

	pushl $haltstring
	call printk

loop:
	hlt
	jmp loop

haltstring: .asciz "BUG - Returned from main\n"
