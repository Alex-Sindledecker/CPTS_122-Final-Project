/*
* Class: CPTS_122
* Authors: Alex Sindledecker
* Date-Created: 4/18/22
* Description: Abstract GameScreen class and GameState enum
*/

#pragma once

#include <SFML/Graphics.hpp>

//State of the game
enum class GameState
{
    PLAYING, PAUSED, MENU, TUTORIAL, QUIT
};

//Abstract class for processing each game state
class GameScreen
{
public:
    //Virtual destructor forces abstractness
    virtual ~GameScreen() {}

    //Call whenever there is an event
    virtual void onEvent(sf::Event& event, GameState& gameState) = 0;
    //Call every frame to update the screen
    virtual void onUpdate(float dt) = 0;
    //Draw the screen
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    //Pointer to the game state so it can be changed
    GameState* state;
};

