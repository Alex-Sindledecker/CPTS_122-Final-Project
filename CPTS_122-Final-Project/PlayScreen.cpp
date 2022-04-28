/*
* Class: CPTS_122
* Authors: Alondra Romero, Alex Sindledecker
* Date-Created: 4/23/22
* Description: Handles the play screen
*/

#include "PlayScreen.h"
#include <math.h>

PlayScreen::PlayScreen(sf::RenderWindow& window)
{
	width = window.getSize().x;
	height = window.getSize().y;

	//ball
	SpriteBall.setFillColor(sf::Color::Green);
	SpriteBall.setRadius(10.f);

	//paddle 
	paddle.setFillColor(sf::Color::Red);
	paddle.setSize(sf::Vector2f(100.0f, 20.f));

	//block initualized
	block.setSize(sf::Vector2f(40, 30));
	block.setOutlineThickness(1.f);
	block.setFillColor(sf::Color::Yellow);
	block.setOutlineColor(sf::Color::Black);
	//block array

	//Set all blocks to exist
	for (int i = 0; i < width / block.getSize().x * 5; i++)
		blocks.push_back(true);

	//Ball movement  and bounce

	Velocity = 75.f * 7.f;
	bounce = 0.0f;
	Vel = sf::Vector2f(0.f, 0.f);
}

void PlayScreen::onEvent(sf::Event& event, GameState& gameState)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
		gameState = GameState::PAUSED;


	if (Vel.x == 0 && event.type == sf::Event::MouseButtonPressed)  //Click of mouse releases ball
	{
		bounce = (-20 - (rand() % 140)) * (3.14 / 180);
		Vel.x = cos(bounce) * Velocity;
		Vel.y = sin(bounce) * Velocity;
	}
	else if (event.type == sf::Event::MouseMoved)  //move with the mouse  
	{
		paddle.setPosition(sf::Vector2f(mouseX - (paddle.getSize().x / 2), height - 60));

	}
}

void PlayScreen::onUpdate(float dt)
{
	if (Vel.y == 0.f)
	{
		//sets ball on the paddle
		SpriteBall.setPosition(sf::Vector2f(paddle.getPosition().x + (paddle.getSize().x / 2) - SpriteBall.getRadius(), paddle.getPosition().y - paddle.getSize().y));
	}
	else
	{
		//Change in ball position this frame (delta x, delta y
		int dx = Vel.x * dt, dy = Vel.y * dt;

		SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x + dx, SpriteBall.getPosition().y + dy));

		//Ball and Paddle Collision Detection
		if (SpriteBall.getPosition().x + (SpriteBall.getRadius() * 2.f) >= paddle.getPosition().x && SpriteBall.getPosition().y + (SpriteBall.getRadius() * 2.f) >= paddle.getPosition().y
			&& SpriteBall.getPosition().x < paddle.getPosition().x + paddle.getSize().x && SpriteBall.getPosition().y < paddle.getPosition().y + paddle.getSize().y)
		{
			SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x, paddle.getPosition().y - (SpriteBall.getRadius() * 2.0f)));
			bounceBallOnPaddle();
		}



		//Ball cant go out of winodw 
		if (SpriteBall.getPosition().x <= 0.0f)
		{
			SpriteBall.setPosition(sf::Vector2f(0.0f, SpriteBall.getPosition().y));
			Vel.x = -Vel.x; //when speed is not negative

		}
		else if (SpriteBall.getPosition().x + (SpriteBall.getRadius() * 2.f) >= width)
		{
			SpriteBall.setPosition(sf::Vector2f(width - (SpriteBall.getRadius() * 2.f), SpriteBall.getPosition().y));
			Vel.x = -Vel.x;
		}
		if (SpriteBall.getPosition().y <= 0.0f)
		{
			SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x, 0.f));
			Vel.y = -Vel.y; //when speed is not negative

		}
		else if (SpriteBall.getPosition().y + (SpriteBall.getRadius() * 2.f) >= height)
		{
			//Dead
			SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x, height - (SpriteBall.getRadius() * 2.f)));
			Vel.x = 0;
			Vel.y = 0;
		}
		

		int x = 0, y = 0;
		for (int i = 0; i < width / block.getSize().x * 5; i++)
		{
			if (blocks[i])
			{
				float l = SpriteBall.getPosition().x - SpriteBall.getRadius();
				float r = SpriteBall.getPosition().x + SpriteBall.getRadius();
				float u = SpriteBall.getPosition().y - SpriteBall.getRadius();
				float d = SpriteBall.getPosition().y + SpriteBall.getRadius();
				bool xOverlap = (l > x && l < x + block.getSize().x) || (r > x && r < x + block.getSize().x);
				bool yOverlap = (u > y && u < y + block.getSize().y) || (d > y && d < y + block.getSize().y);
				if (xOverlap && yOverlap)
				{
					Vel.y *= -1;
					blocks[i] = false;
				}
			}
			x += block.getSize().x;
			if (x >= width)
			{
				x = 0;
				y += block.getSize().y;
			}
		}
		

	}
	//int direction = 1;
	//if (SpriteBall.getGlobalBounds().intersects(paddle.getGlobalBounds()))
	//{
	//	direction *= -1;
	//}
}

void PlayScreen::draw(sf::RenderWindow& window)
{
	//Set mouse pos
	mouseX = sf::Mouse::getPosition(window).x;
	mouseY = sf::Mouse::getPosition(window).y;

	//Draw blocks
	int x = 0, y = 0;
	for (int i = 0; i < width / block.getSize().x * 5; i++)
	{
		if (blocks[i])
		{
			block.setPosition(x, y);
			window.draw(block);
		}

		x += block.getSize().x;
		if (x >= width)
		{
			x = 0;
			y += block.getSize().y;
		}
	}

	//Draw paddle and ball
	window.draw(paddle);
	window.draw(SpriteBall);
}

//Bounces the ball of the paddle - based on the paddle collision response at https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-resolution
void PlayScreen::bounceBallOnPaddle()
{
	//Distance ball and paddle are from each other
	float dx = SpriteBall.getPosition().x - paddle.getPosition().x;
	//What percent of distance is within the paddle size
	float percentage = dx / (paddle.getSize().x / 2.f);
	
	//Update velocitys
	Vel.x *= percentage * 2;
	Vel.y = -Vel.y;

	//Nomrlaize velocitys
	float len = sqrt(pow(Vel.x, 2) + pow(Vel.y, 2));
	Vel.x = Vel.x / len * Velocity;
	Vel.y = Vel.y / len * Velocity;
}
