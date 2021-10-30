#include "features.h"
#include "util.h"

const unsigned int feature_to_mask[] = {
    MASK_RAZ,     MASK_F16C,       MASK_AVX,    MASK_OSXSAVE,
    MASK_XSAVE,   MASK_AES,        MASK_POPCNT, MASK_SSE42,
    MASK_SSE41,   MASK_CMPXCHG16B, MASK_FMA,    MASK_SSSE3,
    MASK_MONITOR, MASK_PCLMULQDQ,  MASK_SSE3,   MASK_HTT,
    MASK_SSE2,    MASK_SSE,        MASK_FXSR,   MASK_MMX,
    MASK_CLFSH,   MASK_PSE36,      MASK_PAT,    MASK_CMOV,
    MASK_MCA,     MASK_PGE,        MASK_MTRR,   MASK_SYSENTERSYSEXIT,
    MASK_APIC,    MASK_CMPXCHG8B,  MASK_MCE,    MASK_PAE,
    MASK_MSR,     MASK_TSC,        MASK_PSE,    MASK_DE,
    MASK_VME,     MASK_FPU,
};

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

void _print_next_feature(unsigned int feature_id, unsigned short *used_width,
                         unsigned short *current_y) {
  if (*used_width + feature_name_lengths[feature_id] > VGA_BUFFER_WIDTH) {
    (*current_y)++;
    *used_width = 0;
  }
  write_string(feature_names[feature_id], *used_width, *current_y, FG_WHITE);
  write_char(' ', *used_width + feature_name_lengths[feature_id] + 1,
             *current_y, FG_WHITE);
  *used_width = *used_width + feature_name_lengths[feature_id] + 1;
}

void write_feature_list(Features *features, unsigned short y) {
  unsigned short used_width = 0;
  unsigned short current_y_pos = y;
  unsigned int feature_id;

  write_string("Supported Features:", 0, current_y_pos++, FG_WHITE);

  /* ECX features */
  for (feature_id = 0; feature_id < ECX_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0001_ecx & feature_to_mask[feature_id])
      _print_next_feature(feature_id, &used_width, &current_y_pos);
  }

  /* EDX features */
  for (feature_id = 0; feature_id < EDX_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0001_edx & feature_to_mask[feature_id])
      _print_next_feature(feature_id + ECX_FEATURE_COUNT, &used_width,
                          &current_y_pos);
  }
}
