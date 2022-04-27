
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
	//block array
	int BlockArray;
	BlockArray = (width / block.getSize().x) * (height / block.getSize().y);
	isBlock = new bool[BlockArray];
	int i;
	for (i = 0; i < BlockArray; i++)
	{
		isBlock[i] = false;
	}

	for (i = 0; i < 125; i++)
	{
		isBlock[i] = true;
	}
	//Ball movement  and bounce

	Velocity = 7.f;
	bounce = 0.0f;
	Vel = sf::Vector2f(0.f, 0.f);
}

PlayScreen::~PlayScreen()
{
	delete[] isBlock;
}

void PlayScreen::onEvent(sf::Event& event, GameState& gameState)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
		gameState = GameState::MENU;


	if (event.type == sf::Event::MouseButtonPressed)  //Click of mouse releases ball
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
		const int ballSpeed = 100;
		//Change in ball position this frame (delta x, delta y
		int dx = Vel.x * dt * ballSpeed, dy = Vel.y * dt * ballSpeed;

		SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x + dx, SpriteBall.getPosition().y + dy));

		//Ball and Paddle Collision Detection
		if (SpriteBall.getPosition().x + (SpriteBall.getRadius() * 2.f) >= paddle.getPosition().x && SpriteBall.getPosition().y + (SpriteBall.getRadius() * 2.f) >= paddle.getPosition().y
			&& SpriteBall.getPosition().x < paddle.getPosition().x + paddle.getSize().x && SpriteBall.getPosition().y < paddle.getPosition().y + paddle.getSize().y)
		{
			SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x, paddle.getPosition().y - (SpriteBall.getRadius() * 2.0f)));
			Vel.y = -abs(Vel.y);
		}



		//Ball cant go out of winodw 
		if (SpriteBall.getPosition().x <= 0.0f)
		{
			SpriteBall.setPosition(sf::Vector2f(0.0f, SpriteBall.getPosition().y));
			Vel.x = abs(Vel.x); //when speed is not negative

		}
		else if (SpriteBall.getPosition().x + (SpriteBall.getRadius() * 2.f) >= width)
		{
			SpriteBall.setPosition(sf::Vector2f(width - (SpriteBall.getRadius() * 2.f), SpriteBall.getPosition().y));
			Vel.x = abs(Vel.x);
		}
		if (SpriteBall.getPosition().y <= 0.0f)
		{
			SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x, 0.f));
			Vel.y = abs(Vel.y); //when speed is not negative

		}
		else if (SpriteBall.getPosition().y + (SpriteBall.getRadius() * 2.f) >= height)
		{
			SpriteBall.setPosition(sf::Vector2f(SpriteBall.getPosition().x, height - (SpriteBall.getRadius() * 2.f)));
			Vel.y = abs(Vel.y);
		}
		//this is where the ball colliosin with the brick would go but im not sure how to do it. 5

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

	int i, j;

	//Draws the Block Array 
	for (i = 0; i < height; i += block.getSize().x)
	{
		for (j = 0; j < width; j += block.getSize().y)
		{
			if (isBlock[(int)((j / block.getSize().y) + ((i / block.getSize().x) * (width / block.getSize().y)))])
			{
				block.setFillColor(sf::Color::Yellow);
				block.setOutlineColor(sf::Color::Black);
				block.setPosition(sf::Vector2f(j, i));
				window.draw(block);
			}
		}
	}
	window.draw(paddle);
	window.draw(SpriteBall);
}
