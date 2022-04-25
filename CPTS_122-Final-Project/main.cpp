/*
* Class: CPTS_122
* Authors: Alex Sindledecker, Alondra Romero
* Date-Created: 4/14/22
* Description: Does stuff (sfml test right now)
*/

//#include "GameScreen.h"
#include "PlayScreen.h"
#include <SFML/Graphics.hpp> 

int main()
{
    PlayScreen PlayScreen(1000, 800, "PLayScreen Works");
    PlayScreen.run();

    return 0;
}