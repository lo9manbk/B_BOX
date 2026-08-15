# B_BOX 🖥️

A simple operating system kernel built from scratch for learning and experimenting with low-level system programming.

> 🚧 **Work in Progress** — B_BOX is an experimental operating system project under active development.

## 📖 About

**B_BOX** is a personal operating-system development project created to explore how computers work at a low level.

The project focuses on building a small x86 kernel from scratch and understanding the fundamentals behind:

* Operating system kernels
* x86 architecture
* Boot process
* Bare-metal programming
* VGA text mode
* Keyboard input
* Terminal interaction
* Port-mapped I/O
* Memory management
* Hardware communication
* Low-level C and Assembly programming

The goal is not to create a production-ready operating system, but to understand the internal mechanisms that make an operating system work.

## 🛠️ Technologies

* **C** — Kernel development
* **x86 Assembly** — Low-level boot and hardware interaction
* **NASM** — Assembly compilation
* **GCC** — C compilation
* **GNU LD** — Kernel linking
* **GRUB** — Bootloader
* **GRUB-MKRESCUE** — ISO generation
* **QEMU** — Virtual machine and testing

## 📁 Project Structure

```text
B_BOX/
├── kernel/
│   ├── kernel.c
│   ├── kernel.asm
│   ├── terminal.c
│   └── terminal.h
├── iso/
├── Makefile
├── linker.ld
└── os.iso
```

> The project structure may change as development continues.

## ⚙️ Building

### Requirements

On a Debian/Ubuntu-based Linux system:

```bash
sudo apt update
sudo apt install build-essential nasm grub-pc-bin grub-common xorriso qemu-system-x86
```

### Clone the Repository

```bash
git clone https://github.com/lo9manbk/B_BOX.git
cd B_BOX
```

### Build

Build the kernel and generate the bootable ISO:

```bash
make
```

## 🚀 Running

You can test B_BOX using QEMU:

```bash
qemu-system-i386 -cdrom os.iso
```

If the generated ISO is located somewhere else, adjust the path accordingly.

## ⌨️ Current Kernel Features

The kernel currently includes basic low-level functionality such as:

* Kernel entry point
* VGA text-mode output
* Screen clearing
* New-line handling
* Terminal output
* Basic screen scrolling
* PS/2 keyboard input
* Keyboard scan-code reading
* Basic keyboard scan-code mapping
* Port-mapped I/O using `inb`
* Basic interaction between Assembly and C

### Keyboard Input

The kernel reads keyboard scan codes from the PS/2 keyboard controller using:

```text
Keyboard
   ↓
Port 0x64
   ↓
Status Check
   ↓
Port 0x60
   ↓
Scan Code
   ↓
Keyboard Mapping
   ↓
ASCII Character
   ↓
Terminal
```

This provides the foundation for developing a more complete keyboard driver and interactive shell.

## 🧠 Architecture

The current development flow is approximately:

```text
BIOS / Boot Process
        ↓
GRUB Bootloader
        ↓
Kernel Entry
        ↓
Assembly
        ↓
C Kernel
        ↓
VGA Terminal
        ↓
Port I/O
        ↓
Keyboard Controller
        ↓
Keyboard Input
        ↓
Terminal Interaction
```

Future components will extend this architecture with interrupts, memory management, processes, and a file system.

## 🗺️ Roadmap

### ✅ Implemented

* [x] Basic kernel
* [x] x86 boot process
* [x] C kernel
* [x] Assembly entry code
* [x] VGA text output
* [x] Screen clearing
* [x] New-line handling
* [x] Basic terminal output
* [x] Basic screen scrolling
* [x] PS/2 keyboard input
* [x] Keyboard scan-code handling
* [x] Basic keyboard mapping
* [x] Port-mapped I/O
* [x] C/Assembly interaction

### 🔨 In Development

* [ ] Improved keyboard driver
* [ ] Better terminal handling
* [ ] Interrupt Descriptor Table (IDT)
* [ ] Hardware interrupts
* [ ] Keyboard interrupts
* [ ] Memory management
* [ ] Better screen and cursor management

### 🔮 Future Goals

* [ ] Physical memory manager
* [ ] Paging
* [ ] Heap allocator
* [ ] Process management
* [ ] Multitasking
* [ ] File system
* [ ] User mode
* [ ] System calls
* [ ] Shell
* [ ] Basic applications

## 🎯 Purpose

The main purpose of **B_BOX** is education and experimentation.

Building an operating system from scratch provides a practical understanding of what happens underneath high-level software and helps develop knowledge of:

```text
Computer Architecture
        ↓
Assembly
        ↓
C
        ↓
Kernel
        ↓
Hardware I/O
        ↓
Drivers
        ↓
Memory
        ↓
Processes
        ↓
File System
```

## 📸 Screenshots

Screenshots will be added as B_BOX develops.

## 🤝 Contributing

This is primarily a personal learning project, but suggestions, ideas, and improvements are welcome.

If you find a bug or have an idea, feel free to open an **Issue** or submit a **Pull Request**.

## ⚠️ Disclaimer

B_BOX is experimental software and should preferably be tested inside a virtual machine such as QEMU.

Do **not** use experimental builds on important physical hardware.

## 📜 License

License information will be added as the project develops.

---

⭐ If you find **B_BOX** interesting, feel free to star the repository and follow its development.

**Built from scratch. One line of code at a time.**

## 📜 License

**B_BOX** is licensed under the GNU General Public License v3.0 (GPL-3.0).

Copyright (C) 2026 **lo9manbk**.

This project is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

See the `LICENSE` file for the complete license.