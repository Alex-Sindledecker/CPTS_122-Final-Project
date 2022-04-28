/*
* Class: CPTS_122
* Authors: Khoi Vu
* Date-Created: 4/27/22
* Description: Handles the pause screen
*/

#include "TutorialScreen.h"

// Show instruction how to play Breakout
TutorialScreen::TutorialScreen(sf::RenderWindow& window): backButton("back", 0, 0, 30, sf::Color(255, 215, 0), sf::Color::Red){
	font.loadFromFile("res/fonts/Aclonica-Regular.ttf"); 
	int i;
	for (i = 0; i < 5; i++){
		text[i].setFont(font);
		text[i].setCharacterSize(35);
		text[i].setFillColor(sf::Color(160, 130, 10));
	}

	text[0].setString("1. Move the paddle with your mouse.");
	text[1].setString("2. Left click to launch the ball.");
	text[2].setString("3. Destroy all the bricks to win the game");
	text[3].setString("4. Do not let the ball hit the ground.");
	text[4].setString("5. Press 'Esc' to pause the game");

	for (i = 0; i < 5; i++) {
		text[i].setPosition(window.getSize().x / 2 - text[i].getGlobalBounds().width / 2, 100 * i + 100);
	}

	background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	background.setFillColor(sf::Color::Blue);
}

// back to the main menu
void TutorialScreen::onEvent(sf::Event& event, GameState& gameState){
	if (backButton.isPressed(event))
		gameState = GameState::MENU;
}

//updating tutorial screen
void TutorialScreen::onUpdate(float dt){
}

// drawing the screen
void TutorialScreen::draw(sf::RenderWindow& window){
	window.draw(background);

	int i;
	for (i = 0; i < 5; ++i) {
		window.draw(text[i]);
	}
	backButton.draw(window);
}
