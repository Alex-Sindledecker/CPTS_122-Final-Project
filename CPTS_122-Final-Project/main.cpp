/*
* Class: CPTS_122
* Authors: Alex Sindledecker, Alondra Romero, Alec Barran, Khoi Vu
* Date-Created: 4/14/22
* Description: Runs the application
*/

#include "GameScreen.h"
#include "MenuScreen.h"
#include "PlayScreen.h"
#include "PauseScreen.h"
#include "TutorialScreen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Breakout");
    window.setFramerateLimit(60);

    //Initial screen to go with initial game state
    GameState gameState = GameState::MENU;
    
    MenuScreen menuScreen;
    PlayScreen playScreen(window);
    PauseScreen pauseScreen(&playScreen);
    TutorialScreen tutorialScreen(window);

    GameScreen* currentScreen = &menuScreen;

    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); //Delta time (the time between frames). For any animated object, multiply its speed by dt to keep consistent movement across different frame rates

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            //Check for events on the currentScreen
            currentScreen->onEvent(event, gameState);
        }

        //Update current screen
        currentScreen->onUpdate(dt);

        window.clear();

        //Check the game state and update the current screen to match the game state
        switch (gameState)
        {
        case GameState::PLAYING:
            currentScreen = &playScreen;
            break;
        case GameState::PAUSED:
            currentScreen = &pauseScreen;
            break;
        case GameState::MENU:
            currentScreen = &menuScreen;
            break;
        case GameState::TUTORIAL:
            currentScreen = &tutorialScreen;
            break;
        case GameState::QUIT:
            window.close();
            break;
        }

        //Draw the current screen
        currentScreen->draw(window);

        window.display();
    }

    return 0;
}