#include "game.h"

void Game::initVariables(){
	this->window = nullptr;

    this->points = 0;
    this->spawnTimerMax = 1000.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxKeys = 5;
}

void Game::initWindow(){
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "My game", sf::Style::Titlebar | sf::Style::Close);
	
    this->window->setFramerateLimit(60);
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
void Game::spawn(){
    /* spawn keys
    set their color and position
    */
    this->key.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->key.getSize().x)),
        0.f); //zaczynamy od samej gory
    this->key.setFillColor(sf::Color::Black);
    //spawn
    this->keys.push_back(this->key);

}

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

void Game::updateMousePositions(){
    //pozycja myszy wzgledem okna gryv
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updateKeys(){
    /* update spawn timer
    spawn keys
    moves keys downwords
    usunac na dole okna
    */
    if (this->keys.size() < this->maxKeys) {
        
        if (this->spawnTimer >= this->spawnTimerMax) {
            //spawn and reset
            this->spawn();
            this->spawnTimer = 0.f;
        }
        else
            this->spawnTimer += 1.f;
    }

    //move
    for (auto &k : this->keys) {
        k.move(0.f, 2.f); //przesuwamy w dol
    }
}

void Game::update(){

    this->pollEvents();

    this->updateMousePositions();

    this->updateKeys();
}

void Game::renderKeys(){
    //rendering
    for (auto &k : this->keys) {
        this->window->draw(k);
    }
}

void Game::render(){
    /*
    -clear old
    -render objects
    -display
    */

    this->window->clear(sf::Color::Cyan);

    this->renderKeys();

    this->window->display();
}
