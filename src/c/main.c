#include "cpuid.h"
#include "printer.h"
#include "util.h"

/*
 * Function names follow the AMD specification available here:
 * https://www.amd.com/system/files/TechDocs/25481.pdf
 */

/**
 * Entry point from the assembly.
 */
void asm_entry() {
  CPUID cpuid;
  unsigned int current_line = 0;

  write_string("LiveCPUID v0.1                 ", 0, 0, FG_BRIGHT_WHITE);
  write_string("(c) Adam Bruce 2021", 61, 0, FG_BRIGHT_WHITE);
  write_string("---------------------------------------------------------------"
               "-----------------",
               0, 1, FG_WHITE);
  current_line = 2;

  fn0000_0000(&cpuid);
  fn8000_0000(&cpuid);

  if (cpuid.largest_standard_function_number < 0x1)
    goto extended;
  fn0000_0001(&cpuid);
  print_fn0000_0001(&cpuid, &current_line);
  current_line++;

  if (cpuid.largest_standard_function_number < 0x5)
    goto extended;
  fn0000_0005(&cpuid);
  print_fn0000_0005(&cpuid, &current_line);

  if (cpuid.largest_standard_function_number < 0x6)
    goto extended;
  fn0000_0006(&cpuid);

  if (cpuid.largest_standard_function_number < 0x7)
    goto extended;
  fn0000_0007(&cpuid);

  if (cpuid.largest_standard_function_number < 0xD)
    goto extended;
  fn0000_000D(&cpuid);

extended:
  if (cpuid.largest_extended_function_number < 0x4)
    goto halt;
  fn8000_0002(&cpuid);
  fn8000_0003(&cpuid);
  fn8000_0004(&cpuid);

  write_string(cpuid.processor_name, 0, ++current_line, FG_YELLOW);

halt:
  /* busy wait */
  while (1)
    ;
}
