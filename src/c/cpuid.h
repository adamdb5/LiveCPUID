#ifndef CPUID_H
#define CPUID_H

#include "family.h"
#include "features.h"
#include "misc.h"

typedef struct {
  unsigned int largest_standard_function_number;
  char vendor[13];
  Family family;
  Misc misc;
  Features features;

} CPUID;

#endif /* CPUID_H */
