#include "cpuid.h"

/* CPUID call */
#if __i386__
void do_cpuid(unsigned int leaf, unsigned int *eax, unsigned int *ebx,
              unsigned int *ecx, unsigned int *edx) {
  __asm("cpuid" : "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx) : "0"(leaf));
}
#elif __x86_64__
void do_cpuid(unsigned int leaf, unsigned int *eax, unsigned int *ebx,
              unsigned int *ecx, unsigned int *edx) {
  __asm("xchgq  %%rbx,%q1\n"
        "cpuid\n"
        "xchgq  %%rbx,%q1"
        : "=a"(*eax), "=r"(*ebx), "=c"(*ecx), "=d"(*edx)
        : "0"(leaf));
}
#else
#error Compilation target must be x86 or x86_64
#endif

void fn0000_0000(CPUID *cpuid) {
  char *vendor = cpuid->vendor;
  vendor[12] = '\0';
  do_cpuid(0x0, &cpuid->largest_standard_function_number,
           (unsigned int *)vendor, (unsigned int *)(vendor + 8),
           (unsigned int *)(vendor + 4));
}

void fn0000_0001(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  do_cpuid(0x1, &eax, &ebx, &ecx, &edx);

  /* Read from EAX */
  cpuid->family.stepping = eax & MASK_STEPPING;
  cpuid->family.base_model = (eax & MASK_BASE_MODEL) >> 4;
  cpuid->family.base_family = (eax & MASK_BASE_FAMILY) >> 8;
  cpuid->family.extended_model = (eax & MASK_EXT_MODEL) >> 16;
  cpuid->family.extended_family = (eax & MASK_EXT_FAMILY) >> 20;

  /* Read from EBX */
  cpuid->misc.byte_brand_id = ebx & MASK_BYTE_BRAND_ID;
  cpuid->misc.clflush_size = (ebx & MASK_CLFLUSH) >> 8;
  cpuid->misc.logical_processor_count = (ebx & MASK_LOGICAL_PROC_COUNT) >> 16;
  cpuid->misc.local_apcid_id = (ebx & MASK_LOCAL_APIC_ID) >> 24;

  /* Read features from ECX and EDX */
  cpuid->features.fn0000_0001_ecx = ecx;
  cpuid->features.fn0000_0001_edx = edx;
}

void fn0000_0005(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  do_cpuid(0x5, &eax, &ebx, &ecx, &edx);

  cpuid->monitor_mwait_features.monitor_line_size_min = 0x0000FFFF & eax;
  cpuid->monitor_mwait_features.monitor_line_size_max = 0x0000FFFF & ebx;
  cpuid->monitor_mwait_features.interrupt_break_event = 0x00000002 & ecx;
  cpuid->monitor_mwait_features.enumerate_extensions = 0x00000001 & ecx;
}

void fn0000_0006(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  do_cpuid(0x6, &eax, &ebx, &ecx, &edx);

  cpuid->thermal_power_features.effective_frequency_interface =
      ecx & 0x00000001;
}

void fn0000_0007(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  ecx = 0;
  do_cpuid(0x7, &eax, &ebx, &ecx, &edx);

  cpuid->structured_extended_feature_identifiers
      .bit_manipulation_instruction_support = ebx & 0x00000004;
}

void fn0000_000D(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;
  ProcessorExtendedStateEnumeration *ex_state_enum;

  ecx = 0;
  do_cpuid(0xD, &eax, &ebx, &ecx, &edx);

  ex_state_enum = &cpuid->processor_extended_state_enumeration;
  ex_state_enum->x_feature_supported_mask_lower = eax;
  ex_state_enum->x_feature_enabled_size_max = ebx;
  ex_state_enum->x_feature_supported_size_max = ecx;
  ex_state_enum->x_feature_supported_mask_upper = edx;

  ecx = 2;
  do_cpuid(0xD, &eax, &ebx, &ecx, &edx);
  ex_state_enum->ymm_save_state_size = eax;
  ex_state_enum->ymm_save_state_offset = ebx;

  ecx = 62;
  do_cpuid(0xD, &eax, &ebx, &ecx, &edx);
  ex_state_enum->lwp_save_state_size = eax;
  ex_state_enum->lwp_save_state_offset = ebx;
}

void fn8000_0000(CPUID *cpuid) {
  unsigned int ebx, ecx, edx;

  do_cpuid(0x0, &cpuid->largest_extended_function_number, &ebx, &ecx, &edx);
}

void fn8000_0001(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;

  do_cpuid(0x80000001, &eax, &ebx, &ecx, &edx);

  cpuid->extended_brand_id.package_type = (ebx & 0xF0000000) >> 28;
  cpuid->extended_brand_id.brand_id = ebx & 0x0000FFFF;

  cpuid->features.fn8000_0001_ecx = ecx;
  cpuid->features.fn8000_0001_edx = edx;
}

void fn8000_0002(CPUID *cpuid) {
  char *proc_name = cpuid->processor_name;
  do_cpuid(0x80000002, (unsigned int *)proc_name,
           (unsigned int *)(proc_name + 4), (unsigned int *)(proc_name + 8),
           (unsigned int *)(proc_name + 12));
}
void fn8000_0003(CPUID *cpuid) {
  char *proc_name = cpuid->processor_name;
  do_cpuid(0x80000003, (unsigned int *)(proc_name + 16),
           (unsigned int *)(proc_name + 16 + 4),
           (unsigned int *)(proc_name + 16 + 8),
           (unsigned int *)(proc_name + 16 + 12));
}
void fn8000_0004(CPUID *cpuid) {
  char *proc_name = cpuid->processor_name;
  do_cpuid(0x80000004, (unsigned int *)(proc_name + 32),
           (unsigned int *)(proc_name + 32 + 4),
           (unsigned int *)(proc_name + 32 + 8),
           (unsigned int *)(proc_name + 32 + 12));
  proc_name[47] = '\0';
}

void fn8000_0005(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;
  do_cpuid(0x80000005, &eax, &ebx, &ecx, &edx);

  cpuid->l1_cache_identifiers.l1dtlb2_and_4m_data_assoc =
      (eax & 0xFF000000) >> 24;
  cpuid->l1_cache_identifiers.l1dtlb2_and_4m_data_size =
      (eax & 0x00FF0000) >> 16;
  cpuid->l1_cache_identifiers.l1dtlb2_and_4m_inst_assoc =
      (eax & 0x0000FF00) >> 8;
  cpuid->l1_cache_identifiers.l1dtlb2_and_4m_inst_size = (eax & 0x000000FF);

  cpuid->l1_cache_identifiers.l1dtlb4k_data_assoc = (ebx & 0xFF000000) >> 24;
  cpuid->l1_cache_identifiers.l1dtlb4k_data_size = (ebx & 0x00FF0000) >> 16;
  cpuid->l1_cache_identifiers.l1dtlb4k_inst_assoc = (ebx & 0x0000FF00) >> 8;
  cpuid->l1_cache_identifiers.l1dtlb4k_inst_size = (ebx & 0x000000FF);

  cpuid->l1_cache_identifiers.l1dc_size = (ecx & 0xFF000000) >> 24;
  cpuid->l1_cache_identifiers.l1dc_assoc = (ecx & 0x00FF0000) >> 16;
  cpuid->l1_cache_identifiers.l1dc_lines_per_tag = (ecx & 0x0000FF00) >> 8;
  cpuid->l1_cache_identifiers.l1dc_line_size = (ecx & 0x000000FF);

  cpuid->l1_cache_identifiers.l1ic_size = (edx & 0xFF000000) >> 24;
  cpuid->l1_cache_identifiers.l1ic_assoc = (edx & 0x00FF0000) >> 16;
  cpuid->l1_cache_identifiers.l1ic_lines_per_tag = (edx & 0x0000FF00) >> 8;
  cpuid->l1_cache_identifiers.l1ic_line_size = (edx & 0x000000FF);
}

void fn8000_0006(CPUID *cpuid) {
  unsigned int eax, ebx, ecx, edx;
  do_cpuid(0x80000006, &eax, &ebx, &ecx, &edx);

  cpuid->l2_and_l3_cache_identifiers.l2dtlb2_and_4m_data_assoc =
      (eax & 0xF0000000) >> 28;
  cpuid->l2_and_l3_cache_identifiers.l2dtlb2_and_4m_data_size =
      (eax & 0x0FFF0000) >> 16;
  cpuid->l2_and_l3_cache_identifiers.l2dtlb2_and_4m_inst_assoc =
      (eax & 0x0000F000) >> 12;
  cpuid->l2_and_l3_cache_identifiers.l2dtlb2_and_4m_inst_size =
      (eax & 0x00000FFF);

  cpuid->l2_and_l3_cache_identifiers.l2dtlb4k_data_assoc =
      (ebx & 0xF0000000) >> 28;
  cpuid->l2_and_l3_cache_identifiers.l2dtlb4k_data_size =
      (ebx & 0x0FFF0000) >> 16;
  cpuid->l2_and_l3_cache_identifiers.l2dtlb4k_inst_assoc =
      (ebx & 0x0000F000) >> 12;
  cpuid->l2_and_l3_cache_identifiers.l2dtlb4k_inst_size = (ebx & 0x00000FFF);

  cpuid->l2_and_l3_cache_identifiers.l2_size = (ecx & 0xFFFF0000) >> 16;
  cpuid->l2_and_l3_cache_identifiers.l2_assoc = (ecx & 0x0000F000) >> 12;
  cpuid->l2_and_l3_cache_identifiers.l2_lines_per_tag = (ecx & 0x00000F00) >> 8;
  cpuid->l2_and_l3_cache_identifiers.l2_line_size = (ecx & 0x000000FF);

  cpuid->l2_and_l3_cache_identifiers.l3_size = (edx & 0xFFFC0000) >> 18;
  cpuid->l2_and_l3_cache_identifiers.l3_assoc = (edx & 0x0000F000) >> 12;
  cpuid->l2_and_l3_cache_identifiers.l3_lines_per_tag = (edx & 0x00000F00) >> 8;
  cpuid->l2_and_l3_cache_identifiers.l3_line_size = (edx & 0x000000FF);
}
