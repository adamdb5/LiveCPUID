#include "features.h"
#include "util.h"

const char *feature_names[] = {
    "RAZ",     "F16C",       "AVX",    "OSXSAVE",
    "XSAVE",   "AES",        "POPCNT", "SSE42",
    "SSE41",   "CMPXCHG16B", "FMA",    "SSSE3",
    "MONITOR", "PCLMULQDC",  "SSE3",   "HTT",
    "SSE2",    "SSE",        "FXSR",   "MMX",
    "CLFSH",   "PSE36",      "PAT",    "CMOV",
    "MCA",     "PGE",        "MTRR",   "SYSENTERSYSEXIT",
    "APIC",    "CMPXCHG8B",  "MCE",    "PAE",
    "MSR",     "TSC",        "PSE",    "DE",
    "VME",     "FPU"};

const unsigned char feature_name_lengths[] = {
    3, 4, 3, 7, 5, 3, 6, 5, 5,  10, 3, 5, 7, 9, 4, 3, 4, 3, 4,
    3, 5, 5, 3, 4, 3, 3, 4, 15, 4,  9, 3, 3, 3, 3, 3, 2, 3, 3};

void write_feature_list(Features *features, unsigned short y) {
  unsigned short used_width = 0;
  unsigned short current_y_pos = y;

  write_string("Supported Features:", 0, current_y_pos++, FG_WHITE);
  if (features->fpu) {
    used_width = used_width + feature_name_lengths[FPU] <= VGA_BUFFER_WIDTH
                     ? used_width + feature_name_lengths[FPU]
                     : 0;
    write_string(feature_names[FPU], used_width++, current_y_pos, FG_WHITE);
  }
  if (features->vme) {
    used_width = used_width + feature_name_lengths[VME] <= VGA_BUFFER_WIDTH
                     ? used_width + feature_name_lengths[VME]
                     : 0;
    write_string(feature_names[VME], used_width++, current_y_pos, FG_WHITE);
  }
}
