#pragma once

#include "GameScreen.h"
#include "TextButton.h"

class MenuScreen : public GameScreen
{
public:
	MenuScreen();
	//Call whenever there is an event
	virtual void onEvent(sf::Event& event, GameState& gameState);
	//Call every frame to update the screen
	virtual void onUpdate(float dt);
	//Draw the screen
	virtual void draw(sf::RenderWindow& window);

private:
	TextButton* buttons[3];
};