#include "printer.h"
#include "util.h"

void print_fn0000_0001(CPUID *cpuid, unsigned int *current_line) {
  char lsfn_string[9];
  write_string("Brand String: ", 0, *current_line, FG_WHITE);
  write_string(cpuid->vendor, 14, *current_line, FG_GREEN);
  int_to_string((int)cpuid->largest_standard_function_number, lsfn_string, 10);
  write_string("Largest Standard Function Number:", 40, *current_line,
               FG_WHITE);
  write_string(lsfn_string, 74, *current_line, FG_YELLOW);
  (*current_line)++;
  *current_line +=
      write_feature_list(&cpuid->features, *current_line,
                         cpuid->largest_extended_function_number > 0x1) +
      1;
}

void print_fn0000_0005(CPUID *cpuid, unsigned int *current_line) {
  unsigned int str_len_a, str_len_b;
  char num_string[9];
  str_len_a = int_to_string(cpuid->monitor_mwait_features.monitor_line_size_min,
                            num_string, 10);
  write_string("Monitor line size: (min: ", 0, *current_line, FG_WHITE);
  write_string(num_string, 25, *current_line, FG_CYAN);
  write_string(", max: ", 25 + str_len_a, *current_line, FG_WHITE);
  str_len_b = int_to_string(cpuid->monitor_mwait_features.monitor_line_size_max,
                            num_string, 10);
  write_string(num_string, 26 + str_len_a + 6, *current_line, FG_CYAN);
  write_char(')', 25 + str_len_a + 7 + str_len_b, *current_line, FG_WHITE);
  (*current_line)++;
}

void print_fn8000_0001(CPUID *cpuid, unsigned int *current_line) {
  char num_string[9];

  write_string("Largest Extended Function Number: ", 0, *current_line,
               FG_WHITE);
  int_to_string((int)cpuid->largest_extended_function_number, num_string, 10);
  write_string(num_string, 35, *current_line, FG_MAGENTA);
  (*current_line)++;
}
