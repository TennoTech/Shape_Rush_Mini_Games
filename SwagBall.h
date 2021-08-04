#pragma once

#include "SFML/Graphics.hpp"

class SwagBall
{
private:
	sf::CircleShape shape;

public:
	SwagBall(sf::RenderTarget* window = nullptr);
	~SwagBall();

	const sf::CircleShape& GetSwagBall() const;
	void Update();
	void Render(sf::RenderTarget* window);
};

