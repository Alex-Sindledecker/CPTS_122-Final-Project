/*
* Class: CPTS_122
* Authors: Alex Sindledecker, ...
* Date-Created: 4/14/22
* Description: Does stuff (sfml test right now)
*/

#include "GameScreen.h"
#include "MenuScreen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Breakout");

    //Initial screen to go with initial game state
    GameState gameState = GameState::MENU;
    GameScreen* currentScreen = new MenuScreen;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            currentScreen->onEvent(event, gameState);
        }

        window.clear();

        switch (gameState)
        {
        case GameState::PLAYING:
            break;
        case GameState::PAUSED:
            break;
        case GameState::MENU:
            currentScreen->draw(window);
            break;
        case GameState::TUTORIAL:
            break;
        case GameState::QUIT:
            window.close();
            break;
        }

        window.display();
    }

    return 0;
}