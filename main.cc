#include <iostream>
#include "game.h"

int main(){
    //window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My game", sf::Style::Titlebar | sf::Style::Close); //mamy miejsce tytulu i zamkniecie (nie pozwalam na resize)
    sf::Event event;
    //game loop
    while(window.isOpen()){
        //events
        while(window.pollEvent(event)){ //jak dlugo dostajemy informacje z okna wpisujemy pod event
            switch(event.type){
            case sf::Event::Closed:
                window.close(); //zamykamy jesli kliknieto przycisk close
                break;
            case sf::Event::Keypressed:
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
        }
        //update

        //render
        window.clear(sf::Color::Cyan); //zerujemy to co bylo
        //main game
        window.display(); //skonczylismy
    }
    //end
    return 0;
}
