/*
* Class: CPTS_122
* Authors: Alex Sindledecker, ...
* Date-Created: 4/14/22
* Description: Does stuff (sfml test right now)
*/

#include <SFML/Graphics.hpp>

enum class GameState
{
    PLAYING, PAUSED, MENU, TUTORIAL, QUIT
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    GameState gameState = GameState::MENU;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        switch (gameState)
        {
        case GameState::PLAYING:
            break;
        case GameState::PAUSED:
            break;
        case GameState::MENU:
            break;
        case GameState::TUTORIAL:
            break;
        case GameState::QUIT:
            break;
        }

        window.display();
    }

    return 0;
}