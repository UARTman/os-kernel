//
// Created by uartman on 9/3/21.
//

#include "snek.h"
#include "arch/i386/asm.h"


void wait() {
    for (int i = 0; i < 65535; ++i) {
        io_wait();
    }
}
int x = 10;
int y = 10;
bool w = false;
bool s = false;
bool a = false;
bool d = false;

void snek_redraw_screen() {
    for (size_t i = 0; i < VGA_WIDTH; ++i) {
        for (size_t j = 0; j < VGA_HEIGHT; ++j) {
            terminal_putentryat(' ', VGA_COLOR_WHITE, i, j);
        }
    }
    for (size_t i = 0; i < VGA_WIDTH; ++i) {
        terminal_putentryat('x', VGA_COLOR_WHITE, i, 0);
        terminal_putentryat('x', VGA_COLOR_WHITE, i, VGA_HEIGHT - 1);
    }
    for (size_t i = 0; i < VGA_HEIGHT; ++i) {
        terminal_putentryat('x', VGA_COLOR_WHITE, 0, i);
        terminal_putentryat('x', VGA_COLOR_WHITE, VGA_WIDTH - 1, i);
    }
    terminal_putentryat('o', VGA_COLOR_WHITE, x, y);
    if (a) {
        terminal_putentryat('a', VGA_COLOR_WHITE, 1, 2);
    }
    if (w) {
        terminal_putentryat('w', VGA_COLOR_WHITE, 2, 1);
    }
    if (s) {
        terminal_putentryat('s', VGA_COLOR_WHITE, 2, 2);
    }
    if (d) {
        terminal_putentryat('d', VGA_COLOR_WHITE, 3, 2);
    }
    wait();
}

void snek_poll_kbd() {
    uint8_t keycode = inb(0x60);
    switch (keycode) {
        case 0x11:
            w = true;
            break;
        case 0x91:
            w = false;
            break;
        case 0x1F:
            s = true;
            break;
        case 0x9F:
            s = false;
            break;
        case 0x1E:
            a = true;
            break;
        case 0x9E:
            a = false;
            break;
        case 0x20:
            d = true;
            break;
        case 0xA0:
            d = false;
            break;
    }
}
void snek_move() {
    if (w & (y > 1)) {
        y -= 1;
    }
    if (s & (y < VGA_HEIGHT - 2)) {
        y += 1;
    }
    if (a & (x > 1)) {
        x -= 1;
    }
    if (d & (x < VGA_WIDTH - 2)) {
        x += 1;
    }
}

_Noreturn void snek() {
    int move_iter = 0;

    while (true) {
        snek_redraw_screen();
        for (int i = 0; i < 100; ++i) {
            snek_poll_kbd();
        }
        move_iter += 1;
        move_iter = move_iter % 10;
        if (move_iter == 0) {
            snek_move();
        }
    }
}
