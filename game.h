#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/* 'opakowanie gry' 'game engine'
*/
class Game{
    public:
        //constructors / destructors
        Game();
        virtual ~Game();

        //Functions
        void update();
        void render();

    private:
        //variables
        //window
        sf::RenderWindow* window(sf::VideoMode(800, 600), "My game", sf::Style::Titlebar | sf::Style::Close);
        //private functions
        void initVariables();
        void initWindow();
};

#endif // GAME_H
