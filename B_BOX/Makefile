all:
	nasm -f elf32 kernel/kernel.asm -o kernel.o

	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c kernel/kernel.c -o kernel_c.o
	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c drivers/terminal.c -o terminal.o
	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c drivers/keyboard.c -o keyboard.o

	ld -m elf_i386 -T linker.ld kernel.o kernel_c.o terminal.o keyboard.o -o kernel.bin

	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/

	grub-mkrescue -o os.iso iso

run: all
	qemu-system-i386 -cdrom os.iso

clean:
	rm -f kernel.o kernel_c.o terminal.o keyboard.c  kernel.bin os.iso
	rm -f iso/boot/kernel.bin
