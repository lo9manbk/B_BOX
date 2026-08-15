/*
 * B_BOX Operating System
 *
 * Copyright (C) 2026 lo9manbk
 *
 * Licensed under the GNU General Public License v3.0.
 */

#include "../drivers/terminal.h"
#include "../drivers/keyboard.h"




char keyboard_map[128] = {
    [0x1E] = 'A',
    [0x30] = 'B',
    [0x2E] = 'C',
    [0x20] = 'D',
    [0x12] = 'E',
    [0x21] = 'F',
    [0x22] = 'G',
    [0x23] = 'H',
    [0x17] = 'I',
    [0x24] = 'J',
    [0x25] = 'K',
    [0x26] = 'L',
    [0x32] = 'M',
    [0x31] = 'N',
    [0x18] = 'O',
    [0x19] = 'P',
    [0x10] = 'Q',
    [0x13] = 'R',
    [0x1F] = 'S',
    [0x14] = 'T',
    [0x16] = 'U',
    [0x2F] = 'V',
    [0x11] = 'W',
    [0x2D] = 'X',
    [0x15] = 'Y',
    [0x2C] = 'Z',
    [0x39] = ' '
};


void kernel_main()
{
    clear_screen();

    while (1)
    {
        unsigned char code = keyboard_read();

        if (code != 0)
        {
            if (!(code & 0x80))
            {
                if (code == 0x1C)
                {
                    new_line();
                }
                else
                {
                    char c = keyboard_map[code];

                    if (c != 0)
                    {
                        putchar(c);
                    }
                }
            }
        }
    }
}





