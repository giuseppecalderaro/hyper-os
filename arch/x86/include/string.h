#ifndef __STRING_H__
#define __STRING_H__

static inline void *__memset(void *s, char c, int count)
{
	int d0, d1;

	asm volatile("rep     \n\t"
		     "stosb"
		     : "=&c" (d0), "=&D" (d1)
		     : "a" (c), "1" (s), "0" (count)
		     : "memory");

	return s;
}

#endif /* __STRING_H__  */
