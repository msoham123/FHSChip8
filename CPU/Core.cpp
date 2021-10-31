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

    // Increment program counter by 2 to be ready to fetch next opcode
    programCounter += 2;
}

void Core::decode(){
    // Extract nibble F
    F = opcode & 0xF000;
    // Extract nibble X
    X = opcode & 0x0F00;
    // Extract nibble Y
    Y = opcode & 0x0F0F;
    // Extract nibble Z
    N = opcode & 0x00FF;
}


void Core::execute() {
    // Get first nibble by masking opcode using AND bitwise operation
    switch (F) {
        default:
            std::cout << "Error: Unknown Opcode " << opcode << std::endl;
    }
}

void Core::updateDelayTimer() {
    // Remember that delay timer counts down until 0 at 60 Hz
    if(delayTimer>0){
        delayTimer--;
    }
}

void Core::updateSoundTimer(){
    // Remember that sound timer counts down until 0 at 60 Hz
    if(soundTimer>0){
        if(soundTimer==1){
            std::cout << "Sound Timer Activated!" << std::endl;
        }
        soundTimer--;
    }
}