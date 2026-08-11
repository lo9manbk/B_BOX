# first_os 🖥️

A simple operating system kernel built from scratch for learning and experimenting with low-level system programming.

> 🚧 **Work in Progress** — This project is under active development.

## 📖 About

**first_os** is a personal operating-system development project created to explore how computers work at a low level.

The project focuses on building a small kernel from scratch and learning the fundamentals behind:

* Operating system kernels
* x86 architecture
* Boot process
* Bare-metal programming
* VGA text mode
* Keyboard input
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
* **QEMU** — Virtual machine/testing

## 📁 Project Structure

```text
first_os/
├── kernel/
│   ├── kernel.c
│   └── kernel.asm
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

### Build the kernel

Clone the repository:

```bash
git clone https://github.com/lo9manbk/first_os.git
cd first_os
```

Build the project:

```bash
make
```

This generates the operating-system ISO.

## 🚀 Running

You can test the operating system using QEMU:

```bash
qemu-system-i386 -cdrom os.iso
```

If your build generates the ISO in another location, adjust the path accordingly.

## 🧠 What I'm Learning

This project is being developed as a practical way to learn:

```text
Bootloader
    ↓
Kernel Entry
    ↓
Assembly
    ↓
C Kernel
    ↓
Hardware I/O
    ↓
Keyboard
    ↓
Memory
    ↓
Processes / Scheduling
    ↓
File System
```

The implementation of these components will be added progressively.

## 🗺️ Roadmap

### ✅ Current / Implemented

* [x] Basic kernel
* [x] x86 boot process
* [x] C kernel
* [x] Assembly entry code
* [x] VGA text output
* [x] Screen clearing
* [x] New line handling
* [x] Basic terminal output

### 🔨 In Development

* [ ] Keyboard driver
* [ ] Improved terminal
* [x] Screen scrolling
* [ ] Port I/O
* [ ] Interrupt Descriptor Table (IDT)
* [ ] Hardware interrupts
* [ ] Memory management

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

The main purpose of **first_os** is education and experimentation.

Building an operating system from scratch provides a practical understanding of what happens underneath high-level software and helps develop strong knowledge of:

**Computer Architecture → Assembly → C → Kernel → Hardware**

## 📸 Screenshots

Screenshots will be added as the operating system develops.

## 🤝 Contributing

This is primarily a personal learning project, but suggestions, ideas, and improvements are welcome.

If you find a bug or have an idea, feel free to open an **Issue** or submit a **Pull Request**.

## ⚠️ Disclaimer

This operating system is experimental and should be run in a virtual machine such as QEMU.

Do **not** use experimental builds on important physical hardware.

## 📜 License

License information will be added as the project develops.

---

⭐ If you find this project interesting, feel free to star the repository and follow its development.

**Built from scratch. One line of code at a time.**
