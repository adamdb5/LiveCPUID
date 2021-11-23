#ifndef FEATURES_H
#define FEATURES_H

/* Standard Features (leaf 000000001h.ECX) */
#define BIT_SSE3         0x00000001
#define BIT_PCLMULQDC    0x00000002
#define BIT_DTES64       0x00000004
#define BIT_MONITOR      0x00000008
#define BIT_DSCPL        0x00000010
#define BIT_VMX          0x00000020
#define BIT_SMX          0x00000040
#define BIT_EIST         0x00000080
#define BIT_TM2          0x00000100
#define BIT_SSSE3        0x00000200
#define BIT_CNXTID       0x00000400
#define BIT_SDBG         0x00000800
#define BIT_FMA          0x00001000
#define BIT_CX16         0x00002000
#define BIT_XTPR         0x00004000
#define BIT_PDCM         0x00008000
#define BIT_PCID         0x00020000
#define BIT_DCA          0x00040000
#define BIT_SSE41        0x00080000
#define BIT_SSE42        0x00100000
#define BIT_X2APIC       0x00200000
#define BIT_MOVBE        0x00400000
#define BIT_POPCNT       0x00800000
#define BIT_TSC_DEADLINE 0x01000000
#define BIT_AESNI        0x02000000
#define BIT_XSAVE        0x04000000
#define BIT_OSXSAVE      0x08000000
#define BIT_AVX          0x10000000
#define BIT_F16C         0x20000000
#define BIT_RDRAND       0x40000000

/* Standard Features (leaf 000000001h.EDX) */
#define BIT_FPU          0x00000001
#define BIT_VME          0x00000002
#define BIT_DE           0x00000004
#define BIT_PSE          0x00000008
#define BIT_TSC          0x00000010
#define BIT_MSR          0x00000020
#define BIT_PAE          0x00000040
#define BIT_MCE          0x00000080
#define BIT_CX8          0x00000100
#define BIT_APIC         0x00000200
#define BIT_SEP          0x00000800
#define BIT_MTRR         0x00001000
#define BIT_PGE          0x00002000
#define BIT_MCA          0x00004000
#define BIT_CMOV         0x00008000
#define BIT_PAT          0x00010000
#define BIT_PSE36        0x00020000
#define BIT_PSN          0x00040000
#define BIT_CLFSH        0x00080000
#define BIT_DS           0x00200000
#define BIT_ACPI         0x00400000
#define BIT_MMX          0x00800000
#define BIT_FXSR         0x01000000
#define BIT_SSE          0x02000000
#define BIT_SSE2         0x04000000
#define BIT_SS           0x08000000
#define BIT_HTT          0x10000000
#define BIT_TM           0x20000000
#define BIT_PBE          0x80000000

/* Extended Features (leaf 800000001h.ECX) */
#define BIT_LAHF_SAHF       0x00000001
#define BIT_LZCNT           0x00000020
#define BIT_PREFETCHW       0x00000100

/* Extended Features (leaf 800000001h.EDX) */
#define BIT_SYSCALL_SYSRET  0x00000800
#define BIT_EXEC_DISABLE    0x00100000
#define BIT_1GB_PAGE        0x04000000
#define BIT_RDTSCP_TSC_AUX  0x08000000
#define BIT_IA64            0x20000000

/* Intel Leaf 7 Features (leaf 00000007h.EBX) */
#define BIT_FSGBASE          0x00000001
#define BIT_IA32_TSC_ADJUST  0x00000002
#define BIT_SGX              0x00000004
#define BIT_BMI1             0x00000008
#define BIT_HLE              0x00000010
#define BIT_AVX2             0x00000020
#define BIT_FDP_EXCEPTN_ONLY 0x00000040
#define BIT_SMEP             0x00000080
#define BIT_BMI2             0x00000100
#define BIT_ENHANCED_REP     0x00000200
#define BIT_INVPCID          0x00000400
#define BIT_RTM              0x00000800
#define BIT_RDTM             0x00001000
#define BIT_DEPR_FPU_CS_DS   0x00002000
#define BIT_MPX              0x00004000
#define BIT_RDTA             0x00008000
#define BIT_AVX512F          0x00010000
#define BIT_AVX512DQ         0x00020000
#define BIT_RDSEED           0x00040000
#define BIT_ADX              0x00080000
#define BIT_SMAP             0x00100000
#define BIT_AVX512_IFMA      0x00200000
#define BIT_CLFLUSHOPT       0x00800000
#define BIT_CLWB             0x01000000
#define BIT_IPT              0x02000000
#define BIT_AVX512PF         0x04000000
#define BIT_AVX512ER         0x08000000
#define BIT_AVX512CD         0x10000000
#define BIT_SHA              0x20000000
#define BIT_AVX512BW         0x40000000
#define BIT_AVX512VL         0x80000000

