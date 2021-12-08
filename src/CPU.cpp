#include "CPU.h"
#include <iostream>
#include <stdio.h>

void CPU::initialize() {
    // Clear memory
    for (int i = 0; i < 4096; i++) {
        memory[i] = 0;
    }   

    // Reset display
    clearDisplay();

    // Reset program counter (starts at 0x200)
    programCounter = 0x200;

    // Reset index register
    indexRegister = 0;

    // Reset stack, variable registers, and keypad
    for (int i = 0; i < 16; i++) {
        stack[i] = 0;
        variableRegisters[i] = 0;
        key[i] = 0;
    }

    // Reset stack pointer
    stackPointer = 0;

    // Reset timers
    delayTimer = 0;
    soundTimer = 0;

    // Reset opcode
    opcode = 0;

    // Load font set into memory starting at 0x50 to 0x09F
    for (int i = 80; i < 160; i++) {
        memory[i] = fontSet[i];
    }

    // Reset nibbles
    F = 0;
    X = 0;
    Y = 0;
    N = 0;

}

void CPU::emulateCycle() {
    // CPU Cycle = Fetch-Decode-Execute and then update timers
    fetch();
    decode();
    execute();
    updateDelayTimer();
    updateSoundTimer();
}

void CPU::fetch() {
    // Remember that opcodes are 16 bit types
    // Fetch 8-bit address, shift it by 8, and merge using OR bitwise operation
    opcode = memory[programCounter] << 8 | memory[programCounter + 1];

    // Increment program counter by 2 to be ready to fetch next opcode
    programCounter += 2;
}

void CPU::decode() {
    // Extract nibble F
    F = (opcode & 0xF000) >> 12;
    // Extract nibble X
    X = (opcode & 0x0F00) >> 8;
    // Extract nibble Y
    Y = (opcode & 0x00F0) >> 4;
    // Extract nibble Z
    N = opcode & 0x000F;
}


void CPU::execute() {
    // Get first nibble by masking opcode using AND bitwise operation
    switch (F) {
        // Graphics opcode
    case 0xD000: {
        // Get the X and Y coordinates from VX and VY
        unsigned const short x = variableRegisters[X >> 8];
        unsigned const short y = variableRegisters[Y >> 4];

        // Set VF to zero
        variableRegisters[0xF] = 0;

        //Initialize bit value
        unsigned short bit;

        // Loop through n number of rows
        for (unsigned int n = 0; n < N; n++) {
            // Get the Nth byte of sprite data, counting from the memory address in the index register
            bit = memory[indexRegister + n];

            // Loop through each of the 8 bits in this sprite row
            for (unsigned int i = 0; i < 8; i++) {
                /* If the current pixel is on and the pixel at coordinates X,Y
                on the screen is also on turn off the pixel and set VF to 1 */
                if ((bit & (0x80 >> i)) != 0) {
                    if (display[x + i + ((y + n) * 64)]) {
                        variableRegisters[0xF] = 1;
                    }
                    display[x + i + ((y + n) * 64)] = display[x + i + ((y + n) * 64)] ^ 1;
                }
            }
        }
        break;
    }
    default:
        std::cout << "Error: Unknown Opcode " << opcode << std::endl;
    }
}

void CPU::updateDelayTimer() {
    // Remember that delay timer counts down until 0 at 60 Hz
    if (delayTimer > 0) {
        delayTimer--;
    }
}

void CPU::updateSoundTimer() {
    // Remember that sound timer counts down until 0 at 60 Hz
    if (soundTimer > 0) {
        if (soundTimer == 1) {
            std::cout << "Sound Timer Activated!" << std::endl;
        }
        soundTimer--;
    }
}

bool* CPU::getDisplayArray() {
    return display;
}

     

// FINISH IMPLEMENTING
void CPU::loadGame(const char* gameName) {
   /*
    FILE* gameFile;
    gameFile = fopen(gameName, "rb");
    if (gameFile != NULL) {
        for (int i = 0; i < 0; i++)
        {

        }
    }
   */
}

void CPU::clearDisplay() {
    for (int i = 0; i < (64 * 32); i++) {
        display[i] = false;
    }
}