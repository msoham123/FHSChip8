#include "Core.h"

void Core::initialize() {

}

void Core::emulateCycle() {

}

void Core::fetch() {
    // Remember that opcodes are 16 bit types
    // Fetch 8-bit address, shift it by 8, and merge using OR bitwise operation
    opcode = memory[programCounter] << 8 | memory[programCounter+1];
}

void Core::decode() {

}

void Core::execute() {

}