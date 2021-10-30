#ifndef FEATURES_H
#define FEATURES_H

#define MASK_RAZ 0x80000000
#define MASK_F16C 0x20000000
#define MASK_AVX 0x10000000
#define MASK_OSXSAVE 0x08000000
#define MASK_XSAVE 0x04000000
#define MASK_AES 0x02000000
#define MASK_POPCNT 0x00800000
#define MASK_SSE42 0x00100000
#define MASK_SSE41 0x00080000
#define MASK_CMPXCHG16B 0x00020000
#define MASK_FMA 0x00010000
#define MASK_SSSE3 0x00000200
#define MASK_MONITOR 0x00000008
#define MASK_PCLMULQDQ 0x00000002
#define MASK_SSE3 0x00000001

#define MASK_HTT 0x10000000
#define MASK_SSE2 0x04000000
#define MASK_SSE 0x02000000
#define MASK_FXSR 0x01000000
#define MASK_MMX 0x00800000
#define MASK_CLFSH 0x00080000
#define MASK_PSE36 0x00020000
#define MASK_PAT 0x00010000
#define MASK_CMOV 0x00008000
#define MASK_MCA 0x00004000
#define MASK_PGE 0x00002000
#define MASK_MTRR 0x00001000
#define MASK_SYSENTERSYSEXIT 0x00000800
#define MASK_APIC 0x00000200
#define MASK_CMPXCHG8B 0x00000100
#define MASK_MCE 0x00000080
#define MASK_PAE 0x00000040
#define MASK_MSR 0x00000020
#define MASK_TSC 0x00000010
#define MASK_PSE 0x00000008
#define MASK_DE 0x00000004
#define MASK_VME 0x00000002
#define MASK_FPU 0x00000001

typedef struct {
  unsigned char raz;
  unsigned char f16c;
  unsigned char avx;
  unsigned char osxsave;
  unsigned char xsave;
  unsigned char aes;
  unsigned char popcnt;
  unsigned char sse42;
  unsigned char sse41;
  unsigned char cmpxchg16b;
  unsigned char fma;
  unsigned char ssse3;
  unsigned char monitor;
  unsigned char pclmulqdc;
  unsigned char sse3;
  unsigned char htt;
  unsigned char sse2;
  unsigned char sse;
  unsigned char fxsr;
  unsigned char mmx;
  unsigned char clfsh;
  unsigned char pse36;
  unsigned char pat;
  unsigned char cmov;
  unsigned char mca;
  unsigned char pge;
  unsigned char mtrr;
  unsigned char sysentersysexit;
  unsigned char apic;
  unsigned char cmpxchg8b;
  unsigned char mce;
  unsigned char pae;
  unsigned char msr;
  unsigned char tsc;
  unsigned char pse;
  unsigned char de;
  unsigned char vme;
  unsigned char fpu;
} Features;

/* Feature flags */
typedef enum {
  RAZ,
  F16C,
  AVX,
  OSXSAVE,
  XSAVE,
  AES,
  POPCNT,
  SSE42,
  SSE41,
  CMPXCHG16B,
  FMA,
  SSSE3,
  MONITOR,
  PCLMULQDC,
  SSE3,
  HTT,
  SSE2,
  SSE,
  FXSR,
  MMX,
  CLFSH,
  PSE36,
  PAT,
  CMOV,
  MCA,
  PGE,
  MTRR,
  SYSENTERSYSEXIT,
  APIC,
  CMPXCHG8B,
  MCE,
  PAE,
  MSR,
  TSC,
  PSE,
  DE,
  VME,
  FPU
} FeatureId;

/* Feature flag string values */
extern const char *feature_names[];

/* Feature flag string lengths */
extern const unsigned char feature_name_lengths[];

void write_feature_list(Features *features, unsigned short y);

#endif /* FEATURES_H */
