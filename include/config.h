#ifndef __CONFIG_H__
#define __CONFIG_H__

#define KERNEL_VIRTUAL     0xC0000000
#define KERNEL_PHYSICAL    0x00100000
#define PAGE_SHIFT         12
#define KERNEL_STACK_PAGES 2
#define KERNEL_STACK_SIZE  (KERNEL_STACK_PAGES * (1 << PAGE_SHIFT))

#endif /* __CONFIG_H__  */
