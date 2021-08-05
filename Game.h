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
	sf::Font font;
	sf::Text text;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;
	short points;

	void PollingEvents();
	void SpawnSwagBalls();

public:
	Game();
	~Game();

	const bool IsRunning() const;
	const void UpdateScoreText();

	void Update();
	void Render();
};

