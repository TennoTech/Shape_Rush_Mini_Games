//#include <iostream>

#include "Player.h"

Player::Player(float x, float y)
	:
	movementSpeed{ 7.5f },
	healthMax{ 10 },
	health{ healthMax }
{
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::Magenta);
	shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::~Player()
{
}

const sf::RectangleShape& Player::GetPlayer() const
{
	return shape;
}

void Player::Update(sf::RenderTarget* window)
{
	// updating input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		shape.move(-movementSpeed, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		shape.move(movementSpeed, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		shape.move(0.f, -movementSpeed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		shape.move(0.f, movementSpeed);

	sf::FloatRect playerBounds = shape.getGlobalBounds();

	// left collision
	if (playerBounds.left <= 0.f)
		shape.setPosition(0.f, shape.getPosition().y);

	// right collision
	if ((playerBounds.left + playerBounds.width) >= window->getSize().x)
		shape.setPosition(
			(window->getView().getSize().x - playerBounds.width),
			shape.getPosition().y);

	// top collision
	if (playerBounds.top <= 0.f)
		shape.setPosition(shape.getPosition().x, 0.f);

	// bottom collision
	if ((playerBounds.top + playerBounds.height) >= window->getSize().y)
		shape.setPosition(
			shape.getPosition().x,
			(window->getView().getSize().y - playerBounds.height));
}

void Player::Render(sf::RenderTarget* window)
{
	window->draw(shape);
}
