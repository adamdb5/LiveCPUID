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
  char buffer[9];

  write_string(" LiveCPUID v0.1                 ", 0, 0, FG_BRIGHT_WHITE);
  write_string("(c) Adam Bruce 2022", 60, 0, FG_BRIGHT_WHITE);
  write_string("---------------------------------------------------------------"
               "-----------------",
               0, 1, FG_WHITE);
  current_line = 2;

  /* Query standard functions */
  fn0000_0000(&cpuid);
  if (cpuid.largest_standard_function_number >= 0x1)
    fn0000_0001(&cpuid);
  if (cpuid.largest_standard_function_number >= 0x5)
    fn0000_0005(&cpuid);
  if (cpuid.largest_standard_function_number >= 0x6)
    fn0000_0006(&cpuid);
  if (cpuid.largest_standard_function_number >= 0x7)
    fn0000_0007(&cpuid);
  if (cpuid.largest_standard_function_number >= 0xD)
    fn0000_000D(&cpuid);  

  /* Query extended functions */
  fn8000_0000(&cpuid);
  if (cpuid.largest_extended_function_number >= 0x1)
    fn8000_0001(&cpuid);
  if (cpuid.largest_extended_function_number >= 0x4) {
    fn8000_0002(&cpuid);
    fn8000_0003(&cpuid);
    fn8000_0004(&cpuid);
  }
  if (cpuid.largest_extended_function_number >= 0x5)
    fn8000_0005(&cpuid);
  if (cpuid.largest_extended_function_number >= 0x6)
    fn8000_0006(&cpuid);

  write_string("Vendor: ", 0, current_line, FG_WHITE);
  write_string(cpuid.vendor, 8, current_line, FG_YELLOW);
  write_string("Name: ", 26, current_line, FG_WHITE);
  if (cpuid.largest_extended_function_number >= 0x4)
    write_string(cpuid.processor_name, 32, current_line++, FG_YELLOW);
  else
    write_string("Not Supported", 32, current_line++, FG_YELLOW);

  /* Family, model, stepping */
  if(cpuid.family.base_family != 0xF)
    int_to_string(cpuid.family.base_family, buffer, 16);
  else
    int_to_string(cpuid.family.base_family + cpuid.family.extended_family, buffer, 16);
  write_string("Family:", 0, current_line, FG_WHITE);
  write_string("0x", 8, current_line, FG_YELLOW);
  write_string(buffer, 10, current_line, FG_YELLOW);

  if(cpuid.family.base_family == 0x6 || cpuid.family.base_family == 0xF)
    int_to_string((4 << cpuid.family.extended_model) + cpuid.family.base_model, buffer, 16);
  else
    int_to_string(cpuid.family.base_model, buffer, 16);
  write_string("Model:", 20, current_line, FG_WHITE);
  write_string("0x", 27, current_line, FG_YELLOW);
  write_string(buffer, 29, current_line, FG_YELLOW);

  int_to_string(cpuid.family.stepping, buffer, 16);
  write_string("Stepping:", 40, current_line, FG_WHITE);
  write_string("0x", 50, current_line, FG_YELLOW);
  write_string(buffer, 52, current_line, FG_YELLOW);

  int_to_string(cpuid.family.processor_type, buffer, 2);
  write_string("Type:", 60, current_line, FG_WHITE);
  write_string("0b", 66, current_line, FG_YELLOW);
  write_string(buffer, 68, current_line++, FG_YELLOW);


  write_string("Features:", 0, current_line++, FG_WHITE);
  current_line +=
      write_feature_list(&cpuid.features, current_line,
                         cpuid.largest_extended_function_number > 0x1);

  if (cpuid.largest_extended_function_number >= 0x06) {

    write_string("L1DTlb2and4MAssoc: ", 0, current_line, FG_WHITE);
    int_to_string(cpuid.l1_cache_identifiers.l1dtlb2_and_4m_data_assoc, buffer,
                  10);
    write_string(buffer, 19, current_line++, FG_WHITE);

    write_string("L1DTlb2and4MSize: ", 0, current_line, FG_WHITE);
    int_to_string(cpuid.l1_cache_identifiers.l1dtlb2_and_4m_data_size, buffer,
                  10);
    write_string(buffer, 19, current_line++, FG_WHITE);

    write_string("L2DTlb2and4MAssoc: ", 0, current_line, FG_WHITE);
    int_to_string(cpuid.l2_and_l3_cache_identifiers.l2dtlb2_and_4m_data_assoc,
                  buffer, 10);
    write_string(buffer, 19, current_line++, FG_WHITE);

    write_string("L2DTlb2and4MSize: ", 0, current_line, FG_WHITE);
    int_to_string(cpuid.l2_and_l3_cache_identifiers.l2dtlb2_and_4m_data_size,
                  buffer, 10);
    write_string(buffer, 19, current_line++, FG_WHITE);
  }

  /* Halting causes the BIOS to reboot, so we just keep the CPU busy. */
  while (1)
    ;
}
