#include <io.h>
#include <string.h>
#include <types.h>
#include <video.h>

static u16 *video = (u16 *)VIDEO_MEM_ADDRESS;
static u8 current_color = LIGHT_GREY;
static int xpos;
static int ypos;
u16 cursor;

static void update_cursor(void)
{
	cursor = xpos + COLUMNS * ypos;

	outb_p(VIDEO_CURSOR_LO, VIDEO_INDEX);
	outb_p((u8)cursor, VIDEO_DATA);
	outb_p(VIDEO_CURSOR_HI, VIDEO_INDEX);
	outb_p((u8)(cursor >> 8), VIDEO_DATA);
}

static void clear_screen(void)
{
	__memset((void *)VIDEO_MEM_ADDRESS, 0, COLUMNS * ROWS * 2);
	
	xpos = 0;
	ypos = 0;
}

static void newline(void)
{
	xpos = 0;
	ypos += 1;
}

static void video_putchar(u8 ch)
{
	switch (ch) {
	case '\n':
	case '\r':
		newline();
		break;
	case '\t':
		/* Tab handling goes here.  */
		break;
	default:
		*(video + cursor) = (current_color << 8) | ch;
		if (++xpos >= COLUMNS)
			newline();
		break;
	}
	update_cursor();       
}

static char *itoa (int value, char *buffer, int base)
{
	char *ptr = buffer;
	char *ptr_swap = buffer;
	char tmp_char;
	int tmp_value;

	if (base < 2 || base > 36) {
		*buffer = '\0';
		goto out;
	}

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );
	
	if (tmp_value < 0) 
		*ptr++ = '-';
	*ptr-- = '\0';
	
	while(ptr_swap < ptr) {
		tmp_char = *ptr;
		*ptr-- = *ptr_swap;
		*ptr_swap++ = tmp_char;
	}
out:
	return buffer;
}

void printk(const char *format, ...)
{
	char **arg = ((char **)&format) + 1;
	char ch;
	char buffer[32];

	while(ch = *format++) {
		switch (ch) {
		case '%':
			switch (*format++) {
			case 'd':
			case 'u':
				itoa(*((int *)arg++), buffer, 10);
				break;
			case 'x':
				itoa(*((int *)arg++),  buffer, 16);
				break;
			}
			printk(buffer);
			break;
		default:
			video_putchar(ch);
			break;
		}
	}
}

void __init init_video(void)
{
	clear_screen();
	update_cursor();
}
