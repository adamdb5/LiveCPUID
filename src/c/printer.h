#ifndef PRINTER_H
#define PRINTER_H

#include "cpuid.h"

void print_fn0000_0001(CPUID *cpuid, unsigned int *current_line);
void print_fn0000_0005(CPUID *cpuid, unsigned int *current_line);

/* Extended */
void print_fn8000_0001(CPUID* cpuid, unsigned int *current_line);

#endif /* PRINTER_H */
