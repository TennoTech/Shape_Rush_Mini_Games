#include "Game.h"
#include <sstream>

Game::Game()
	:
	screenSize{ 1000, 800 },
	endGame{ false },
	spawnTimerMax{ 10.f },
	spawnTimer{ spawnTimerMax },
	maxSwagBalls{ 7 },
	points{ 0 }
{
	window = new sf::RenderWindow(screenSize, "Game Window", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);

	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(30);
	text.setString("Points: 0");
}

Game::~Game()
{
	delete window;
}

const bool Game::IsRunning() const
{
	return window->isOpen();
}

const void Game::UpdateScoreText()
{
	std::stringstream ss;
	ss << "Points: " << points;
	text.setString(ss.str());
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

	// checking collision against player
	for (size_t i = 0; i < swagBalls.size(); i++)
	{
		if (
			player.GetPlayer().getGlobalBounds().intersects(
				swagBalls[i].GetSwagBall().getGlobalBounds()))
		{
			swagBalls.erase(swagBalls.begin() + i);
			points++;
			UpdateScoreText();
		}
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
	window->draw(text);

	window->display();
}
