#include "CPU.h"
#include "Display.h"


Display WINDOW;
CPU CORE;

using namespace std;

void setupGraphics() {
    WINDOW.initDisplay();
}

void setupInput() {

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


    setupGraphics();
    setupInput();

    CORE.initialize();
    WINDOW.updateDisplay(CORE.getDisplayArray());


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




