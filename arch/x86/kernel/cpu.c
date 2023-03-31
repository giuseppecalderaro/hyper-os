#include <compiler.h>
#include <cpu.h>
#include <gdt.h>
#include <types.h>

static struct gate_desc[GDT_ENTRIES];

static init_gdt_entry(u16 limit, u32 base, u8 attribs0_7, u8 attribs8_15)
{
	
}

static void __init init_gdt(void)
{


	load_gdt(0);
}
