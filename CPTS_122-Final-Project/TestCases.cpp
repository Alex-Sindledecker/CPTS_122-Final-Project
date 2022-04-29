#include "TestCases.h"

#include <iostream>

namespace test
{

	static std::thread thread;

	void startTesting()
	{
		//Start a thread for running the test cases
		thread = std::thread([]() {
			_testButtons();
			_testPaddleMovement();
			_testBallPaddleBounce();
			_testBallBlockBounce();
			_testBounds();
		});
	}

	void endTesting()
	{
		thread.join();
	}

	void _testButtons()
	{
		char result1, result2;
		std::cout << "Do all the buttons change color when you hover over them? (y/n): ";
		std::cin >> result1;
		std::cout << "Do all the buttons do something? (y/n): ";
		std::cin >> result2;

		if (result1 == 'n' || result2 == 'n')
			std::cout << "The button tests failed!" << std::endl;
		else
			std::cout << "The button tests succeeded" << std::endl;
	}

	void _testPaddleMovement()
	{
		char result1;
		std::cout << "Does the paddle move with the muouse? (y/n): ";
		std::cin >> result1;

		if (result1 == 'n')
			std::cout << "The paddle tests failed!" << std::endl;
		else
			std::cout << "The paddle tests succeeded" << std::endl;
	}

	void _testBallPaddleBounce()
	{
		char result1;
		std::cout << "Does the ball bounce of the paddle and have varying bounce angles? (y/n): ";
		std::cin >> result1;

		if (result1 == 'n')
			std::cout << "The paddle ball tests failed!" << std::endl;
		else
			std::cout << "The paddle ball tests succeeded" << std::endl;
	}

	void _testBallBlockBounce()
	{
		char result1;
		std::cout << "Does the ball bounce of the blocks correctly? (y/n): ";
		std::cin >> result1;

		if (result1 == 'n')
			std::cout << "The block ball tests failed!" << std::endl;
		else
			std::cout << "The block ball tests succeeded" << std::endl;
	}

	void _testBounds()
	{
		char result1;
		std::cout << "Does the ball stay in the bounds? (y/n): ";
		std::cin >> result1;

		if (result1 == 'n')
			std::cout << "The ball window tests failed!" << std::endl;
		else
			std::cout << "The ball window tests succeeded" << std::endl;
	}

}