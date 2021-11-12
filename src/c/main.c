#include "cpuid.h"
#include "printer.h"

/* Function names follow the AMD specification available here:
 * https://www.amd.com/system/files/TechDocs/25481.pdf
 */

/**
 * Entry point from the assembly.
 */
void asm_entry() {
  CPUID cpuid;
  unsigned int current_line = 0;

  fn0000_0000(&cpuid);

  if (cpuid.largest_standard_function_number < 0x1)
    return;
  fn0000_0001(&cpuid);
  print_fn0000_0001(&cpuid, &current_line);

  if (cpuid.largest_standard_function_number < 0x5)
    return;
  fn0000_0005(&cpuid);
  print_fn0000_0005(&cpuid, &current_line);

  if (cpuid.largest_standard_function_number < 0x6)
    return;
  fn0000_0006(&cpuid);

  if (cpuid.largest_standard_function_number < 0x7)
    return;
  fn0000_0007(&cpuid);

  if (cpuid.largest_standard_function_number < 0xD)
    return;
  fn0000_000D(&cpuid);
}
