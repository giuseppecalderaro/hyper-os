#ifndef __GDT_H__
#define __GDT_H__

#include <compiler.h>
#include <types.h>

#define GDT_ENTRIES 8192
#define SEGMENT_INDEX(x) (x >> 3)
typedef enum {
	dummy_seg = 0x00,
	kernel_code_seg = 0x08,
	kernel_data_seg = 0x10,
	user_code_seg = 0x18,
	user_data_seg = 0x20,
} segments;

typedef enum {
	read_write = 0x2,	
	execute_read = 0xa,
} segment_type;

typedef enum {
	/* S  */
	flag_system = 0,
	flag_codedata = 1,
	/* DPL  */
	flag_ring0 = 0,
	flag_ring1 = 1,
	flag_ring2 = 2,
	flag_ring3 = 3,
	/* P  */
	flag_not_present = 0,
	flag_present = 1,
	/* AVL  */
	flag_not_avl = 0,
	flag_avl = 1,
	/* L  */
	flag_not_l =0,
	flag_l = 1,
	/* D  */
	flag_not_d = 0,
	flag_d = 1,
	/* G  */
	flag_not_g = 0,
	flag_g = 1,
} segment_flags;

struct gate_desc {
	u16 limit0;
	u16 base0;
	u16 base1 : 8;
	u16 type  : 4;
	u16 s     : 1;
	u16 dpl   : 2;
	u16 p     : 1;
	u16 limit : 4;
	u16 avl   : 1;
	u16 l     : 1;
	u16 d     : 1;
	u16 g     : 1;
	u16 base2 : 8;
} __packed;

struct gate_desc_ptr {
	u16 size;
	address_t address;
} __packed;

void segment_init(void);

#endif /* __GDT_H__  */
