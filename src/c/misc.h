#ifndef MISC_H
#define MISC_H

/**
 *   cpuid->misc.byte_brand_id = ebx & 0b00000000000000000000000011111111;
  cpuid->misc.clflush_size = ebx & 0b00000000000000001111111100000000;
  cpuid->misc.logical_processor_count =
      ebx & 0b00000000111111110000000000000000;
  cpuid->misc.local_apcid_id = ebx & 0b11111111000000000000000000000000;
  */

#define MASK_BYTE_BRAND_ID 0x000000FF
#define MASK_CLFLUSH 0X0000FF00
#define MASK_LOGICAL_PROC_COUNT 0x00FF0000
#define MASK_LOCAL_APIC_ID 0xFF000000

typedef struct {
  unsigned char local_apcid_id;
  unsigned char logical_processor_count;
  unsigned char clflush_size;
  unsigned char byte_brand_id;
} Misc;

#endif /* MISC_H */
