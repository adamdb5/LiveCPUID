#include <cpuid.h>

#include "types.h"
#include "util.h"

void asm_entry() {
  uint32_t a;
  char name[13];

  /* CPUID Brand String */
  name[12] = '\0';
  __get_cpuid(0x0, &a, (uint32_t *)name, (uint32_t *)(name + 8),
              (uint32_t *)(name + 4));

  write_string("Brand String: ", 0, 0, FG_WHITE);
  write_string(name, 14, 0, FG_CYAN);
}
