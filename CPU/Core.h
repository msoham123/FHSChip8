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

    // A program counter which points at the current instruction in memory
    unsigned short programCounter;

    // One 16-bit index register which is used to point at locations in memory
    unsigned short indexRegister;

    // A stack for 16-bit addresses, which is used to call subroutines/functions and return from them
    unsigned short stack[16];

    // A stack pointer points to the level of the stack which is being used
    unsigned short stackPointer;

    // An 8-bit delay timer which is decremented at a rate of 60 Hz (60 times per second) until it reaches 0
    unsigned char delayTimer;

    // An 8-bit sound timer which functions like the delay timer, but which also gives off a beeping sound as long as it’s not 0
    unsigned char soundTimer;

    // The Chip-8 has 35 opcodes, or 35 operations, each two bytes (16 bits) long
    unsigned short opcode;

    /*
     * The Chip-8 has 16 8-bit (one byte) general-purpose variable registers numbered
     * 0 through F hexadecimal (0 through 15 in decimal) called V0 through VF
     * */
    unsigned char variableRegisters[16];

    // The Chip-8 has a HEX based keypad (Ox0-0xF) in which we store the current state of the key
    unsigned char key[16];

    // Of every value, we use the binary representation to draw using first four bits (nibble) a number or character.
    unsigned char fontSet[80] =
            {
            0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
            0x20, 0x60, 0x20, 0x20, 0x70, // 1
            0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
            0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
            0x90, 0x90, 0xF0, 0x10, 0x10, // 4
            0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
            0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
            0xF0, 0x10, 0x20, 0x40, 0x40, // 7
            0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
            0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
            0xF0, 0x90, 0xF0, 0x90, 0x90, // A
            0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
            0xF0, 0x80, 0x80, 0x80, 0xF0, // C
            0xE0, 0x90, 0x90, 0x90, 0xE0, // D
            0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
            0xF0, 0x80, 0xF0, 0x80, 0x80  // F
            };

    //All four nibbles decoded from the opcode (let F be the first nibble)
    unsigned short F, X, Y, N;

    // Helper Methods
    void fetch();
    void decode();
    void execute();

    public:
        void initialize();
        void emulateCycle();
};

#endif
