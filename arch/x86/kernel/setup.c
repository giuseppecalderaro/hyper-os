#include <cpu.h>
#include <gdt.h>
#include <mm.h>
#include <page.h>

void setup_arch(void)
{
	segment_init();
	paging_init();

	init_mm._text = _text;
	init_mm._end_text = _end_text;
	init_mm._rodata = _rodata;
	init_mm._end_rodata = _end_rodata;
	init_mm._data = _data;
	init_mm._end_data = _end_data;
	init_mm._bss = _end_kernel;
}
