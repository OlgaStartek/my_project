#include "game.h"

void Game::initVariables(){
	this->window = nullptr;

    this->endGame = false; 
    this->points = 0;
    this->lives = 10;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxKeys = 6;
}

void Game::initWindow(){
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "My game", sf::Style::Titlebar | sf::Style::Close);
	
    this->window->setFramerateLimit(60);
}

void Game::initKeys(){
    this->key.setPosition(10.f, 10.f);
    this->key.setSize(sf::Vector2f(80.f, 100.f)); //dwa floaty
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
const bool Game::running() const{
	return this->window->isOpen();
}

const bool Game::getEnd() const{
    return this->endGame;
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
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow); //mapping window position to float
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

    //move and delete 
    for (int i = 0; i < this->keys.size(); i++) {
        bool deleted = false; //ustawiamy flage dla opcji usuwania zeby nie usuwac w kazdym miejscu osobno
        this->keys[i].move(0.f, 2.f); //przesuwamy w dol

        //check if clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (this->keys[i].getGlobalBounds().contains(this->mousePosView)) { //sprawdzamy czy klikniecie jest wewnatrz 
                deleted = true;
                this->points += 5;
                std::cout << "Points: " << this->points << "\n";
            }
        }
        //jesli przekroczymy koniec ekranu 
        if (this->keys[i].getPosition().y > this->window->getSize().y) { //sprawdzamy czy y przekracza window size
            deleted = true;
            this->lives -= 1;
            std::cout << "Lives left: " << this->lives << "\n";
        }
        
        //usuwanie
        if(deleted)
            this->keys.erase(this->keys.begin() + i); 
    }
}

void Game::update(){

    this->pollEvents(); //to zostawiamy poza petla zeby moc wylaczyc ekran 
    if (this->endGame == false) {
        this->updateMousePositions();

        this->updateKeys();
    }

    //End game condition 
    if (this->lives <= 0)
        this->endGame = true;
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
