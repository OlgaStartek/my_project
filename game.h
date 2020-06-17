#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game {
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;//view mouse position in float

	//Text
	sf::Font font;
	sf::Text gameText;
	sf::Text endGameText;

	sf::Texture backgroundTex;
	sf::Sprite background;

	//some variables
	bool endGame;
	unsigned points; //only positives
	int lives;
	float spawnTimer;
	float spawnTimerMax;
	int maxKeys; //max na ekranie w tym samym czasie 

	//Game objects
	std::vector<sf::RectangleShape> keys;
	sf::RectangleShape key;

	//Private functions
	void initVariables();
	void initWindow();
	void initBackground();
	void initText();
	void initKeys();
public:
	//Constructors/destructrs
	Game();
	Game(const Game& g);
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEnd() const;
	
	//Functions
	void spawn();
	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateKeys();
	void update();

	void renderText();
	void renderKeys();
	void renderBackground();
	void render();
};

#endif
