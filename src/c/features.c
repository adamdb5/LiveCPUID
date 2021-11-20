#include "features.h"
#include "util.h"

const unsigned int standard_feature_to_mask[] = {
    MASK_RDRND,      MASK_F16C,        MASK_AVX,    MASK_OSXSAVE, MASK_XSAVE,
    MASK_AESNI,      MASK_TSCDEADLINE, MASK_POPCNT, MASK_MOVBE,   MASK_SSE42,
    MASK_SSE41,      MASK_DCA,         MASK_PCID,   MASK_PDCM,    MASK_XTPR,
    MASK_CMPXCHG16B, MASK_FMA,         MASK_CNXTID, MASK_SSSE3,   MASK_TM2,
    MASK_EIST,       MASK_SMX,         MASK_VMX,    MASK_DSCPL,   MASK_MONITOR,
    MASK_DTES64,     MASK_PCLMULQDQ,   MASK_SSE3,   MASK_PBE,     MASK_TM,
    MASK_HTT,        MASK_SS,          MASK_SSE2,   MASK_SSE,     MASK_FXSR,
    MASK_MMX,        MASK_ACPI,        MASK_DS,     MASK_CLFSH,   MASK_PSN,
    MASK_PSE36,      MASK_PAT,         MASK_CMOV,   MASK_MCA,     MASK_PGE,
    MASK_MTRR,       MASK_SEP,         MASK_APIC,   MASK_CX8,     MASK_MCE,
    MASK_PAE,        MASK_MSR,         MASK_TSC,    MASK_PSE,     MASK_DE,
    MASK_VME,        MASK_FPU,
};

const unsigned int extended_feature_to_mask[] = {
    MASK_TOPOLOGYEXT,
    MASK_TBM,
    MASK_NODEID,
    MASK_FMA4,
    MASK_LWP,
    MASK_WDT,
    MASK_SKINIT,
    MASK_XOP,
    MASK_IBS,
    MASK_OSVW,
    MASK_3DNOWPREFETCH,
    MASK_MISALIGNSSE,
    MASK_SSE4A,
    MASK_ABM,
    MASK_ALTMOVCR8,
    MASK_EXTAPICSPACE,
    MASK_SVM,
    MASK_CMPLEGACY,
    MASK_LAHFSAHF,
    MASK_3DNOW,
    MASK_3DNOW_EXT,
    MASK_LM,
    MASK_RDTSCP,
    MASK_PAGE1GB,
    MASK_FFXSR,
    MASK_MMXEXT,
    MASK_NX,
    MASK_SYSCALLSYSRET,
};

const char *standard_feature_names[] = {
    "RDRND",       "F16C",   "AVX",       "OSXSAVE",    "XSAVE", "AESNI",
    "TSCDEADLINE", "POPCNT", "MOVBE",     "SSE42",      "SSE41", "DCA",
    "PCID",        "PDCM",   "XTPR",      "CMPXCHG16B", "FMA",   "CNXTID",
    "SSSE3",       "TM2",    "EIST",      "SMX",        "VMX",   "DSCPL",
    "MONITOR",     "DTES64", "PCLMULQDC", "SSE3",       "PBE",   "TM",
    "HTT",         "SS",     "SSE2",      "SSE",        "FXSR",  "MMX",
    "ACPI",        "DS",     "CLFSH",     "PSN",        "PSE36", "PAT",
    "CMOV",        "MCA",    "PGE",       "MTRR",       "SEP",   "APIC",
    "CX8",         "MCE",    "PAE",       "MSR",        "TSC",   "PSE",
    "DE",          "VME",    "FPU",
};

const char *extended_feature_names[] = {
    "TOPOLOGYEXTENSIONS",
    "TBM",
    "NODEID",
    "FMA4",
    "LWP",
    "WDT",
    "SKINIT",
    "XOP",
    "IBS",
    "OSVW",
    "3DNOWPREFETCH",
    "MISALIGNSSE",
    "SSE4A",
    "ABM",
    "ALTMOVCR8",
    "EXTAPICSPACE",
    "SVM",
    "CMPLEGACY",
    "LAHFSAHF",
    "3DNOW",
    "3DNOWEXT",
    "LM",
    "RDTSCP",
    "PAGE1GB",
    "FFXSR",
    "MMXEXT",
    "NX",
    "SYSCALLSYSRET",
};

