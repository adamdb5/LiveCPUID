#include "features.h"
#include "util.h"

const unsigned int fn0000_0001_ecx_feature_bits[] = {
  BIT_SSE3, BIT_PCLMULQDC, BIT_DTES64, BIT_MONITOR, BIT_DSCPL, BIT_VMX, BIT_SMX,
  BIT_EIST, BIT_TM2, BIT_SSSE3, BIT_CNXTID, BIT_SDBG, BIT_FMA, BIT_CX16, BIT_XTPR,
  BIT_PDCM, BIT_PCID, BIT_DCA, BIT_SSE41, BIT_SSE42, BIT_X2APIC, BIT_MOVBE, BIT_POPCNT,
  BIT_TSC_DEADLINE, BIT_AESNI, BIT_XSAVE, BIT_OSXSAVE, BIT_AVX, BIT_F16C, BIT_RDRAND
};
const char *fn0000_0001_ecx_feature_names[] = {
  "SSE3", "PCLMULQDC", "DTES64", "MONITOR", "DSCPL", "VMX", "SMX", 
  "EIST", "TM2", "SSSE3", "CNXTID", "SDBG", "FMA", "CX16", "XTPR",
  "PDCM", "PCID", "DCA", "SSE41", "SSE42", "X2APIC", "MOVBE", "POPCNT",
  "TSC_DEADLINE", "AESNI", "XSAVE", "OSXSAVE", "AVX", "F16C", "RDRAND"
};

const unsigned int fn0000_0001_edx_feature_bits[] = {
  BIT_FPU, BIT_VME, BIT_DE, BIT_PSE, BIT_TSC, BIT_MSR, BIT_PAE, BIT_MCE, BIT_CX8,
  BIT_APIC, BIT_SEP, BIT_MTRR, BIT_PGE, BIT_MCA, BIT_CMOV, BIT_PAT, BIT_PSE36, BIT_PSN, 
  BIT_CLFSH, BIT_DS, BIT_ACPI, BIT_MMX, BIT_FXSR, BIT_SSE, BIT_SSE2, BIT_SS, BIT_HTT,
  BIT_TM, BIT_PBE
};
const char *fn0000_0001_edx_feature_names[] = {
  "FPU", "VME", "DE", "PSE", "TSC", "MSR", "PAE", "MCE", "CX8",
  "APIC", "SEP", "MTRR", "PGE", "MCA", "CMOV", "PAT", "PSE36", "PSN",
  "CLFSH", "DS", "ACPI", "MMX", "FXSR", "SSE", "SSE2", "SS", "HTT",
  "TM", "PBE"
};

const unsigned int fn8000_0001_ecx_feature_bits[] = {
  BIT_LAHF_SAHF, BIT_LZCNT, BIT_PREFETCHW
};
const char *fn8000_0001_ecx_feature_names[] = {
  "LAHF_SAHF", "LZCNT", "PREFETCHW"
};

const unsigned int fn8000_0001_edx_feature_bits[] = {
  BIT_SYSCALL_SYSRET, BIT_EXEC_DISABLE, BIT_1GB_PAGE, BIT_RDTSCP_TSC_AUX, BIT_IA64
};
const char *fn8000_0001_edx_feature_names[] = {
  "SYSCALL_SYSRET", "EXEC_DISABLE", "1GB_PAGE", "RDTSCP_TSC_AUX", "IA64"
};

const unsigned int fn0000_0007_ebx_feature_bits[] = {
  BIT_FSGBASE, BIT_IA32_TSC_ADJUST, BIT_SGX, BIT_BMI1, BIT_HLE, BIT_AVX2, BIT_FDP_EXCEPTN_ONLY,
  BIT_SMEP, BIT_BMI2, BIT_ENHANCED_REP, BIT_INVPCID, BIT_RTM, BIT_RDTM, BIT_DEPR_FPU_CS_DS,
  BIT_MPX, BIT_RDTA, BIT_AVX512F, BIT_AVX512DQ, BIT_RDSEED, BIT_ADX, BIT_SMAP, BIT_AVX512_IFMA,
  BIT_CLFLUSHOPT, BIT_CLWB, BIT_IPT, BIT_AVX512PF, BIT_AVX512ER, BIT_AVX512CD, BIT_SHA,
  BIT_AVX512BW, BIT_AVX512VL
};
const char *fn0000_0007_ebx_feature_names[] = {
  "FSGBASE", "IA32_TSC_ADJUST", "SGX", "BMI1", "HLE", "AVX2", "FDP_EXCEPTN_ONLY",
  "SMEP", "BMI2", "ENHANCED_REP", "INVPCID", "RTM", "RDTM", "DEPR_FPU_CS_DS",
  "MPX", "RDTA", "AVX512F", "AVX512DQ", "RDSEED", "ADX", "SMAP", "AVX512_IFMA",
  "CLFLUSHOPT", "CLWB", "IPT", "AVX512PF", "AVX512ER", "AVX512CD", "SHA",
  "AVX512BW", "AVX512VL"
};

