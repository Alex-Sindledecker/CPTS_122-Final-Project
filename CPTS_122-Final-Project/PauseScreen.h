/*
* Class: CPTS_122
* Authors: Alex Sindledecker
* Date-Created: 4/14/22
* Description: Runs the application
*/

#pragma once

#include "GameScreen.h"
#include "PlayScreen.h"
#include "TextButton.h"

class PauseScreen : public GameScreen
{
public:
	PauseScreen(PlayScreen* playScreen);

	// Inherited via GameScreen
	virtual void onEvent(sf::Event& event, GameState& gameState) override;
	virtual void onUpdate(float dt) override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	PlayScreen* playScreenPtr;

	TextButton resumeButton;
	TextButton returnButton;
	TextButton quitButton;

	//Gray background that darkens the game to indicate that the game is paused.
	sf::RectangleShape alphaCover;

	sf::Text title;
	sf::Font titleFont;
};

