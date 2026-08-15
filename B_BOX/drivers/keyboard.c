/*
 * B_BOX Operating System
 *
 * Copyright (C) 2026 lo9manbk
 *
 * Licensed under the GNU General Public License v3.0.
 */

#include "keyboard.h"

unsigned char inb (unsigned short port){
    
    unsigned char value;

    asm volatile (
        "inb %1, %0"
        : "=a"(value)
        : "Nd"(port)
    );
        return value;
}

unsigned char keyboard_read(){
    unsigned char status = inb(0x64);

    if (status & 1)
    {
        return inb(0x60);
    }

    return 0;
}