/* Intel Leaf 7 Features (leaf 00000007h.ECX) */

#define BIT_PREFETCHW1       0x00000001
#define BIT_AVX512_VBMI      0x00000002
#define BIT_UMIP             0x00000004
#define BIT_PKU              0x00000008
#define BIT_OSPKE            0x00000010
#define BIT_WAITPKG          0x00000020
#define BIT_AVX512_VBMI2     0x00000040
#define BIT_CET_SS           0x00000080
#define BIT_GFNI             0x00000100
#define BIT_VAES             0x00000200
#define BIT_VPCLMULQDQ       0x00000400
#define BIT_AVX512_VNNI      0x00000800
#define BIT_AVX512_BITALG    0x00001000
#define BIT_TME_EN           0x00002000
#define BIT_AVX512_VPOPCNTDQ 0x00004000
#define BIT_LA57             0x00010000
#define BIT_RDPID            0x00400000
#define BIT_KL               0x00800000
#define BIT_CLDEMOTE         0x02000000
#define BIT_MOVDIRI          0x08000000
#define BIT_MOVDIR64B        0x10000000
#define BIT_SGX_LC           0x40000000
#define BIT_PKS              0x80000000

/* Intel Leaf 7 Features (leaf 00000007h.EDX) */

#define BIT_AVX512_4VNNIW    0x00000004
#define BIT_AVX512_4FMAPS    0x00000008
#define BIT_FS_REP_MOV       0x00000010
#define BIT_AVX512_VP2INT    0x00000100
#define BIT_MD_CLEAR         0x00000400
#define BIT_HYBRID           0x00008000
#define BIT_PCONFIG          0x00040000
#define BIT_CET_IBT          0x00100000
#define BIT_IBRS_IBPB        0x04000000
#define BIT_STIBP            0x08000000
#define BIT_L1D_FLUSH        0x10000000
#define BIT_IA32_ARCH_CAP    0x20000000
#define BIT_IA32_CORE_CAP    0x40000000
#define BIT_SSBD             0x80000000

/* Feature counts */

#define ECX_0000_0001_FEATURE_COUNT 30
#define EDX_0000_0001_FEATURE_COUNT 29
#define ECX_8000_0001_FEATURE_COUNT 2
#define EDX_8000_0001_FEATURE_COUNT 5
#define EBX_0000_0007_FEATURE_COUNT 31
#define ECX_0000_0007_FEATURE_COUNT 23
#define EDX_0000_0007_FEATURE_COUNT 14

typedef struct {
  unsigned int fn0000_0001_ecx;
  unsigned int fn0000_0001_edx;
  unsigned int fn8000_0001_ecx;
  unsigned int fn8000_0001_edx;
  unsigned int fn0000_0007_ebx;
  unsigned int fn0000_0007_ecx;
  unsigned int fn0000_0007_edx;
} Features;

/* Feature flag id -> string maps */
extern const unsigned int fn0000_0001_ecx_feature_bits[];
extern const char        *fn0000_0001_ecx_feature_names[];
extern const unsigned int fn0000_0001_edx_feature_bits[];
extern const char        *fn0000_0001_edx_feature_names[];

extern const unsigned int fn8000_0001_ecx_feature_bits[];
extern const char        *fn8000_0001_ecx_feature_names[];
extern const unsigned int fn8000_0001_edx_feature_bits[];
extern const char        *fn8000_0001_edx_feature_names[];

extern const unsigned int fn0000_0007_ebx_feature_bits[];
extern const char        *fn0000_0007_ebx_feature_names[];
extern const unsigned int fn0000_0007_ecx_feature_bits[];
extern const char        *fn0000_0007_ecx_feature_names[];
extern const unsigned int fn0000_0007_edx_feature_bits[];
extern const char        *fn0000_0007_edx_feature_names[];

/**
 * Displays the list of features supported by the processor.
 *
 * \param features the struct of features supported by the CPU.
 * \param y the y position (row) to start displaying the list.
 */
int write_feature_list(Features *features, unsigned short y, int extended);

#endif /* FEATURES_H */
