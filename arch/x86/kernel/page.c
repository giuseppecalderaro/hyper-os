#include <page.h>
#include <types.h>

extern address_t _pgd;

static void page_tables_init(void)
{

}

static void load_cr3(void)
{

}

void paging_init(void)
{
	page_tables_init();

	load_cr3();
}
