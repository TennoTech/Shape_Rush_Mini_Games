#include "SwagBall.h"

SwagBall::SwagBall(sf::RenderTarget* window, short ballType)
	:
	type{ ballType }
{
	shape.setRadius(static_cast<float>(rand() % 10 + 10));
	shape.setPosition(
	static_cast<float>(rand() % window->getSize().x),
		static_cast<float>(rand() % window->getSize().y)
		);

	sf::Color color;
	switch (type)
	{
	case DEFAULT:
		color = sf::Color::White;
		break;
	case DAMAGING:
		color = sf::Color::Red;
		break;
	case HEALING:
		color = sf::Color::Green;
		break;
	}
	shape.setFillColor(color);
}

const short& SwagBall::GetType() const
{
	return type;
}

const sf::CircleShape& SwagBall::GetSwagBall() const
{
	return shape;
}

void SwagBall::Render(sf::RenderTarget* window)
{
	window->draw(shape);
}
