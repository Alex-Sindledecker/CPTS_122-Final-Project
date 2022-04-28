/*
* Class: CPTS_122
* Authors: Alondra Romero, Alex Sindledecker
* Date-Created: 4/23/22
* Description: Handles the play screen
*/

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
	//Bounces the ball of the paddle - based on the paddle collision response at https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-resolution
	void bounceBallOnPaddle();

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
