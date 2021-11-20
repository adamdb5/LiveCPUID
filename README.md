# [WIP] LiveCPUID

![LiveCPUID in QEMU](https://adambruce.net/images/livecpuid/LiveCPUID_QEMU.png?)

A bootable ISO to display CPU information for x86 processors that support the CPUID instruction.

This project is currently a work in progress, so there is limited functionality, and some issues when booting on bare metal.

## Requirements

- C compiler (e.g. gcc, clang)
- x86 Assembler (e.g. nasm)
- Linker (e.g. ld, ld.ldd)
- make
- grub-mkrescue
- xorriso
- mtools

## Debug Requirements:
- Debugger (e.g. gdb, lldb) - a `.gdbinit` file is provided
- QEMU


## Compiling
LiveCPUID can be compiled to an ISO using the makefile provided. To compile into an ISO run
```bash
make
```

## Booting the ISO in QEMU
To boot the ISO, run 
```bash
make qemu
```

## Debugging
1. Enable debug symbols in compilation: add `-g` to the `CFLAGS` parameter in the Makefile.
2. Add `gdb set auto-load safe-path .` to `~/.gdbinit`
3. Run QEMU in debug mode using ```make qemu-gdb```
4. Run `gdb` in the project's root directory, this should attach to QEMU and automatically set a breakpoint on the `asm_entry` subroutine.
