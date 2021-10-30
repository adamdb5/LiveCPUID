ENTRY(start)

SECTIONS {

  /* Kernel starts at 1MB */
  . = 0x100000;

  /* Align multiboot_header to $K boundaries */
  .boot : ALIGN(4k)
  {
      *(.multiboot_header)
  }
}