#include "MenuScreen.h"

MenuScreen::MenuScreen() {
	// text for menu options
	std::string options[3] = {"Play Game", "Tutorial", "Exit"};

	// Instantiation (text, x, y, text size, color, hover color)
	// easy loop to maintain menu style
	for (int i = 0; i < 3; i++) {
		buttons[i] = new TextButton(options[i], 100, 300 + i * 100, 30, sf::Color::White, sf::Color::Red);
	}
}

void MenuScreen::onEvent(sf::Event& event, GameState& gameState) {
	// play game
	if (buttons[0]->isPressed(event)) {
		gameState = GameState::PLAYING;
	}
	// tutorial
	else if (buttons[1]->isPressed(event)) {
		gameState = GameState::TUTORIAL;
	}
	// exit
	else if (buttons[2]->isPressed(event)) {
		gameState = GameState::QUIT;
	}
}

void MenuScreen::onUpdate(float dt) {
	// would like to have a ball just bounce around the screen
	// but will have to see the style of the game itself first
}

void MenuScreen::draw(sf::RenderWindow& window) {
	// for the sake of consistency and ease
	// this text will be a button but never updated
	TextButton title = { "BREAKOUT", 100, 50, 100, sf::Color::Red, sf::Color::Red };
	title.draw(window);

	// draw all the buttons
	for (int i = 0; i < 3; i++) {
		buttons[i]->draw(window);
	}
}