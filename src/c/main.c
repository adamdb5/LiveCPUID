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

  /* Read features from ECX and EDX */
  cpuid->features.fn0000_0001_ecx = ecx;
  cpuid->features.fn0000_0001_edx = edx;
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
  write_string(cpuid.vendor, 14, 0, FG_GREEN);

  int_to_string(cpuid.largest_standard_function_number, strNum, 10);
  write_string("Largest Standard Function Number:", 40, 0, FG_WHITE);
  write_string(strNum, 74, 0, FG_YELLOW);

  write_feature_list(&cpuid.features, 1);
}