const unsigned char standard_feature_name_lengths[] = {
    5, 4, 3, 7, 5, 5, 11, 6, 5, 5, 5, 3, 4, 4, 4, 10, 3, 6, 5,
    3, 4, 3, 3, 5, 7, 6,  9, 4, 3, 2, 3, 2, 4, 3, 4,  3, 4, 2,
    5, 3, 5, 3, 4, 3, 3,  4, 3, 4, 3, 3, 3, 3, 3, 3,  2, 3, 3,
};

const unsigned char extended_feature_name_lengths[] = {
    18, 3,  6, 4, 3, 3, 6, 3, 3, 4, 13, 11, 5, 3,
    9,  12, 3, 9, 8, 5, 8, 2, 6, 7, 5,  6,  2, 13,
};

void print_next_standard_feature(unsigned int feature_id,
                                 unsigned short *used_width,
                                 unsigned short *current_y) {
  if (*used_width + standard_feature_name_lengths[feature_id] >
      VGA_BUFFER_WIDTH) {
    (*current_y)++;
    *used_width = 0;
  }
  write_string(standard_feature_names[feature_id], *used_width, *current_y,
               FG_WHITE);
  write_char(' ', *used_width + standard_feature_name_lengths[feature_id] + 1,
             *current_y, FG_WHITE);
  *used_width = *used_width + standard_feature_name_lengths[feature_id] + 1;
}

void print_next_extended_feature(unsigned int feature_id,
                                 unsigned short *used_width,
                                 unsigned short *current_y) {
  if (*used_width + extended_feature_name_lengths[feature_id] >
      VGA_BUFFER_WIDTH) {
    (*current_y)++;
    *used_width = 0;
  }
  write_string(extended_feature_names[feature_id], *used_width, *current_y,
               FG_WHITE);
  write_char(' ', *used_width + extended_feature_name_lengths[feature_id] + 1,
             *current_y, FG_WHITE);
  *used_width = *used_width + extended_feature_name_lengths[feature_id] + 1;
}

int write_feature_list(Features *features, unsigned short y, int extended) {
  unsigned short used_width = 0;
  unsigned short current_y_pos = y;
  unsigned int feature_id;
  int start_y = y;

  /* ECX standard features */
  for (feature_id = 0; feature_id < ECX_0000_0001_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0001_ecx & standard_feature_to_mask[feature_id])
      print_next_standard_feature(feature_id, &used_width, &current_y_pos);
  }

  /* EDX standard features */
  for (feature_id = 0; feature_id < EDX_0000_0001_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0001_edx &
        standard_feature_to_mask[feature_id + ECX_0000_0001_FEATURE_COUNT])
      print_next_standard_feature(feature_id + ECX_0000_0001_FEATURE_COUNT,
                                  &used_width, &current_y_pos);
  }

  if (extended) {
    /* ECX extended features */
    for (feature_id = 0; feature_id < ECX_8000_0001_FEATURE_COUNT;
         feature_id++) {
      if (features->fn8000_0001_ecx & extended_feature_to_mask[feature_id])
        print_next_extended_feature(feature_id, &used_width, &current_y_pos);
    }

    /* EDX extended features */
    for (feature_id = 0; feature_id < EDX_8000_0001_FEATURE_COUNT;
         feature_id++) {
      if (features->fn8000_0001_edx &
          extended_feature_to_mask[feature_id + ECX_8000_0001_FEATURE_COUNT])
        print_next_extended_feature(feature_id + ECX_8000_0001_FEATURE_COUNT,
                                    &used_width, &current_y_pos);
    }
  }

  return current_y_pos - start_y + 1;
}
