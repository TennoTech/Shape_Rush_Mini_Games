#pragma once

#include "SFML/Graphics.hpp"

class Player
{
private:
	sf::RectangleShape shape;
	float movementSpeed;
	short healthMax;
	short health;

public:
	Player(float x = 0.f, float y = 0.f);
	~Player();

	const sf::RectangleShape& GetPlayer() const;
	void Update(sf::RenderTarget* window);
	void Render(sf::RenderTarget* window);
};
