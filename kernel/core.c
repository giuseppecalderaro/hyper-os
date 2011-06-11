#include <compiler.h>
#include <core.h>
#include <irq.h>
#include <mem.h>
#include <multiboot.h>
#include <setup.h>
#include <video.h>

static void halt(void)
{
	asm volatile("nop");
}

static void __noreturn die(void)
{
	for(;;)
		halt();
}

void __asmlinkage __init core(unsigned long magic, struct multiboot_info *info)
{
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
		/* We haven't init video yet.
		   No error message then.  */
		die();
	}	

	init_video();
	printk(KERNEL_VERSION);
	setup_arch();
	mem_init(info->mem_lower + info->mem_upper);

	die();
}
