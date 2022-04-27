/*
* Class: CPTS_122
* Authors: Alex Sindledecker
* Date-Created: 4/19/22
* Description: Class definition for text button class
*/

#pragma once

#include <SFML/Graphics.hpp>

//Text graphics that can change color when the mouse hovers over it
class TextButton
{
public:
	//Constructor 
	TextButton(const std::string& str, float x = 0, float y = 0, int textSize = 30, sf::Color color = sf::Color::White, sf::Color hoverColor = sf::Color::White);
	TextButton();

	//Sets the position text (center)
	void setCenterPos(float x, float y);
	//Sets the position of the text (top left)
	void setPos(float x, float y);
	//Sets the size of the text
	void setTextSize(int textSize);
	//Sets the color of the text
	void setColor(sf::Color color);
	//Sets the color of the text when the mouse hovers over it
	void setHoverColor(sf::Color color);

	//Returns true when the button gets pressed
	bool isPressed(sf::Event& event) const;

	//Draws the text
	void draw(sf::RenderWindow& window);

private:
	//Initializes a static font (that way we don't recreate a new font every time a button is created)
	static void initFont();

private:
	static sf::Font font;

	sf::Text text;
	sf::Color color, hoverColor;
};


/* Button example usage:

sf::RenderWindow window(...)                                                                            //
                                                                                                        //
TextButton button("Test", 0, 0, 30, sf::Color::White, sf::Color::Red);                                  // Instantiation (text, x, y, text size, color, hover color)
button.setCenterPos(window.getSize().x / 2, window.getSize().y / 2);                                    // Set the text to be center aligned on the screen
button.setTextSize(50);                                                                                 // Set the size of the text
                                                                                                        //
while (window.isOpen())                                                                                 //
{                                                                                                       //
	sf::Event event;                                                                                //
	while (window.pollEvent(event))                                                                 //
	{                                                                                               //
		if (event.type == sf::Event::Closed)                                                    //
			window.close();                                                                 //
                                                                                                        //
		if (button.isPressed(event))                                                            // Handle button events (it getting pressed). This must always be in the event loop for the button to work
			std::cout << "Pressed!" << std::endl;                                           //
	}                                                                                               //
                                                                                                        //
	window.clear();                                                                                 //
                                                                                                        //
	button.draw(window);                                                                            // - Draw button to screen
                                                                                                        //
	window.display();                                                                               //

}

*/
