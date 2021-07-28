#include "Game.h"

#include "SFML/Graphics.hpp"

Game::Game()
	:
	endGame{ false }
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game Window", sf::Style::Close | sf::Style::Titlebar);
}

Game::~Game()
{
	delete window;
}

void Game::Update()
{
}

void Game::Render()
{
}
