#pragma once

#include "SFML/Graphics.hpp"

class SwagBall
{
private:
	sf::CircleShape shape;

public:
	SwagBall(sf::RenderTarget* window = nullptr);
	~SwagBall();

	void Update();
	void Render(sf::RenderTarget* window);
};

