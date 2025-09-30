#pragma once
#include <iostream>


struct Paddle
{
	int xPos;
	int yPos;
	int width = 20;
	int height = 20;
	float speed = 5.0f;
	int lives;
};

Paddle CreatePaddle(int xPos, int yPos, int width, int height, float speed);
Paddle MoveRight(Paddle paddle);
Paddle MoveLeft(Paddle paddle);