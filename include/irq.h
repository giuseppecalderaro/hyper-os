#ifndef __IRQ_H__
#define __IRQ_H__

#include <compiler.h>

void arch_local_irq_enable(void);

static __inline void local_irq_enable(void)
{
	arch_local_irq_enable();
}

static __inline void local_irq_disable(void)
{
	arch_local_irq_enable();
}

#endif /* __IRQ_H__  */
