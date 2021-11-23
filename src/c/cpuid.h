#ifndef CPUID_H
#define CPUID_H

#include "family.h"
#include "features.h"
#include "misc.h"

/**
 * Stores information about monitor line size and mwait features from
 * fn0000_0005.
 */
typedef struct {
  unsigned short monitor_line_size_min;
  unsigned short monitor_line_size_max;
  unsigned char interrupt_break_event;
  unsigned char enumerate_extensions;
} MonitorMWaitFeatures;

/**
 * Stores information about the effective frequency interface from fn0000_0006.
 */
typedef struct {
  unsigned char effective_frequency_interface;
} ThermalPowerFeatures;

/**
 * Stores information about bit manipulation instruction support from
 * fn0000_0007.
 */
typedef struct {
  unsigned char bit_manipulation_instruction_support;
} StructuredExtendedFeatureIdentifiers;

/**
 * Stores information extended state enumeration from fn0000_000D.
 */
typedef struct {
  unsigned int x_feature_supported_mask_lower;
  unsigned int x_feature_supported_mask_upper;
  unsigned int x_feature_enabled_size_max;
  unsigned int x_feature_supported_size_max;
  unsigned int ymm_save_state_size;
  unsigned int ymm_save_state_offset;
  unsigned int lwp_save_state_size;
  unsigned int lwp_save_state_offset;
} ProcessorExtendedStateEnumeration;

/**
 * Stores information about package type and brand id from fn8000_0001.
 */
typedef struct {
  unsigned char package_type;
  unsigned short brand_id;
} ExtendedBrandId;

/**
 * Stores information about L1 caches and their associativity.
 */
typedef struct {
  unsigned char l1dtlb2_and_4m_data_assoc;
  unsigned char l1dtlb2_and_4m_data_size;
  unsigned char l1dtlb2_and_4m_inst_assoc;
  unsigned char l1dtlb2_and_4m_inst_size;
  unsigned char l1dtlb4k_data_assoc;
  unsigned char l1dtlb4k_data_size;
  unsigned char l1dtlb4k_inst_assoc;
  unsigned char l1dtlb4k_inst_size;
  unsigned char l1dc_size;
  unsigned char l1dc_assoc;
  unsigned char l1dc_lines_per_tag;
  unsigned char l1dc_line_size;
  unsigned char l1ic_size;
  unsigned char l1ic_assoc;
  unsigned char l1ic_lines_per_tag;
  unsigned char l1ic_line_size;
} L1CacheIdentifiers;

/**
 * Stores information about L2 and L3 caches and their associativity.
 */
typedef struct {
  unsigned char l2dtlb2_and_4m_data_assoc;
  unsigned short l2dtlb2_and_4m_data_size;
  unsigned char l2dtlb2_and_4m_inst_assoc;
  unsigned short l2dtlb2_and_4m_inst_size;
  unsigned char l2dtlb4k_data_assoc;
  unsigned short l2dtlb4k_data_size;
  unsigned char l2dtlb4k_inst_assoc;
  unsigned short l2dtlb4k_inst_size;
  unsigned short l2_size;
  unsigned char l2_assoc;
  unsigned char l2_lines_per_tag;
  unsigned char l2_line_size;
  unsigned char l3_size;
  unsigned char l3_assoc;
  unsigned char l3_lines_per_tag;
  unsigned char l3_line_size;
} L2AndL3CacheIdentifiers;

/**
 * Stores all CPUID information about a processor.
 */
typedef struct {
  unsigned int largest_standard_function_number;
  unsigned int largest_extended_function_number;
  char vendor[13];
  char processor_name[48];
  Family family;
  Misc misc;
  Features features;
  MonitorMWaitFeatures monitor_mwait_features;
  ThermalPowerFeatures thermal_power_features;
  StructuredExtendedFeatureIdentifiers structured_extended_feature_identifiers;
  ProcessorExtendedStateEnumeration processor_extended_state_enumeration;
  ExtendedBrandId extended_brand_id;
  L1CacheIdentifiers l1_cache_identifiers;
  L2AndL3CacheIdentifiers l2_and_l3_cache_identifiers;
} CPUID;

/**
 * Executes the cpuid instruction on the given leaf, and loads the results into
the given pointers.
 *
 * \param leaf the CPUID leaf.
 * \param eax a pointer to load the value from eax into.
 * \param ebx a pointer to load the value from ebx into.
 * \param ecx a pointer to load the value from ecx into.
 * \param edx a pointer to load the value from edx into.
 */
void do_cpuid(unsigned int leaf, unsigned int *eax, unsigned int *ebx,
              unsigned int *ecx, unsigned int *edx);

/**
 * Largest Standard Function Number and Processor Vendor.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn0000_0000(CPUID *cpuid);

/**
 * Gets information about the processor's family, model and stepping and
 * supported standard features.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn0000_0001(CPUID *cpuid);

/**
 * Gets information about the features for the MONITOR and MWAIT instructions.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn0000_0005(CPUID *cpuid);

/**
 * Gets information about the digital thermal sensor and power management
 * parameters.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn0000_0006(CPUID *cpuid);

/**
 * Gets information about the extended features supported by the processor.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn0000_0007(CPUID *cpuid);

/**
 * Gets information about extended state enumeration supported by the procesor.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn0000_000D(CPUID *cpuid);

/**
 * Largest Extended Function Number and Processor Brand Id part 2.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0000(CPUID *cpuid);

/**
 * Gets information about the processor's package type and supported extended
 * features.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0001(CPUID *cpuid);

/**
 * Loads the first 16 bytes of the processor name.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0002(CPUID *cpuid);

/**
 * Loads the second 16 bytes of the processor name.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0003(CPUID *cpuid);

/**
 * Loads the third 16 bytes of the processor name.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0004(CPUID *cpuid);

/**
 * Gets information about the processor's L1 cache and TLB characteristics.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0005(CPUID *cpuid);

/**
 * Gets information about the processor's L2 cache and TLB characteristics.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0006(CPUID *cpuid);

/**
 * Advanced power management and more features.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn8000_0007(CPUID *cpuid);

#endif /* CPUID_H */
