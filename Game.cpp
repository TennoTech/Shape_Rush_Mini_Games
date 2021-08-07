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
	text.setString("Points: 0 \nHealth : 10");

	endGameText.setFont(font);
	endGameText.setFillColor(sf::Color::White);
	endGameText.setCharacterSize(75);
	endGameText.setString("Game Over");
	endGameText.setPosition(
		window->getView().getCenter().x - (endGameText.getGlobalBounds().width / 2),
		window->getView().getCenter().y - (endGameText.getGlobalBounds().height / 2));
}

Game::~Game()
{
	delete window;
}

const bool Game::IsRunning() const
{
	return window->isOpen();
}

const void Game::UpdateTextUI()
{
	std::stringstream ss;
	ss << "Points: " << points << "\n" << "Health: " << player.GetHealth();
	text.setString(ss.str());
}

const void Game::UpdateCollision()
{
	for (size_t i = 0; i < swagBalls.size(); i++)
	{
		if (
			player.GetPlayer().getGlobalBounds().intersects(
				swagBalls[i].GetSwagBall().getGlobalBounds()))
		{
			switch (swagBalls[i].GetType())
			{
			case SwagBallTypes::DEFAULT:
				points++;
				break;
			case SwagBallTypes::DAMAGING:
				player.TakeDamage(1);
				break;
			case SwagBallTypes::HEALING:
				player.GainHealth(1);
				break;
			}

			UpdateTextUI();
			swagBalls.erase(swagBalls.begin() + i);

			if (player.GetHealth() <= 0)
				endGame = true;
		}
	}
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
			swagBalls.push_back(SwagBall(window, RandomBallType()));
			spawnTimer = 0.f;
		}
	}
}

const short Game::RandomBallType() const
{
	int value = rand() & 100 + 1;

	if (value > 60 && value <= 70)
		return SwagBallTypes::DAMAGING;
	else if (value > 70 && value <= 100)
		return SwagBallTypes::HEALING;

	return SwagBallTypes::DEFAULT;
}

void Game::Update()
{
	PollingEvents();

	if (!endGame)
	{
		player.Update(window);
		SpawnSwagBalls();
		UpdateCollision();
	}
}

void Game::Render()
{
	window->clear();

	// rendering enemies
	for (auto& i : swagBalls)
	{
		i.Render(window);
	}

	player.Render(window);
	window->draw(text);

	if (endGame)
		window->draw(endGameText);

	window->display();
}
