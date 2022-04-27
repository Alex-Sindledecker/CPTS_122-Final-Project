#pragma once
//#include "GameScreen.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;
using namespace sf;

class PlayScreen
{
public:
	PlayScreen(int w, int h, string title);
	~PlayScreen();
	void onEvent(Event event);
	void update(double dT);
	void draw();

	void run();
private:
	CircleShape SpriteBall;
	RectangleShape paddle;
	RectangleShape block;
	RenderWindow* window = NULL;
	double Velocity;
	double bounce;
	Vector2f Vel;
	int width;
	int height;
	bool* isBlock;

};
