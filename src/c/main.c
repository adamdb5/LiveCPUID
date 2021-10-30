#include <cpuid.h>

#include "cpuid.h"
#include "features.h"
#include "util.h"

/* Function names follow the AMD specification available here:
 * https://www.amd.com/system/files/TechDocs/25481.pdf */

/**
 * Largest Standard Function Number and Processor Vendor.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void Fn0000_0000(CPUID *cpuid) {
  char *vendor = cpuid->vendor;
  vendor[12] = '\0';
  __get_cpuid(0x0, &cpuid->largest_standard_function_number,
              (unsigned int *)vendor, (unsigned int *)(vendor + 8),
              (unsigned int *)(vendor + 4));
}

/**
 * Gets information about the processor's family, model and stepping
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void Fn0000_0001(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  __get_cpuid(0x1, &eax, &ebx, &ecx, &edx);

  /* Read from EAX */
  cpuid->family.stepping = eax & MASK_STEPPING;
  cpuid->family.base_model = eax & MASK_BASE_MODEL;
  cpuid->family.base_family = eax & MASK_BASE_FAMILY;
  cpuid->family.extended_model = eax & MASK_EXT_MODEL;
  cpuid->family.extended_family = eax & MASK_EXT_FAMILY;

  /* Read from EBX */
  cpuid->misc.byte_brand_id = ebx & MASK_BYTE_BRAND_ID;
  cpuid->misc.clflush_size = ebx & MASK_CLFLUSH;
  cpuid->misc.logical_processor_count = ebx & MASK_LOGICAL_PROC_COUNT;
  cpuid->misc.local_apcid_id = ebx & MASK_LOCAL_APIC_ID;

  /* Read from ECX */
  cpuid->features.raz = ecx & MASK_RAZ;
  cpuid->features.f16c = ecx & MASK_F16C;
  cpuid->features.avx = ecx & MASK_AVX;
  cpuid->features.osxsave = ecx & MASK_OSXSAVE;
  cpuid->features.xsave = ecx & MASK_XSAVE;
  cpuid->features.aes = ecx & MASK_AES;
  cpuid->features.popcnt = ecx & MASK_POPCNT;
  cpuid->features.sse42 = ecx & MASK_SSE42;
  cpuid->features.sse41 = ecx & MASK_SSE41;
  cpuid->features.cmpxchg16b = ecx & MASK_CMPXCHG16B;
  cpuid->features.fma = ecx & MASK_FMA;
  cpuid->features.ssse3 = ecx & MASK_SSSE3;
  cpuid->features.monitor = ecx & MASK_MONITOR;
  cpuid->features.pclmulqdc = ecx & MASK_PCLMULQDQ;

  /* Read from EDX */
  cpuid->features.htt = edx & MASK_HTT;
  cpuid->features.sse2 = edx & MASK_SSE2;
  cpuid->features.sse = edx & MASK_SSE;
  cpuid->features.fxsr = edx & MASK_FXSR;
  cpuid->features.mmx = edx & MASK_MMX;
  cpuid->features.clfsh = edx & MASK_CLFSH;
  cpuid->features.pse36 = edx & MASK_PSE36;
  cpuid->features.pat = edx & MASK_PAT;
  cpuid->features.cmov = edx & MASK_CMOV;
  cpuid->features.pge = edx & MASK_PGE;
  cpuid->features.mtrr = edx & MASK_MTRR;
  cpuid->features.sysentersysexit = edx & MASK_SYSENTERSYSEXIT;
  cpuid->features.apic = edx & MASK_APIC;
  cpuid->features.cmpxchg8b = edx & MASK_CMPXCHG8B;
  cpuid->features.mce = edx & MASK_MCE;
  cpuid->features.pae = edx & MASK_PAE;
  cpuid->features.msr = edx & MASK_MSR;
  cpuid->features.tsc = edx & MASK_TSC;
  cpuid->features.pse = edx & MASK_PSE;
  cpuid->features.de = edx & MASK_DE;
  cpuid->features.vme = edx & MASK_VME;
  cpuid->features.fpu = edx & MASK_FPU;
}

/**
 * Entry point from the assembly.
 */
void asm_entry() {
  CPUID cpuid;
  char strNum[9];
  Fn0000_0000(&cpuid);
  Fn0000_0001(&cpuid);

  write_string("Brand String: ", 0, 0, FG_WHITE);
  write_string(cpuid.vendor, 14, 0, FG_CYAN);

  int_to_string(cpuid.largest_standard_function_number, strNum, 10);
  write_string("Largest Standard Function Number:", 0, 1, FG_WHITE);
  write_string(strNum, 34, 1, FG_YELLOW);

  write_feature_list(&cpuid.features, 2);
}
