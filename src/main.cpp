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

    // Example - Delete (sets 4 corners to white)
    *(CORE.getDisplayArray() + 0) = true;
    *(CORE.getDisplayArray() + 63) = true;
    *(CORE.getDisplayArray() + 2047) = true;
    *(CORE.getDisplayArray() + (2047 - 63)) = true;

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




