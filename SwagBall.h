#pragma once

#include "SFML/Graphics.hpp"

enum SwagBallTypes
{
	DEFAULT,
	DAMAGING,
	HEALING,
	NUMOFTYPES
};

class SwagBall
{
private:
	sf::CircleShape shape;
	short type;

public:
	SwagBall(sf::RenderTarget* window, short ballType);

	const short& GetType() const;

	const sf::CircleShape& GetSwagBall() const;
	void Render(sf::RenderTarget* window);
};

