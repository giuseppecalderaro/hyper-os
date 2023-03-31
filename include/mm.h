#ifndef __MM_H__
#define __MM_H__

#include <types.h>

struct vma {
	address_t start;
};

struct mm {
	struct vma *mmap;
	address_t pgd;
	address_t _text, _end_text;
	address_t _rodata, _end_rodata;
	address_t _data, _end_data;
	address_t _bss;
};

/* Defined in the linker script.  */
extern address_t _text, _end_text;
extern address_t _rodata, _end_rodata;
extern address_t _data, _end_data;
extern address_t _end_kernel;

extern struct mm init_mm;

#endif /* __MM_H__  */
