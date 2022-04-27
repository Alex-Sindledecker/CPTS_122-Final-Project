/*
* Class: CPTS_122
* Authors: Alex Sindledecker, Alondra Romero
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

    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); //Delta time (the time between frames). For any animated object, multiply its speed by dt to keep consistent movement across different frame rates

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            currentScreen->onEvent(event, gameState);
        }

        //currentScreen->onUpdate(dt);

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