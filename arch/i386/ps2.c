/**
 * PS/2 controller driver
 *
 * Currently most of the functionality is unimplemented, but it's usable in qemu.
 */

#include "ps2.h"
#include "asm.h"
#include "../../lib/printf/printf.h"

#define DATA_PORT 0x60

void ps2_command(uint8_t cmd) {
    outb(0x64, cmd);
}

uint8_t ps2_read_status() {
    return inb(0x64);
}

int ps2_init() {
    // Step 3: Disable devices
    ps2_command(0xAD);
    io_wait();
    ps2_command(0xA7);
    io_wait();
    // Step 4: Flush the output buffer
    inb(0x60);
    io_wait();
    // Step 5: Set the Controller Config byte
    ps2_command(0x20);
    io_wait();
    uint8_t config = inb(0x60);
    io_wait();
    printf("Controller config is: %b\n", config);
    config = config & 0b10111100;
    ps2_command(0x60);
    io_wait();
    outb(0x60, config);
    io_wait();
    // Step 6: Perform a self-test
    ps2_command(0xAA);
    io_wait();
    uint8_t self_test = inb(0x60);
    if (self_test == 0xFC) {
        printf("Self-test failed\n");
        return 1;
    } else if (self_test != 0x55) {
        printf("Self-test didn't return either of the bytes it should\n");
        return 2;
    }
    // Set 8: Perform interface tests
    ps2_command(0xAB);
    uint8_t port1_test = inb(0x60);
    if (port1_test == 0x00) {
        printf("Port 1 is working!\n");
    } else {
        printf("Port 1 errors with code 0x%x!\n", port1_test);
        return 3;
    }

    // Step 9: Enable devices
    ps2_command(0xAE);

    // Step 10: Reset Devices
    while((ps2_read_status() & 1) != 0) {

    }
    outb(0x60, 0xFF);
    printf("PS2 initialized!\n");
    return 0;
}

uint8_t ps2_read() {
    while((ps2_read_status() & 1) != 1);
    return inb(0x60);
}

int ps2_write(uint8_t b) {
    while((ps2_read_status() & 1) != 0);
    outb(0x60, b);
}

int ps2_detect_device() {
    outb(0x60, 0xF5); // Send the "disable scanning" command to the device
    io_wait();
    if (ps2_read() != 0xFA) {
        printf("ACK not received!");
        return 1;
    }
    outb(0x60, 0xF2); // Send the "identify" command to the device
    io_wait();
    uint8_t read = ps2_read();
    if (read != 0xFA) {
        printf("ACK2 not received! Instead got 0x%x", read);
        return 1;
    }
    uint8_t byte_1 = ps2_read();
    printf("Byte 1 is 0x%x\n", byte_1);
    uint8_t byte_2 = ps2_read();
    printf("Byte 2 is 0x%x\n", byte_2);
    return 0;
}


