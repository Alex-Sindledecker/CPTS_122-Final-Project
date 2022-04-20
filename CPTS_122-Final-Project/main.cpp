/*
* Class: CPTS_122
* Authors: Alex Sindledecker, ...
* Date-Created: 4/14/22
* Description: Does stuff (sfml test right now)
*/

#include "GameScreen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    GameState gameState = GameState::MENU;
    
    //Initial screen to go with initial game state
    //GameScreen* currentScreen = new MenuScreen(&gameState);

    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); //Delta time (the time between frames). For any animated object, multiply its speed by dt to keep consistent movement across different frame rates

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            //currentScreen->onEvent(&event);
        }

        //currentScreen->onUpdate(dt);

        window.clear();

        //currentScreen->draw(window);

        window.display();
    }

    return 0;
}