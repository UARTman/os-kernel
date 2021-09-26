/**
 * PS-2 keyboard device driver
 *
 * Currently almost uniumplemented
 */

#include "ps2_keyboard.h"

int ps2_kbd_init() {
    // Set scan code set to 1
    ps2_write(0xF0);
    if (ps2_read() != 0xFA) {
        return 1;
    }
    ps2_write(0x1);
    if (ps2_read() != 0xFA) {
        return 1;
    }
    // Enable scanning
    ps2_write(0xF4);
    if (ps2_read() != 0xFA) {
        return 1;
    }
    return 0;
}