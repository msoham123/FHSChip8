#ifndef FHSCHIP8_CORE_H
#define FHSCHIP8_CORE_H


class Core {

    // The Chip-8 has 35 opcodes, or 35 operations, each two bytes (16 bits) long
    unsigned short opcode;

    // The Chip-8 has 4 kilobytes of memory
    unsigned char memory[4096];

    /*
     * The Chip-8 has 16 8-bit (one byte) general-purpose variable registers numbered
     * 0 through F hexadecimal (0 through 15 in decimal) called V0 through VF
     * */
    unsigned char V[16];

    // One 16-bit index register called I which is used to point at locations in memory
    unsigned short I;








};


#endif
