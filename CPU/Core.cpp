#include "Core.h"
#include <iostream>

void Core::initialize() {

}

void Core::emulateCycle() {

}

void Core::fetch() {
    // Remember that opcodes are 16 bit types
    // Fetch 8-bit address, shift it by 8, and merge using OR bitwise operation
    opcode = memory[programCounter] << 8 | memory[programCounter+1];
}

void Core::decodeAndExecute() {
    // Get first nibble by masking opcode using AND bitwise operation
    switch (opcode & 0xF000) {
        default:
            std::cout << "Error: Unknown Opcode " << opcode << std::endl;
    }
}