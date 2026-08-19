/*
 * B_BOX Operating System
 *
 * Copyright (C) 2026 lo9manbk
 *
 * Licensed under the GNU General Public License v3.0.
 */

#include "keyboard.h"
#include "terminal.h"


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



char keyboard_map[128] = {
    [0x1E] = 'a',  [0x30] = 'b',  [0x2E] = 'c',  [0x20] = 'd',
    [0x12] = 'e',  [0x21] = 'f',  [0x22] = 'g',  [0x23] = 'h',
    [0x17] = 'i',  [0x24] = 'j',  [0x25] = 'k',  [0x26] = 'l',
    [0x32] = 'm',  [0x31] = 'n',  [0x18] = 'o',  [0x19] = 'p',
    [0x10] = 'q',  [0x13] = 'r',  [0x1F] = 's',  [0x14] = 't',
    [0x16] = 'u',  [0x2F] = 'v',  [0x11] = 'w',  [0x2D] = 'x',
    [0x15] = 'y',  [0x2C] = 'z',

    [0x39] = ' ',

    [0x02] = '1', [0x03] = '2', [0x04] = '3', [0x05] = '4',
    [0x06] = '5', [0x07] = '6', [0x08] = '7', [0x09] = '8',
    [0x0A] = '9', [0x0B] = '0'
};

char numbers_shift(char c) {
    switch (c){

            case '1': c = '!'; break;
            case '2': c = '@'; break;
            case '3': c = '#'; break;
            case '4': c = '$'; break;
            case '5': c = '%'; break;
            case '6': c = '^'; break;
            case '7': c = '&'; break;
            case '8': c = '*'; break;
            case '9': c = '('; break;
            case '0': c = ')'; break;
    }
    return c;
}


int shift_pressed = 0;


void keyboard_handle()
{
    unsigned char code = keyboard_read();

    if (code == 0)
        return;

    // Release 
    if (code & 0x80){
        unsigned char released = code & 0x7F;

        if (released == 0x2A || released == 0x36)
        {
            shift_pressed = 0;
        }

        return;
    }

    // Shift Press 
    if (code == 0x2A || code == 0x36) {
        shift_pressed = 1;
        return; }

    // Enter 
    if (code == 0x1C){
        new_line();
        return;
    }

    // Normal key 
    char c = keyboard_map[code];

    if (c == 0)
        return;

    // Shift + letter 
    if (shift_pressed && c >= 'a' && c <= 'z')  { c = c - 'a' + 'A'; }
    else if (shift_pressed) { c =  numbers_shift(c); }
    putchar(c);
}

