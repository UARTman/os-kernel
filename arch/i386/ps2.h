/**
 * PS/2 controller driver
 *
 * Currently most of the functionality is unimplemented, but it's usable in qemu.
 */

#include <stdint.h>
#ifndef KERNEL_PS2_H
#define KERNEL_PS2_H

int ps2_init();
int ps2_detect_device();
uint8_t ps2_read();
int ps2_write(uint8_t b);


#endif //KERNEL_PS2_H
