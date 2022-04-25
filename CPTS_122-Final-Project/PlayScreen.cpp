
#include "PlayScreen.h"
#include <math.h>
PlayScreen::PlayScreen(int w, int h, string title)
{
	width = w;
	height = h;
	window = new RenderWindow(sf::VideoMode(w, h), title);
	window->setFramerateLimit(70);

	//ball
	SpriteBall.setFillColor(Color::Green);
	SpriteBall.setRadius(10.f);

	//paddle 
	paddle.setFillColor(Color::Red);
	paddle.setSize(Vector2f(100.0f, 20.f));

	//block initualized
	block.setSize(Vector2f(40, 30));
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
	Vel = Vector2f(0.f, 0.f);



}
PlayScreen::~PlayScreen()
{
	delete window;
	delete[] isBlock;
}


void PlayScreen::onEvent(Event event)
{

	if (event.type == sf::Event::Closed)
	{
		window->close();
	}
	else if (event.type == Event::MouseButtonPressed)  //Click of mouse releases ball
	{
		bounce = (-20 - (rand() % 140)) * (3.14 / 180);
		Vel.x = cos(bounce) * Velocity;
		Vel.y = sin(bounce) * Velocity;
	}
	else if (event.type == Event::MouseMoved)  //move with the mouse  
	{
		paddle.setPosition(Vector2f(Mouse::getPosition(*window).x - (paddle.getSize().x / 2), height - 60));

	}


}

void PlayScreen::update(double dT)
{
	if (Vel.y == 0.f)
	{
		//sets ball on the paddle
		SpriteBall.setPosition(Vector2f(paddle.getPosition().x + (paddle.getSize().x / 2) - SpriteBall.getRadius(), paddle.getPosition().y - paddle.getSize().y));
	}
	else
	{
		SpriteBall.setPosition(Vector2f(SpriteBall.getPosition().x + Vel.x, SpriteBall.getPosition().y + Vel.y));

		//Ball and Paddle Collision Detection
		if (SpriteBall.getPosition().x + (SpriteBall.getRadius() * 2.f) >= paddle.getPosition().x && SpriteBall.getPosition().y + (SpriteBall.getRadius() * 2.f) >= paddle.getPosition().y
			&& SpriteBall.getPosition().x < paddle.getPosition().x + paddle.getSize().x && SpriteBall.getPosition().y < paddle.getPosition().y + paddle.getSize().y)
		{
			SpriteBall.setPosition(Vector2f(SpriteBall.getPosition().x, paddle.getPosition().y - (SpriteBall.getRadius() * 2.0f)));
			Vel.y = -abs(Vel.y);
		}



		//Ball cant go out of winodw 
		if (SpriteBall.getPosition().x <= 0.0f)
		{
			SpriteBall.setPosition(Vector2f(0.0f, SpriteBall.getPosition().y));
			Vel.x = abs(Vel.x); //when speed is not negative

		}
		else if (SpriteBall.getPosition().x + (SpriteBall.getRadius() * 2.f) >= width)
		{
			SpriteBall.setPosition(Vector2f(width - (SpriteBall.getRadius() * 2.f), SpriteBall.getPosition().y));
			Vel.x = abs(Vel.x);
		}
		if (SpriteBall.getPosition().y <= 0.0f)
		{
			SpriteBall.setPosition(Vector2f(SpriteBall.getPosition().x, 0.f));
			Vel.y = abs(Vel.y); //when speed is not negative

		}
		else if (SpriteBall.getPosition().y + (SpriteBall.getRadius() * 2.f) >= height)
		{
			SpriteBall.setPosition(Vector2f(SpriteBall.getPosition().x, height - (SpriteBall.getRadius() * 2.f)));
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
void PlayScreen::draw()
{
	int i, j;

	//Draws the Block Array 
	for (i = 0; i < height; i += block.getSize().x)
	{
		for (j = 0; j < width; j += block.getSize().y)
		{
			if (isBlock[(int)((j / block.getSize().y) + ((i / block.getSize().x) * (width / block.getSize().y)))])
			{
				block.setFillColor(Color::Yellow);
				block.setOutlineColor(Color::Black);
				block.setPosition(Vector2f(j, i));
				window->draw(block);
			}
		}
	}
	window->draw(paddle);
	window->draw(SpriteBall);


}

void PlayScreen::run()
{
	Clock time;
	double dT = 0.0f;
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			onEvent(event);
		}
		update(dT);

		window->clear();
		draw();
		window->display();

		dT = time.getElapsedTime().asSeconds();
	}
}