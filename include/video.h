#ifndef __VIDEO_H__
#define __VIDEO_H__

#define VIDEO_MEM_ADDRESS 0x000B8000
#define VIDEO_INDEX       0x03D4
#define VIDEO_DATA        0x03D5
#define VIDEO_CURSOR_SR   0x0A
#define VIDEO_CURSOR_LO   0x0F
#define VIDEO_CURSOR_HI   0x0E 

/* Video colors.  */
#define BLACK 			0x00 //!< Black color.
#define BLUE			0x01 //!< Blue color.
#define GREEN			0x02 //!< Green color.
#define CYAN			0x03 //!< Cyan color.
#define RED	 		0x04 //!< Red color.
#define MAGENTA			0x05 //!< Magenta color.
#define BROWN	 		0x06 //!< Brown color.
#define LIGHT_GREY		0x07 //!< Light grey color.
#define GREY			0x08 //!< Grey color.
#define LIGHT_BLUE		0x09 //!< Light blue color.
#define LIGHT_GREEN		0x0A //!< Light green color.
#define LIGHT_CYAN		0x0B //!< Light cyan color.
#define LIGHT_RED		0x0C //!< Light red color.
#define LIGHT_MAGENTA		0x0D //!< Light magenta color.
#define YELLOW			0x0E //!< Yellow color.
#define WHITE			0x0F //!< White color.

/* Blank character.  */
#define BLANK             (0x20 | LIGHT_GREY << 8)

/* Screen size.  */
#define ROWS    25
#define COLUMNS 80

void init_video(void);
void printk(const char *format, ...);

#endif /* __VIDEO_H__  */
