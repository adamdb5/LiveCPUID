#ifndef FEATURES_H
#define FEATURES_H

/* Standard Features */
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

/* Extended Features */
#define MASK_TOPOLOGYEXT 0x00400000
#define MASK_TBM 0x00200000
#define MASK_NODEID 0x00080000
#define MASK_FMA4 0x00010000
#define MASK_LWP 0x00008000
#define MASK_WDT 0x00002000
#define MASK_SKINIT 0x00001000
#define MASK_XOP 0x00000800
#define MASK_IBS 0x00000400
#define MASK_OSVW 0x00000200
#define MASK_3DNOWPREFETCH 0x00000100
#define MASK_MISALIGNSSE 0x00000080
#define MASK_SSE4A 0x00000040
#define MASK_ABM 0x00000020
#define MASK_ALTMOVCR8 0x00000010
#define MASK_EXTAPICSPACE 0x00000008
#define MASK_SVM 0x00000004
#define MASK_CMPLEGACY 0x00000002
#define MASK_LAHFSAHF 0x00000001

#define MASK_3DNOW 0x80000000
#define MASK_3DNOW_EXT 0x40000000
#define MASK_LM 0x20000000
#define MASK_RDTSCP 0x08000000
#define MASK_PAGE1GB 0x04000000
#define MASK_FFXSR 0x02000000
#define MASK_MMXEXT 0x00800000
#define MASK_NX 0x00400000
#define MASK_SYSCALLSYSRET 0x00080000

typedef struct {
  unsigned int fn0000_0001_ecx;
  unsigned int fn0000_0001_edx;
  unsigned int fn8000_0001_ecx;
  unsigned int fn8000_0001_edx;
} Features;

#define ECX_0000_0001_FEATURE_COUNT 15
#define EDX_0000_0001_FEATURE_COUNT 23
#define ECX_8000_0001_FEATURE_COUNT 19
#define EDX_8000_0001_FEATURE_COUNT 9

/* Feature to mask map */
extern const unsigned int standard_feature_to_mask[];
extern const unsigned int extended_feature_to_mask[];

/* Feature flag string values */
extern const char *standard_feature_names[];
extern const char *extended_feature_names[];

/* Feature flag string lengths */
extern const unsigned char standard_feature_name_lengths[];
extern const unsigned char extended_feature_name_lengths[];

/**
 * Prints the next feature, modifying the used_with and current_y fields for the
 * next call.
 *
 * \param feature_id the ID of the feature to print
 * \param used_with a pointer to the current number of characters on the line.
 * \param current_y a pointer to the current row.
 */
void print_next_standard_feature(unsigned int feature_id,
                                 unsigned short *used_width,
                                 unsigned short *current_y);

void print_next_extended_feature(unsigned int feature_id,
                                 unsigned short *used_width,
                                 unsigned short *current_y);

/**
 * Displays the list of features supported by the processor.
 *
 * \param features the struct of features supported by the CPU.
 * \param y the y position (row) to start displaying the list.
 */
int write_feature_list(Features *features, unsigned short y, int extended);

#endif /* FEATURES_H */
