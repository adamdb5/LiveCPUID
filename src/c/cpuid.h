#ifndef CPUID_H
#define CPUID_H

#include "family.h"
#include "features.h"
#include "misc.h"

typedef struct {
  unsigned short monitor_line_size_min;
  unsigned short monitor_line_size_max;
  unsigned char interrupt_break_event;
  unsigned char enumerate_extensions;

} MonitorMWaitFeatures;

typedef struct {
  unsigned char effective_frequency_interface;
} ThermalPowerFeatures;

typedef struct {
  unsigned char bit_manipulation_instruction_support;
} StructuredExtendedFeatureIdentifiers;

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


typedef struct {
  unsigned int largest_standard_function_number;
  char vendor[13];
  Family family;
  Misc misc;
  Features features;
  MonitorMWaitFeatures monitor_mwait_features;
  ThermalPowerFeatures thermal_power_features;
  StructuredExtendedFeatureIdentifiers structured_extended_feature_identifiers;
  ProcessorExtendedStateEnumeration processor_extended_state_enumeration;

} CPUID;

/**
 * Largest Standard Function Number and Processor Vendor.
 *
 * \param cpuid A pointer to a CPUID structure.
 */
void fn0000_0000(CPUID *cpuid);

/**
 * Gets information about the processor's family, model and stepping
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
 * Gets information about the extended state enumeration supported by the
 * processor.
 *
 * @param cpuid
 */
void fn0000_000D(CPUID *cpuid);

#endif /* CPUID_H */
