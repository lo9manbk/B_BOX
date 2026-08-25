# B_BOX

<p align="center">
  <strong>A small operating system built from scratch.</strong>
</p>

<p align="center">
  <a href="https://github.com/lo9manbk/B_BOX/stargazers">⭐ Star</a>
  ·
  <a href="https://github.com/lo9manbk/B_BOX/issues">Issues</a>
  ·
  <a href="https://github.com/lo9manbk/B_BOX">Repository</a>
</p>

---

## About

B_BOX is a hobby operating system built from the ground up for x86.

It starts with a minimal kernel and is gradually evolving into a complete operating system.

The project focuses on understanding the layers that normally stay hidden:

```text
Hardware
   ↓
Kernel
   ↓
Interrupts
   ↓
Memory
   ↓
Processes
   ↓
Filesystem
   ↓
Userspace
   ↓
Shell
```

> **One system. Built from scratch.**

---

## 🖥️ Current State

B_BOX can currently boot its own kernel and provide an interactive terminal with keyboard input.

### Implemented

* Bootable x86 kernel
* VGA text terminal
* Screen management
* Keyboard input
* PS/2 scan-code handling
* Port I/O
* Terminal interaction
* Screen scrolling

### Currently Building

* Interrupt Descriptor Table
* Hardware interrupts
* Keyboard interrupts
* Cursor support
* Memory management

---

## 🚧 Roadmap

### Kernel

* [x] Boot
* [x] VGA terminal
* [x] Keyboard input
* [x] Terminal
* [x] Screen scrolling
* [ ] IDT
* [ ] Hardware interrupts
* [ ] Keyboard interrupts
* [ ] Timer
* [ ] Cursor

### Memory

* [ ] Physical memory manager
* [ ] Paging
* [ ] Kernel heap
* [ ] Virtual memory

### Processes

* [ ] Process management
* [ ] Context switching
* [ ] Multitasking
* [ ] User mode

### Storage

* [ ] Disk I/O
* [ ] Filesystem
* [ ] File operations

### Userspace

* [ ] System calls
* [ ] Shell
* [ ] Basic applications

---

## 🚀 Run

### Requirements

Linux with:

* NASM
* GRUB tools
* QEMU
* Make

### Build

```bash
git clone https://github.com/lo9manbk/B_BOX.git
cd B_BOX
make
```

### Boot

```bash
qemu-system-i386 -cdrom os.iso
```

---

## 🛠️ Stack

**C** · **x86 Assembly** · **GRUB** · **QEMU**

---

## 📂 Structure

```text
B_BOX/
├── kernel/
│   ├── kernel.c
│   └── kernel.asm
├── drivers/
│   ├── terminal.c
│   ├── terminal.h
│   ├── keyboard.c
│   └── keyboard.h
├── linker.ld
├── Makefile
└── os.iso
```

---

## 🎯 Why B_BOX?

Modern operating systems hide almost everything from the programmer.

B_BOX takes the opposite approach.

Every subsystem is built progressively, starting from the kernel and moving toward memory management, processes, storage, and userspace.

The result is not just an operating system.

It's a way to understand **how an operating system actually works underneath.**

---

## 📜 License

GNU GPL-3.0

---

<p align="center">
  <strong>B_BOX — Built from scratch.</strong>
</p>
