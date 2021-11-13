#include "cpuid.h"
#include "printer.h"
#include "util.h"
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

//  if (cpuid.largest_standard_function_number < 0x1)
//    goto extended;
  fn0000_0001(&cpuid);
  print_fn0000_0001(&cpuid, &current_line);

//  if (cpuid.largest_standard_function_number < 0x5)
//    goto extended;
  fn0000_0005(&cpuid);
  print_fn0000_0005(&cpuid, &current_line);

//  if (cpuid.largest_standard_function_number < 0x6)
//    goto extended;
  fn0000_0006(&cpuid);

//  if (cpuid.largest_standard_function_number < 0x7)
//    goto extended;
  fn0000_0007(&cpuid);

//  if (cpuid.largest_standard_function_number < 0xD)
//    goto extended;
  fn0000_000D(&cpuid);

//extended:
  write_string("Executing fn8000_0000", 0, 9, FG_ORANGE);
  fn8000_0000(&cpuid);
//  if(cpuid.largest_extended_function_number < 0x1)
;//    goto halt;
  fn8000_0001(&cpuid);
  current_line = 10;
  print_fn8000_0001(&cpuid, &current_line);

halt:
  /* busy wait */
  while(1);

}
