cmake_minimum_required(VERSION 3.19)

set(CMAKE_TOOLCHAIN_FILE "~/Programming/osdev/barebones/BareBones.cmake")

project(kernel C ASM)

add_executable(kernel kernel.c boot.s arch/i386/tty.h arch/i386/tty.c lib/printf/printf.c lib/printf/printf.h arch/i386/bda.c arch/i386/bda.h arch/i386/com.c arch/i386/com.h printf_layer.c snek.c snek.h arch/i386/asm.c arch/i386/asm.h arch/i386/ps2.c arch/i386/ps2.h arch/i386/ps2_keyboard.c arch/i386/ps2_keyboard.h)
add_custom_target(qemu
        COMMAND qemu-system-i386 --kernel kernel -serial stdio
        )
add_dependencies(qemu kernel)