kernel := kernel.bin
isoname := livecpuid.iso

INCLUDE += c
CFLAGS  += -ffreestanding -Wpedantic -Wall -std=c89 -m32 -fno-stack-protector

linker_script := linker.ld
assembly_source_files := $(wildcard src/asm/*.asm)
assembly_object_files := $(patsubst src/asm/%.asm, build/%.o, $(assembly_source_files))
c_source_files        := $(wildcard src/c/*.c)
c_object_files        := $(patsubst src/c/%.c, build/%.o, $(c_source_files))

.PHONY: all clean kernel qemu qemu-gdb

all: $(kernel)

clean:
	- @rm -fr build
	- @rm -f serial.log

qemu: $(kernel)
	qemu-system-x86_64 -vga std -s -serial file:serial.log -cdrom build/$(isoname)

qemu32: $(kernel)
	qemu-system-i386 -vga std -s -serial file:serial.log -cdrom build/$(isoname)

qemu-gdb: $(kernel)
	qemu-system-x86_64 -vga std -s -serial file:serial.log -S -cdrom build/$(isoname)

$(kernel): $(assembly_object_files) $(c_object_files) $(linker_script)
	@mkdir -p build/isofiles/boot/grub
	$(LD) -melf_i386 -n -T $(linker_script) -o build/isofiles/boot/$(kernel) $(assembly_object_files)
	grub-mkrescue -o build/$(isoname) ./build/isofiles/
	@cp grub.cfg build/isofiles/boot/grub

# compile c files
build/%.o: src/c/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

# compile assembly files
build/%.o: src/asm/%.asm
	@mkdir -p $(shell dirname $@)
	nasm -felf32 $< -o $@

