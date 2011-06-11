#ifndef __MULTIBOOT_H__
#define __MULTIBOOT_H__

#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MULTIBOOT_HEADER_FLAGS 0x00010007
#define MULTIBOOT_BOOTLOADER_MAGIC 0x2BADB002

#ifndef ASM
struct aout_symbol_table {
	unsigned long tab_size;
	unsigned long str_size;
	unsigned long address;
	unsigned long reserved;	
};

struct elf_section_header_table {
	unsigned long num;
	unsigned long size;
	unsigned long address;
	unsigned long shndx;
};

struct multiboot_info {
	unsigned long flags;
	unsigned long mem_lower;
	unsigned long mem_upper;
	unsigned long boot_device;
	unsigned long cmdline;
	unsigned long mods_addr;
	union {
		struct aout_symbol_table aout_sym;
		struct elf_section_header_table elf_sec_t;
	} u;
	unsigned long mmap_length;
	unsigned long mmap_addr;
};
#endif /* ASM  */

#endif /* __MULTIBOOT_H__  */
