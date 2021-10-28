#ifndef UTIL_H
#define UTIL_H

/* Foreground colours */
#define FG_BLACK 0x00
#define FG_BLUE 0x01
#define FG_GREEN 0x02
#define FG_CYAN 0x03
#define FG_RED 0x04
#define FG_MAGENTA 0x05
#define FG_ORANGE 0x06
#define FG_WHITE 0x07
#define FG_GREY 0x08
#define FG_LIGHT_BLUE 0x09
#define FG_LIGHT_GREEN 0x0A
#define FG_LIGHT_CYAN 0x0B
#define FG_LIGHT_RED 0x0C
#define FG_LIGHT_MAGENTA 0x0D
#define FG_YELLOW 0x0E
#define FG_BRIGHT_WHITE 0x0F

/* Background colours */
#define BG_BLACK 0x00
#define BG_BLUE 0x10
#define BG_GREEN 0x20
#define BG_CYAN 0x30
#define BG_RED 0x40
#define BG_MAGENTA 0x50
#define BG_ORANGE 0x60
#define BG_WHITE 0x70
#define BG_GREY 0x80
#define BG_LIGHT_BLUE 0x90
#define BG_LIGHT_GREEN 0xA0
#define BG_LIGHT_CYAN 0xB0
#define BG_LIGHT_RED 0xC0
#define BG_LIGHT_MAGENTA 0xD0
#define BG_YELLOW 0xE0
#define BG_BRIGHT_WHITE 0xF0

/* Start address of the VGA buffer */
#define VGA_BUFFER_START (unsigned short *)0xB8000

/* Width of the VGA buffer (number of columns) */
#define VGA_BUFFER_WIDTH 0x50

/**
 * Writes a character to the VGA display buffer at the given offset with the
 * given colour.
 *
 * \param c the character to write to the buffer.
 * \param x the x-coordinate to display the character.
 * \param y the y-coordinate to display the character.
 * \param colour the colour of the glyph (foreground | background).
 */
void write_char(const char c, const unsigned short x, const unsigned short y,
                const unsigned char colour);

/**
 * Writes a character array (string) to the VGA display buffer at the given
 * offset with the given colour.
 *
 * \param str the string to write to the buffer.
 * \param x the x-coordinate to display the character.
 * \param y the y-coordinate to display the character.
 * \param colour the colour of the string (foreground | background).
 */
void write_string(const char *str, const unsigned short x,
                  const unsigned short y, const unsigned char colour);

/**
 * Converts an integer to a string, storing the output into the given buffer.
 *
 * \param x the integer to convert.
 * \param buffer the buffer to store the string.
 * \param base the base of the output (bin=2, dec=10, hex=16, ...).
 */
void int_to_string(const int x, char buffer[9], const int base);

/**
 * Reverses a string, storing the output into the source buffer.
 *
 * \param buffer the buffer containing the string, and the output destination.
 * \param length the length of the string.
 */
void reverse_string(char *buffer, const unsigned int length);

#endif /* UTIL_H */
