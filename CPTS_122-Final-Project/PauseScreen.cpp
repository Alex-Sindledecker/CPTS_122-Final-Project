#include "PauseScreen.h"

PauseScreen::PauseScreen(PlayScreen* playScreen)
	: resumeButton("Resume", 100, 300, 30, sf::Color::White, sf::Color::Red), returnButton("Return To Menu", 100, 400, 30, sf::Color::White, sf::Color::Red),
	  quitButton("Exit", 100, 500, 30, sf::Color::White, sf::Color::Red)
{
	titleFont.loadFromFile("res/fonts/ROGFonts-Regular.otf");
	title.setFont(titleFont);
	title.setCharacterSize(100);
	title.setString("Breakout");
	title.setPosition(100, 50);
	title.setFillColor(sf::Color::Red);

	alphaCover.setFillColor(sf::Color(187, 187, 187, 35));

	playScreenPtr = playScreen;
}

void PauseScreen::onEvent(sf::Event& event, GameState& gameState)
{
	if (resumeButton.isPressed(event))
		gameState = GameState::PLAYING;
	else if (returnButton.isPressed(event))
		gameState = GameState::MENU;
	else if (quitButton.isPressed(event))
		gameState = GameState::QUIT;
}

void PauseScreen::onUpdate(float dt)
{
	
}

void PauseScreen::draw(sf::RenderWindow& window)
{
	alphaCover.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

	playScreenPtr->draw(window);

	window.draw(alphaCover);

	window.draw(title);
	resumeButton.draw(window);
	returnButton.draw(window);
	quitButton.draw(window);
}
