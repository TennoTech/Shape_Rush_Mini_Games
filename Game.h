#pragma once

#include "Player.h"
#include "SwagBall.h"

class Game
{
private:
	sf::VideoMode screenSize;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event env;

	Player player;
	std::vector<SwagBall> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	void PollingEvents();
	void SpawnSwagBalls();

public:
	Game();
	~Game();

	const bool IsRunning() const;

	void Update();
	void Render();
};

