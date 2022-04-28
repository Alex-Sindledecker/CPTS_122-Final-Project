/*
* Class: CPTS_122
* Authors: Khoi Vu
* Date-Created: 4/27/22
* Description: Handles the pause screen
*/

#pragma once

#include "GameScreen.h"
#include "TextButton.h"

class TutorialScreen : public GameScreen{
private:
	sf::Text text[5];
	sf::Font font;

	sf::RectangleShape background;

	TextButton backButton;

public:
	TutorialScreen(sf::RenderWindow& window);

	// Inherited from GameScreen
	virtual void onEvent(sf::Event& event, GameState& gameState) override;
	virtual void onUpdate(float dt) override;
	virtual void draw(sf::RenderWindow& window) override;
};

