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

	// text
	sf::Font font;
	sf::Text text;
	sf::Text endGameText;

	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;
	short points;

	void PollingEvents();
	void SpawnSwagBalls();
	const short RandomBallType() const;
	const void UpdateTextUI();
	const void UpdateCollision();

public:
	Game();
	~Game();

	const bool IsRunning() const;


	void Update();
	void Render();
};

