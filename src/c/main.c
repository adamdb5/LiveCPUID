#include <cpuid.h>

#include "util.h"

/* Function names follow the AMD specification available here:
 * https://www.amd.com/system/files/TechDocs/25481.pdf */

/**
 * Largest Standard Function Number and Processor Vendor.
 *
 * \param LFuncStd a pointer to the variable to store the Largest Standard
 * Function Number.
 * \param Vendor a buffer to store the Vendor ID String.
 */
void Fn0000_0000(unsigned int *LFuncStd, char Vendor[13]) {
  Vendor[12] = '\0';
  __get_cpuid(0x0, LFuncStd, (unsigned int *)Vendor,
              (unsigned int *)(Vendor + 8), (unsigned int *)(Vendor + 4));
}

/**
 * Entry point from the assembly.
 */
void asm_entry() {
  unsigned int LFuncStd;
  char Vendor[13], strNum[9];

  Fn0000_0000(&LFuncStd, Vendor);
  write_string("Brand String: ", 0, 0, FG_WHITE);
  write_string(Vendor, 14, 0, FG_CYAN);

  int_to_string(LFuncStd, strNum, 16);
  write_string("Largest Standard Function Number:", 0, 1, FG_WHITE);
  write_string("0x", 34, 1, FG_YELLOW);
  write_string(strNum, 36, 1, FG_YELLOW);
}