const unsigned int fn0000_0007_ecx_feature_bits[] = {
  BIT_PREFETCHW1, BIT_AVX512_VBMI, BIT_UMIP, BIT_PKU, BIT_OSPKE, BIT_WAITPKG, BIT_AVX512_VBMI2,
  BIT_CET_SS, BIT_GFNI, BIT_VAES, BIT_VPCLMULQDQ, BIT_AVX512_VNNI, BIT_AVX512_BITALG, BIT_TME_EN,
  BIT_AVX512_VPOPCNTDQ, BIT_LA57, BIT_RDPID, BIT_KL, BIT_CLDEMOTE, BIT_MOVDIRI, BIT_MOVDIR64B,
  BIT_SGX_LC, BIT_PKS
}; 
const char *fn0000_0007_ecx_feature_names[] = {
  "PREFETCHW1", "AVX512_VBMI", "UMIP", "PKU", "OSPKE", "WAITPKG", "AVX512_VBMI2",
  "CET_SS", "GFNI", "VAES", "VPCLMULQDC", "AVX512_VNNI", "AVX512_BITALG", "TME_EN",
  "AVX512_VPOPCNTDQ", "LA57", "RDPID", "KL", "CLDEMOTE", "MOVDIRI", "MOVDIR64B", 
  "SGX_LC", "PKS"
};

const unsigned int fn0000_0007_edx_feature_bits[] = {
  BIT_AVX512_4VNNIW, BIT_AVX512_4FMAPS, BIT_FS_REP_MOV, BIT_AVX512_VP2INT, BIT_MD_CLEAR,
  BIT_HYBRID, BIT_PCONFIG, BIT_CET_IBT, BIT_IBRS_IBPB, BIT_STIBP, BIT_L1D_FLUSH, BIT_IA32_ARCH_CAP,
  BIT_IA32_CORE_CAP, BIT_SSBD
};
const char *fn0000_0007_edx_feature_names[] = {
  "AVX512_4VNNIW", "AVX512_4FMAPS", "FS_REP_MOV", "AVX512_CP2INT", "MD_CLEAR",
  "HYBRID", "PCONFIG", "CET_IBT", "IBRS_IBPB", "STIBP", "L1D_FLUSH", "IA32_ARCH_CAP",
  "IA32_CORE_CAP", "SSBD"
};

void print_feature(const char *feature_name, unsigned short *x, unsigned short *y) {
  unsigned int name_length;

  name_length = str_len(feature_name);
  if(*x + name_length > VGA_BUFFER_WIDTH) {
    (*y)++;
    *x = 0;
  }

  write_string(feature_name, *x, *y, FG_WHITE);
  *x += name_length + 1;
}

int write_feature_list(Features *features, unsigned short y, int extended) {
  unsigned short used_width = 0;
  unsigned short current_y_pos = y;
  unsigned int feature_id;
  int start_y = y;

  /* fn0000_0001.ECX */
  for (feature_id = 0; feature_id < ECX_0000_0001_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0001_ecx & fn0000_0001_ecx_feature_bits[feature_id])
      print_feature(fn0000_0001_ecx_feature_names[feature_id], &used_width, &current_y_pos);
  }

  /* fn0000_0001.EDX */
  for (feature_id = 0; feature_id < EDX_0000_0001_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0001_edx & fn0000_0001_edx_feature_bits[feature_id])
      print_feature(fn0000_0001_edx_feature_names[feature_id], &used_width, &current_y_pos);
  }

  /* fn0000_0007.EBX (ECX=1) */
  for (feature_id = 0; feature_id < EBX_0000_0007_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0007_ebx & fn0000_0007_ebx_feature_bits[feature_id])
      print_feature(fn0000_0007_ebx_feature_names[feature_id], &used_width, &current_y_pos);
  }

  /* fn0000_0007.ECX (ECX=1) */
  for (feature_id = 0; feature_id < ECX_0000_0007_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0007_ecx & fn0000_0007_ecx_feature_bits[feature_id])
      print_feature(fn0000_0007_ecx_feature_names[feature_id], &used_width, &current_y_pos);
  }

  /* fn0000_0007.EDX (ECX=1) */
  for (feature_id = 0; feature_id < EDX_0000_0007_FEATURE_COUNT; feature_id++) {
    if (features->fn0000_0007_edx & fn0000_0007_edx_feature_bits[feature_id])
      print_feature(fn0000_0007_edx_feature_names[feature_id], &used_width, &current_y_pos);
  }

  if(extended) {
    /* fn8000_0001.ECX */
    for (feature_id = 0; feature_id < ECX_8000_0001_FEATURE_COUNT; feature_id++) {
      if (features->fn8000_0001_ecx & fn8000_0001_ecx_feature_bits[feature_id])
        print_feature(fn8000_0001_ecx_feature_names[feature_id], &used_width, &current_y_pos);
    }

    /* fn8000_0001.EDX */
    for (feature_id = 0; feature_id < EDX_8000_0001_FEATURE_COUNT; feature_id++) {
      if (features->fn8000_0001_edx & fn8000_0001_edx_feature_bits[feature_id])
        print_feature(fn8000_0001_edx_feature_names[feature_id], &used_width, &current_y_pos);
    }
  }

  return current_y_pos - start_y + 1;
}
