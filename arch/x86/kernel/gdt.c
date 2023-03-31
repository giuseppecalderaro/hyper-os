#include <gdt.h>
#include <types.h>

static struct gate_desc gates[GDT_ENTRIES];
static struct gate_desc_ptr gates_ptr;

static __inline void gdt_entry_init(struct gate_desc *desc, 
				    u32 base,
				    u32 limit, 
				    segment_type type, 
				    u16 s, 
				    u16 dpl,
				    u16 p,
				    u16 avl,
				    u16 l,
				    u16 d,
				    u16 g)
{
	desc->limit0 = limit & 0x0000FFFF;
	desc->base0  = base & 0x0000FFFF;
	desc->base1  = (base & 0x00FF0000) >> 16;
	desc->type   = type & 0xF;
	desc->s      = s & 0x1;
	desc->dpl    = dpl & 0x3;
	desc->p      = p & 0x1;
	desc->limit  = (limit & 0x000F0000) >> 16;
	desc->avl    = avl & 0x1;
	desc->l      = l & 0x1;
	desc->d      = d & 0x1;
	desc->g      = g & 0x1;
	desc->base2  = (base & 0xFF000000) >> 24;
}

static void load_gdt(void)
{
	gates_ptr.size = (u16)(GDT_ENTRIES * 8 - 1);
	gates_ptr.address = (address_t)gates;

	asm volatile("lgdt %0                \n\t"
		     "ljmp %1,$1f            \n\t"
		     "1: movw %2,%%bx        \n\t"
		     "movw %%bx,%%ds         \n\t"
		     "movw %%bx,%%es         \n\t"
		     "movw %%bx,%%fs         \n\t"
		     "movw %%bx,%%gs         \n\t"
		     :
		     :"m" (gates_ptr), 
		      "i" (kernel_code_seg),
		      "i" (kernel_data_seg)
		);
}

void segment_init(void)
{
	/* Dummy segment.  */
	gdt_entry_init(&gates[SEGMENT_INDEX(dummy_seg)], 
		       0, 0, 0, 0, 0, 
		       0, 0, 0, 0, 0);
	/* Kernel code segment.  */
	gdt_entry_init(&gates[SEGMENT_INDEX(kernel_code_seg)], 
		       0x00000000, /* base  */
		       0xFFFFF,    /* limit  */
		       execute_read,
		       flag_codedata,
		       flag_ring0,
		       flag_present,
		       flag_not_avl,
		       flag_not_l,
		       flag_d,
		       flag_g 
		);
	/* Kernel data segment.  */
	gdt_entry_init(&gates[SEGMENT_INDEX(kernel_data_seg)],
		       0x00000000, /* base  */
		       0xFFFFF,    /* limit  */
		       read_write,
		       flag_codedata,
		       flag_ring0,
		       flag_present,
		       flag_not_avl,
		       flag_not_l,
		       flag_d,
		       flag_g
		);
	/* User code segment.  */
	gdt_entry_init(&gates[SEGMENT_INDEX(user_code_seg)],
		       0x00000000, /* base  */
		       0xFFFFF,    /* limit  */
		       execute_read,
		       flag_codedata,
		       flag_ring3,
		       flag_present,
		       flag_not_avl,
		       flag_not_l,
		       flag_d,
		       flag_g
		);		       
	/* User data segment.  */
	gdt_entry_init(&gates[SEGMENT_INDEX(user_data_seg)],
		       0x00000000, /* base  */
		       0xFFFFF,    /* limit  */
		       read_write,
		       flag_codedata,
		       flag_ring3,
		       flag_present,
		       flag_not_avl,
		       flag_not_l,
		       flag_d,
		       flag_g
		);		       
	
	load_gdt();
}
