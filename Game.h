#pragma once

namespace sf
{
	class RenderWindow;
}

class Game
{
private:
	sf::RenderWindow* window;
	bool endGame;

public:
	Game();
	~Game();

	void Update();
	void Render();
};

