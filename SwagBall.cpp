#include "SwagBall.h"

SwagBall::SwagBall(sf::RenderTarget* window)
{
	if (window)
	{
		shape.setRadius(static_cast<float>(rand() % 10 + 10));
		sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		shape.setFillColor(color);
		shape.setPosition(
			static_cast<float>(rand() % window->getSize().x),
			static_cast<float>(rand() % window->getSize().y)
		);
	}
}

SwagBall::~SwagBall()
{
}

void SwagBall::Update()
{
}

void SwagBall::Render(sf::RenderTarget* window)
{
	window->draw(shape);
}
