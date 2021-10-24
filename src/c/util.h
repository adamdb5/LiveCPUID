#ifndef UTIL_H
#define UTIL_H

#include "types.h"

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
#define VGA_BUFFER_START (uint16_t *)0xB8000

/* Width of the VGA buffer (number of columns) */
#define VGA_BUFFER_WIDTH 0x50

/**
 * Writes a character to the VGA display buffer at the given offset with the
 * given colour.
 */
void write_char(const char c, const uint16_t x, const uint16_t y,
                const uint8_t colour);

/**
 * Writes a character array (string) to the VGA display buffer at the given
 * offset with the given colour.
 */
void write_string(const char *str, const uint16_t x, const uint16_t y,
                  const uint8_t colour);

#endif /* UTIL_H */
