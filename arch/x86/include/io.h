#ifndef __IO_H__
#define __IO_H__

#include <compiler.h>
#include <config.h>
#include <types.h>

static __inline void io_delay(void)
{
	__asm__ __volatile__("outb %al,$0x80");
}

static __inline void outb(u8 value, u16 port)
{
	__asm__ __volatile__ ("outb %0, %1"
			      :
			      : "a" (value), "d" (port));
}

static __inline void outw(u16 value, u16 port)
{
	__asm__ __volatile__ ("outw %0, %1"
			      :
			      : "a" (value), "d" (port));
}

static __inline void outl(u32 value, u16 port)
{
	__asm__ __volatile__ ("outl %0, %1"
			      :
			      : "a" (value), "d" (port));
}

static __inline void outb_p(u8 value, u16 port)
{
	__asm__ __volatile__ ("outb %0, %1"
			      :
			      : "a" (value), "d" (port));
	io_delay();
}

static __inline void outw_p(u8 value, u16 port)
{
	__asm__ __volatile__ ("outw %0, %1"
			      :
			      : "a" (value), "d" (port));
	io_delay();
}

static __inline void outl_p(u32 value, u16 port)
{
	__asm__ __volatile__ ("outl %0, %1"
			      :
			      : "a" (value), "d" (port));
	io_delay();
}
#endif /* __IO_H__  */
