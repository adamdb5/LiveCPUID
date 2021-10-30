#ifndef FAMILY_H
#define FAMILY_H

#define MASK_STEPPING 0x0000000F;
#define MASK_BASE_MODEL 0x000000F0;
#define MASK_BASE_FAMILY 0x00000F00;
#define MASK_EXT_MODEL 0x000F0000;
#define MASK_EXT_FAMILY 0x0FF00000;

typedef struct {
  unsigned char stepping;
  unsigned char base_model;
  unsigned char base_family;
  unsigned char extended_model;
  unsigned char extended_family;
} Family;

#endif /* FAMILY_H */
