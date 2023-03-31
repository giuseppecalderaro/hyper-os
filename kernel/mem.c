#include <types.h>
#include <video.h>

extern void *_init, *_end_init;
extern void *_text, *_end_text;
extern void *_rodata, *_end_rodata;
extern void *_data, *_end_data;
extern void *_pgd, *_end_pgd;
extern void *_stack, *_end_stack;
extern void *_bss, *_end_bss;
extern void *_end_kernel;

void mem_init(size_t memory)
{
	/* Size returned from grub is in kilobytes.  */
	memory = (memory >> 10) + 1;
	printk("Available memory: %dMb\n", memory);

	printk("init: 0x%x\n", &_init);
	printk("text: 0x%x\n", &_text);
	printk("rodata: 0x%x\n", &_rodata);
	printk("data: 0x%x\n", &_data);
	printk("pgd: 0x%x\n", &_pgd);
	printk("stack: 0x%x\n", &_stack);
	printk("bss: 0x%x\n", &_bss);
	printk("end_kernel: 0x%x\n", &_end_kernel);	
}
