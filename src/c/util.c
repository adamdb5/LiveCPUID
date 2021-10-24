#include "util.h"
#include "types.h"

void write_char(const char c, const uint16_t x, const uint16_t y,
                const uint8_t colour) {
  uint16_t glyph = (c | (colour << 8));
  uint16_t *ptr = VGA_BUFFER_START + (y * VGA_BUFFER_WIDTH) + x;
  *ptr = glyph;
}

void write_string(const char *str, const uint16_t x, const uint16_t y,
                  const uint8_t colour) {
  uint16_t i = 0;
  while (str[i] != '\0') {
    write_char(str[i], x + i, y, colour);
    i++;
  }
}