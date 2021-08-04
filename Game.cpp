#include "Game.h"

Game::Game()
	:
	screenSize{ 1000, 800 },
	endGame{ false },
	spawnTimerMax{ 10.f },
	spawnTimer{ spawnTimerMax },
	maxSwagBalls{ 7 }
{
	window = new sf::RenderWindow(screenSize, "Game Window", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
}

Game::~Game()
{
	delete window;
}

const bool Game::IsRunning() const
{
	return window->isOpen();
}

void Game::PollingEvents()
{
	while (window->pollEvent(env))
	{
		if (env.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();
	}
}

void Game::SpawnSwagBalls()
{
	if (spawnTimer <= spawnTimerMax)
		spawnTimer += 1.f;
	else
	{
		if (static_cast<int>(swagBalls.size()) <= maxSwagBalls)
		{
			swagBalls.push_back(SwagBall(window));
			spawnTimer = 0.f;
		}
	}
}

void Game::Update()
{
	PollingEvents();
	player.Update(window);
	SpawnSwagBalls();

	for (size_t i = 0; i < swagBalls.size(); i++)
	{
		if (
			player.GetPlayer().getGlobalBounds().intersects(
				swagBalls[i].GetSwagBall().getGlobalBounds()))
			swagBalls.erase(swagBalls.begin() + i);
	}
}

void Game::Render()
{
	window->clear();

	for (auto& i : swagBalls)
	{
		i.Render(window);
	}
	player.Render(window);

	window->display();
}
