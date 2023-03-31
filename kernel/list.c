#include <list.h>

#define new_list(name) \
	struct list_head *name = { &(name), &(name) }

void list_add(struct list_head *new, struct list_head *head)
{
	struct list_head *next = head->next;

	next->prev = new;
	new->next = next;
	new->prev = head;	
	head->next = new;
}

void list_add_tail(struct list_head *new, struct list_head *head)
{
	list_add(new, head->prev);
}

void list_del(struct list_head *old)
{
	struct list_head *next = old->next;
	struct list_head *prev = old->prev;

	next->prev = prev;
	prev->next = next;
}
