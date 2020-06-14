#include "game.h"

void Game::initVariables(){
	this->window = nullptr;
}

void Game::initWindow(){
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "My game", sf::Style::Titlebar | sf::Style::Close);
	
    this->window->setFramerateLimit(144);
}

void Game::initKeys(){
    this->key.setPosition(10.f, 10.f);
    this->key.setSize(sf::Vector2f(100.f, 100.f)); //dwa floaty
    this->key.setFillColor(sf::Color::Black);
}

Game::Game() {
	this->initVariables();
	this->initWindow();
    this->initKeys();
}

Game::~Game() {
	delete this->window;

}
//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}
//Functions
void Game::pollEvents(){
    //Event poll
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            break;
        }
    }
}

void Game::update(){
    this->pollEvents();

    //pozycja myszy wzgledem okna gry
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";;
}

void Game::render(){
    /*
    -clear old
    -render objects
    -display
    */

    window->clear(sf::Color::Cyan);

    window->draw(this->key);

    window->display();
}
