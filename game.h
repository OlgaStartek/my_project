#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class Game {
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Mouse position
	sf::Vector2i mousePosWindow;

	int points;
	float spawnTimer;
	float spawnTimerMax;
	int maxKeys; //max na ekranie w tym samym czasie 

	//Game objects
	std::vector<sf::RectangleShape> keys;
	sf::RectangleShape key;

	//Private functions
	void initVariables();
	void initWindow();
	void initKeys();
public:
	//Constructors/destructrs
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	
	//Functions
	void spawn();
	void pollEvents();
	void updateMousePositions();
	void updateKeys();
	void update();
	void renderKeys(); 
	void render();



};

#endif
