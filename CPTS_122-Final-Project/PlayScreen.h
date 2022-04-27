#pragma once

#include "GameScreen.h"

class PlayScreen : public GameScreen
{
public:
	PlayScreen(sf::RenderWindow& window);
	~PlayScreen();

	virtual void onEvent(sf::Event& event, GameState& gameState) override;
	virtual void onUpdate(float dt) override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	sf::CircleShape SpriteBall;
	sf::RectangleShape paddle;
	sf::RectangleShape block;
	double Velocity;
	double bounce;
	sf::Vector2f Vel;
	int width;
	int height;
	bool* isBlock;

	float mouseX, mouseY;

};
