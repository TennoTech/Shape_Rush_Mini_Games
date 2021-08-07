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

	const sf::RectangleShape& GetPlayer() const;
	const short& GetHealth() const;
	const short& GetHealthMax() const;

	void TakeDamage(const short damage);
	void GainHealth(const short additionalHealth);

	void Update(sf::RenderTarget* window);
	void Render(sf::RenderTarget* window);
};
