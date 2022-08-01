#include "CPU.h"
#include "Display.h"
#include <cstdio>
#include "SDL.h"
#include <cstdlib>
#include <iostream>

Display WINDOW;
CPU CORE;

using namespace std;

bool KEYS[322] = { false };
bool keyStates[4][4] = { false };

void setupGraphics() {
    WINDOW.initDisplay(CORE.getDisplayArray());
}

void setUpInput() {
    
}

void checkKeyStates(SDL_Event event) {
    KEYS[event.key.keysym.sym] = true;
    if (KEYS[SDLK_1]) {
        keyStates[0][0] = true;
        cout << "1 pressed" << endl;
    } else if (KEYS[SDLK_2]) {
        keyStates[0][1] = true;
    } else if (KEYS[SDLK_3]) {
        keyStates[0][2] = true;
    } else if (KEYS[SDLK_4]) {
        keyStates[0][3] = true;
    } else if (KEYS[SDLK_q]) {
        keyStates[1][0] = true;
    } else if (KEYS[SDLK_w]) {
        keyStates[1][1] = true;
    } else if (KEYS[SDLK_e]) {
        keyStates[1][2] = true;
    } else if (KEYS[SDLK_r]) {
        keyStates[1][3] = true;
    } else if (KEYS[SDLK_a]) {
        keyStates[2][0] = true;
    } else if (KEYS[SDLK_s]) {
        keyStates[2][1] = true;
    } else if (KEYS[SDLK_d]) {
        keyStates[2][2] = true;
    } else if (KEYS[SDLK_f]) {
        keyStates[2][3] = true;
    } else if (KEYS[SDLK_z]) {
        keyStates[3][0] = true;
    } else if (KEYS[SDLK_x]) {
        keyStates[3][1] = true;
    } else if (KEYS[SDLK_c]) {
        keyStates[3][2] = true;
    } else if (KEYS[SDLK_v]) {
        keyStates[3][3] = true;
    }
}

int main(int argc, char **arcgv) {
   
    /* Pseudocode Implementation (Implement as development progresses)
     *
     *  // Set up render system and register input callbacks
     *  setupGraphics();
     *  setupInput();
     *
     *   // Initialize the Chip8 system and load the game into the memory
     *   core.initialize();
     *   core.loadGame("pong");
     *
     *   // Emulation loop
     *   for(;;){
     *   // Emulate one cycle
     *   core.emulateCycle();
     *   // If the draw flag is set, update the screen
     *   if(myChip8.drawFlag)
     *       drawGraphics();
     *       (THIS IS window.updateDisplay();)
     *   }
     *   // Store key press state (Press and Release)
     *   core.setKeys();
     *   }
     */

    CORE.initialize();

    setupGraphics();

    CORE.emulateCycle();

    // Example (Comment Out When Not Used) - Renders FHS

    // F
    *(CORE.getDisplayArray() + 263) = true;
    *(CORE.getDisplayArray() + 264) = true;
    *(CORE.getDisplayArray() + 265) = true;
    *(CORE.getDisplayArray() + 266) = true;
    *(CORE.getDisplayArray() + 267) = true;
    *(CORE.getDisplayArray() + 263 + 64) = true;
    *(CORE.getDisplayArray() + 263 + (64*2)) = true;
    *(CORE.getDisplayArray() + 263 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 263 + (64 * 4)) = true;
    *(CORE.getDisplayArray() + 263 + (64 * 5)) = true;
    *(CORE.getDisplayArray() + 263 + (64 * 6)) = true;
    *(CORE.getDisplayArray() + 264 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 265 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 266 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 267 + (64 * 3)) = true;

    // H
    *(CORE.getDisplayArray() + 272) = true;
    *(CORE.getDisplayArray() + 272 + 64) = true;
    *(CORE.getDisplayArray() + 272 + (64 * 2)) = true;
    *(CORE.getDisplayArray() + 272 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 272 + (64 * 4)) = true;
    *(CORE.getDisplayArray() + 272 + (64 * 5)) = true;
    *(CORE.getDisplayArray() + 272 + (64 * 6)) = true;
    *(CORE.getDisplayArray() + 273 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 274 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 275 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 276) = true;
    *(CORE.getDisplayArray() + 276 + (64 * 1)) = true;
    *(CORE.getDisplayArray() + 276 + (64 * 2)) = true;
    *(CORE.getDisplayArray() + 276 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 276 + (64 * 4)) = true;
    *(CORE.getDisplayArray() + 276 + (64 * 5)) = true;
    *(CORE.getDisplayArray() + 276 + (64 * 6)) = true;


    // S
    *(CORE.getDisplayArray() + 281) = true;
    *(CORE.getDisplayArray() + 282) = true;
    *(CORE.getDisplayArray() + 283) = true;
    *(CORE.getDisplayArray() + 284) = true;
    *(CORE.getDisplayArray() + 285) = true;
    *(CORE.getDisplayArray() + 281 + 64) = true;
    *(CORE.getDisplayArray() + 281 + (64 * 2)) = true;
    *(CORE.getDisplayArray() + 281 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 282 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 283 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 284 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 285 + (64 * 3)) = true;
    *(CORE.getDisplayArray() + 285 + (64 * 4)) = true;
    *(CORE.getDisplayArray() + 285 + (64 * 5)) = true;
    *(CORE.getDisplayArray() + 285 + (64 * 6)) = true;
    *(CORE.getDisplayArray() + 284 + (64 * 6)) = true;
    *(CORE.getDisplayArray() + 283 + (64 * 6)) = true;
    *(CORE.getDisplayArray() + 282 + (64 * 6)) = true;
    *(CORE.getDisplayArray() + 281 + (64 * 6)) = true;

    // Keep the window open until forcefully closed
    bool running = true;
    while (running) {

        WINDOW.updateDisplay(CORE.getDisplayArray());

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                if (event.type == SDL_KEYDOWN) {
                    checkKeyStates(event);
                }
                break;
            }
        }
    }


    //FINISH IMPLEMENTING
    // CORE.LOADGAME("PONG");

    /*
    for (;;) {
        core.emulatecycle();
        if (core.drawflag == true) {
            window.updatedisplay(core.getdisplayarray());
        }

        core.setkeys();
    }
    */


    return 0;
}




