/*
 * B_BOX Operating System
 *
 * Copyright (C) 2026 lo9manbk
 *
 * Licensed under the GNU General Public License v3.0.
 */

#include "../drivers/terminal.h"
#include "../drivers/keyboard.h"


void kernel_main()
{
    clear_screen();

    while (1)
    {
        keyboard_handle();
    }
}