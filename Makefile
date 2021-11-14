kernel := kernel.bin
isoname := livecpuid.iso

INCLUDE += c
CFLAGS  += -ffreestanding -fno-builtin -fno-stack-protector -Wpedantic -Wall -std=c89 -m32
LFLAGS  += -z max-page-size=4096 -melf_i386 -n

# GNU
#CC := gcc
#LD := ld

# LLVM
CC := clang
LD := ld.lld

linker_script := linker.ld
assembly_source_files := $(wildcard src/asm/*.s)
assembly_object_files := $(patsubst src/asm/%.s, build/%.o, $(assembly_source_files))
c_source_files        := $(wildcard src/c/*.c)
c_object_files        := $(patsubst src/c/%.c, build/%.o, $(c_source_files))

.PHONY: all clean kernel qemu qemu-gdb

all: $(kernel)

clean:
	- @rm -fr build
	- @rm -f serial.log

qemu: $(kernel)
	qemu-system-x86_64 -vga std -cdrom build/$(isoname)

qemu32: $(kernel)
	qemu-system-i386 -vga std -cdrom build/$(isoname)

qemu-gdb: $(kernel)
	qemu-system-x86_64 -vga std -s -serial file:serial.log -S -cdrom build/$(isoname)

$(kernel): $(assembly_object_files) $(c_object_files) $(linker_script)
	@mkdir -p build/isofiles/boot/grub
	$(LD) $(LFLAGS) -T $(linker_script) -o build/isofiles/boot/$(kernel) $(assembly_object_files) $(c_object_files)
	@cp grub.cfg build/isofiles/boot/grub
	grub-mkrescue -o build/$(isoname) ./build/isofiles/


# compile c files
build/%.o: src/c/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

# compile assembly files
build/%.o: src/asm/%.s
	@mkdir -p $(shell dirname $@)
	nasm -felf32 $< -o $@

