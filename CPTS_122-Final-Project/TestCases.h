/*
* Class: CPTS_122
* Authors: Alex Sindledecker
* Date-Created: 4/28/22
* Description: Functions for testing
*/
#pragma once

#include <thread>

namespace test
{

	//Starts testing asynchronously
	void startTesting();
	//Ends testing (joins testing threads)
	void endTesting();

	//Tests buttons (runs on a seperate thread)
	void _testButtons();
	//Tests paddle movement (runs on a seperate thread)
	void _testPaddleMovement();
	//Tests ball paddle collisions (runs on a seperate thread)
	void _testBallPaddleBounce();
	//Test ball block collisions (runs on a seperate thread)
	void _testBallBlockBounce();
	//Test the ball to make sure its in the bounds
	void _testBounds();

}