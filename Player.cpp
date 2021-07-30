#include "Player.h"

Player::Player()
{
	shape.setFillColor(sf::Color::Magenta);
	shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(shape);
}
