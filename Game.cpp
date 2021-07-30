#include "Game.h"

Game::Game()
	:
	screenSize{1000, 800},
	endGame{ false }
{
	window = new sf::RenderWindow(screenSize, "Game Window", sf::Style::Close | sf::Style::Titlebar);
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

void Game::Update()
{
	PollingEvents();
}

void Game::Render()
{
	window->clear();
	
	player.Render(window);
	window->display();
}
