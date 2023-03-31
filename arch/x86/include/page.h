#ifndef __PAGE_H__
#define __PAGE_H__

#include <config.h>

#define PAGE_SIZE (1 << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE - 1))

#endif /* __PAGE_H__  */
