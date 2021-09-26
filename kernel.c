#include "lib/printf/printf.h"
#include "arch/i386/tty.h"
#include "arch/i386/bda.h"
#include "arch/i386/com.h"
#include "snek.h"
#include "arch/i386/ps2.h"
#include "arch/i386/ps2_keyboard.h"
/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif


__attribute__((unused)) void kernel_main(void)
{
	/* Initialize terminal interface */
	terminal_initialize();
 
	terminal_writestring("Hello, kernel World!\n");
    printf("This is line %d\n", 1);
    printf("Address of COM1: %x\n", bda_com_table()->COM1);
    int serial_result = init_serial();
    printf("Result of init_serial(): %d\n", serial_result);
    int ps2_result = ps2_init();
    ps2_detect_device();
    ps2_kbd_init();
}