#include "CPU.h"
#include "Display.h"
#include <cstdio>
#include "SDL.h"
#include <cstdlib>

Display WINDOW;
CPU CORE;

using namespace std;

void setupGraphics() {
    WINDOW.initDisplay(CORE.getDisplayArray());
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




