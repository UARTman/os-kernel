/**
 * A primitive COM serial driver
 *
 * Currently works in QEMU, but doesn't support IRQ and the port is hard-coded
 */


#include "com.h"


int is_transmit_empty() {
    return inb(PORT + 5) & 0x20;
}

void write_serial(char a) {
    while (is_transmit_empty() == 0);

    outb(PORT,a);
}

int serial_received() {
    return inb(PORT + 5) & 1;
}

char read_serial() {
    while (serial_received() == 0);

    return inb(PORT);
}
