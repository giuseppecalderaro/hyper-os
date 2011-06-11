void arch_local_irq_enable(void)
{
	asm volatile("sti"
		     :
		     :
		     : "memory");
}

void arch_local_irq_disable(void)
{
	asm volatile("cli"
		     :
		     :
		     : "memory");
}
