#pragma once

#include "Player.h"

class Game
{
private:
	sf::VideoMode screenSize;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event env;

	Player player;

	void PollingEvents();

public:
	Game();
	~Game();

	const bool IsRunning() const;

	void Update();
	void Render();
};

