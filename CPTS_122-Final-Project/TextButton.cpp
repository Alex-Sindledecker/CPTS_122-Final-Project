/*
* Class: CPTS_122
* Authors: Alex Sindledecker
* Date-Created: 4/19/22
* Description: Class implimentation for text button class
*/

#include "TextButton.h"

#include <iostream>

TextButton::TextButton(const std::string& str, float x, float y, int textSize, sf::Color color, sf::Color hoverColor)
{
	//Initialize font
	if (!font.loadFromFile("res/fonts/ROGFonts-Regular.otf"))
		std::cout << "ERROR: Failed to load font: \"res/fonts/ROGFonts-Regular.otf\"" << std::endl;

	//Initialize text
	text.setFont(font);
	text.setCharacterSize(textSize);
	text.setString(str);

	setPos(x, y);
	setColor(color);
	setHoverColor(hoverColor);
}

TextButton::TextButton()
{
	setPos(0, 0);
}

void TextButton::setCenterPos(float x, float y)
{
	//Move the top left of the text back by half the size of the box. This alows you to possition it via the middle coord
	text.setPosition(x - text.getGlobalBounds().width / 2, y - text.getGlobalBounds().height / 2);
}

void TextButton::setPos(float x, float y)
{
	text.setPosition(x, y);
}

void TextButton::setTextSize(int textSize)
{
	text.setCharacterSize(textSize);
}

void TextButton::setColor(sf::Color color)
{
	this->color = color;
}

void TextButton::setHoverColor(sf::Color color)
{
	hoverColor = color;
}

bool TextButton::isPressed(sf::Event& event) const
{
	//If the mouse is over the text and the left mouse button gets pressed
	if (text.getFillColor() == hoverColor && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
		return true;
	return false;
}

void TextButton::draw(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	//Check if mouse is over the button and change color accordingly
	if (mousePos.x > text.getGlobalBounds().left && mousePos.x < text.getGlobalBounds().left + text.getGlobalBounds().width &&
		mousePos.y > text.getGlobalBounds().top && mousePos.y < text.getGlobalBounds().top + text.getGlobalBounds().height)
		text.setFillColor(hoverColor);
	else
		text.setFillColor(color);

	window.draw(text);
}
