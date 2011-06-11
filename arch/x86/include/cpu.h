#ifndef __CPU_H__
#define __CPU_H__

#include <compiler.h>
#include <types.h>

static __inline void crash(void)
{
	asm volatile("jmp 0xDEADBEEF");
}

static __inline void load_cr3(address_t address)
{
	asm volatile("mov %0,%%cr3"
		     :
		     : "r" (address));
}
#endif /* __CPU_H__  */
