#ifndef FHSCHIP8_CORE_H
#define FHSCHIP8_CORE_H


class Core {

    // The Chip-8 has 4 kilobytes of memory
    unsigned char memory[4096];

    /*
     * The display is 64 pixels wide and 32 pixels tall. Each pixel can be on or off.
     * In other words, each pixel is a boolean value, or a bit.
     * */
    unsigned char display[64 * 32];

    // A program counter, often called PC, which points at the current instruction in memory
    unsigned short PC;

    // One 16-bit index register called I which is used to point at locations in memory
    unsigned short I;

    // A stack for 16-bit addresses, which is used to call subroutines/functions and return from them
    unsigned short stack[16];

    // A stack pointer points to the level of the stack which is being used
    unsigned short SP;

    // An 8-bit delay timer which is decremented at a rate of 60 Hz (60 times per second) until it reaches 0
    unsigned char delayTimer;

    // The Chip-8 has 35 opcodes, or 35 operations, each two bytes (16 bits) long
    unsigned short opcode;

    /*
     * The Chip-8 has 16 8-bit (one byte) general-purpose variable registers numbered
     * 0 through F hexadecimal (0 through 15 in decimal) called V0 through VF
     * */
    unsigned char V[16];

};

#endif
