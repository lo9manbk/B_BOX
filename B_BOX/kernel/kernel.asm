/*
 * B_BOX Operating System
 *
 * Copyright (C) 2026 lo9manbk
 *
 * Licensed under the GNU General Public License v3.0.
 */

global _start
extern kernel_main

section .multiboot
align 4
    dd 0x1BADB002
    dd 0x00000000
    dd -(0x1BADB002 + 0x00000000)

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

section .text
_start:
    mov esp, stack_top
    call kernel_main

.hang:
    jmp .hang
