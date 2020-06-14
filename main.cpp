#include <iostream>
#include "game.h"

int main() {
    Game game;
    //Game loop
    while (game.running()) {

        //Update
        game.update();

        //Render
        game.render();
       
        

        //END
       
    }
    return 0;
}
