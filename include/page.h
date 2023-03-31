#ifndef __PAGE_H__
#define __PAGE_H__

#include <config.h>

#define virt_to_phys(x) (x - KERNEL_VIRTUAL)
#define phys_to_virt(x) (x + KERNEL_VIRTAUL)

void paging_init(void);

#endif /* __PAGE_H__  */
