#pragma once

#include "SFML/Graphics.hpp"

class Player
{
private:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Player(float x = 0.f, float y = 0.f);
	~Player();

	void Update(sf::RenderTarget* window);
	void Render(sf::RenderTarget* window);
};
