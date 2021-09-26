# A 32-bit x86 kernel

## Motivation
This is a purely academic project, conducted primarily to get
some understanding of the bare-metal x86.

## Roadmap
- [x] Boot
- [x] Text output on the screen
    - [ ] VBE Framebuffer
    - [ ] VGA
- [ ] PS/2
    - [x] Port 1
    - [ ] Port 2
    - [ ] IRQ
    - [ ] Keyboard
    - [ ] Mouse
- [ ] GDT
- [ ] Interrupts
- [ ] Timers
- [ ] PCI
- [ ] USB
    - [ ] Keyboard
    - [ ] Mouse
- [ ] User mode
- [ ] Drive support
- [ ] Libc implementation
- [ ] GCC cross-compiler
- [ ] Doom port

## Build instructions
You need to have an `i686-elf` cross-compiler toolchain and a UNIX-like system.

While I don't guarantee that you will be able to build it, I recommend 
hacking on `CMakeLists.txt` and `BareBones.cmake` to make CMake builds work on your machine.


## License
- The main body of code is licensed under [The Unlicense](LICENSE),
  effectively making it public domain.

- The printf implementation at `lib/printf` is licensed under
  the [MIT license](https://mit-license.org/).