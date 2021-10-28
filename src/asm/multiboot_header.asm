; Multiboot 2 header
section .multiboot_header
header_start:
    MULTIBOOT_PAGE_ALIGN    equ 1           ; Align to 4K boundaries
    MULTIBOOT_HEADER_ARCH   equ 0           ; 32-bit (protected) mode of i386
    MULTIBOOT_HEADER_MAGIC  equ 0xE85250D6  ; Magic number
    MULTIBOOT_CHECKSUM      equ - (MULTIBOOT_HEADER_MAGIC + (header_end - header_start))                               
    MULTIBOOT_TYPE          equ 0
    MULTIBOOT_FLAGS         equ 0
    MULTIBOOT_SIZE          equ 8

    dd MULTIBOOT_HEADER_MAGIC
    dd MULTIBOOT_HEADER_ARCH
    dd header_end - header_start
    dd MULTIBOOT_CHECKSUM

    dw MULTIBOOT_TYPE
    dw MULTIBOOT_FLAGS
    dd MULTIBOOT_SIZE
header_end: