tui enable
layout reg
target remote :1234
symbol-file build/isofiles/boot/kernel.bin
b asm_entry
continue
