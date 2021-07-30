#pragma once

#include "SFML/Graphics.hpp"

class Player
{
private:
	sf::RectangleShape shape;

public:
	Player();
	~Player();

	void Update();
	void Render(sf::RenderTarget* target);
};
