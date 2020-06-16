#include <iostream>
#include "game.h"

int main() {
    std::srand(static_cast<unsigned>(time(NULL)));
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
