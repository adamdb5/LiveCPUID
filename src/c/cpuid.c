#include "cpuid.h"

#include <cpuid.h>

void fn0000_0000(CPUID *cpuid) {
  char *vendor = cpuid->vendor;
  vendor[12] = '\0';
  __get_cpuid(0x0, &cpuid->largest_standard_function_number,
              (unsigned int *)vendor, (unsigned int *)(vendor + 8),
              (unsigned int *)(vendor + 4));
}

void fn0000_0001(CPUID *cpuid) {
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

void fn0000_0005(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  __get_cpuid(0x5, &eax, &ebx, &ecx, &edx);

  cpuid->monitor_mwait_features.monitor_line_size_min = 0x0000FFFF & eax;
  cpuid->monitor_mwait_features.monitor_line_size_max = 0x0000FFFF & ebx;
  cpuid->monitor_mwait_features.interrupt_break_event = 0x00000002 & ecx;
  cpuid->monitor_mwait_features.enumerate_extensions = 0x00000001 & ecx;
}

void fn0000_0006(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  __get_cpuid(0x6, &eax, &ebx, &ecx, &edx);

  cpuid->thermal_power_features.effective_frequency_interface =
      ecx & 0x00000001;
}

void fn0000_0007(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  ecx = 0;
  __get_cpuid(0x7, &eax, &ebx, &ecx, &edx);

  cpuid->structured_extended_feature_identifiers
      .bit_manipulation_instruction_support = ebx & 0x00000004;
}

void fn0000_000D(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  ecx = 0;
  __get_cpuid(0xD, &eax, &ebx, &ecx, &edx);

  cpuid->processor_extended_state_enumeration.x_feature_supported_mask_lower =
      eax;
  cpuid->processor_extended_state_enumeration.x_feature_enabled_size_max = ebx;
  cpuid->processor_extended_state_enumeration.x_feature_supported_size_max =
      ecx;
  cpuid->processor_extended_state_enumeration.x_feature_supported_mask_upper =
      edx;

  ecx = 2;
  __get_cpuid(0xD, &eax, &ebx, &ecx, &edx);
  cpuid->processor_extended_state_enumeration.ymm_save_state_size = eax;
  cpuid->processor_extended_state_enumeration.ymm_save_state_offset = ebx;

  ecx = 62;
  __get_cpuid(0xD, &eax, &ebx, &ecx, &edx);
  cpuid->processor_extended_state_enumeration.lwp_save_state_size = eax;
  cpuid->processor_extended_state_enumeration.lwp_save_state_offset = ebx;
}
