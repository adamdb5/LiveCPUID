#include "util.h"

void write_char(const char c, const unsigned short x, const unsigned short y,
                const unsigned char colour) {
  unsigned short glyph = (c | (colour << 8));
  unsigned short *ptr = VGA_BUFFER_START + (y * VGA_BUFFER_WIDTH) + x;
  *ptr = glyph;
}

void write_string(const char *str, const unsigned short x,
                  const unsigned short y, const unsigned char colour) {
  unsigned short i = 0;
  while (str[i] != '\0') {
    write_char(str[i], x + i, y, colour);
    i++;
  }
}

void int_to_string(const int x, char buffer[9], const int base) {
  int i = 0;
  int num = x;
  unsigned char is_negative = 0;

  if (num == 0) {
    buffer[0] = '0';
    buffer[1] = '\0';
    return;
  }

  if (num < 0) {
    is_negative = 1;
    num -= num;
  }

  while (num != 0) {
    int remainder = num % base;
    buffer[i++] = (remainder > 9) ? (remainder - 10) + 'A' : remainder + '0';
    num /= base;
  }

  if (is_negative)
    buffer[i++] = '-';

  buffer[i] = '\0';
  reverse_string(buffer, i);
}

void reverse_string(char *buffer, const unsigned int length) {
  unsigned int i = 0;
  unsigned int j = length - 1;
  char temp;

  while (i < j) {
    temp = buffer[j];
    buffer[j] = buffer[i];
    buffer[i] = temp;
    i++;
    j--;
  }
}
