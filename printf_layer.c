//
// Created by uartman on 9/3/21.
//

#include "arch/i386/com.h"
#include "arch/i386/tty.h"

void _putchar(char c) {
    terminal_putchar(c);
}