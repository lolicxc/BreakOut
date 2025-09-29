#pragma once
#include <iostream>


struct Paddle
{
	int xPos;
	int yPos;
	int width = 10;
	int height = 10;
	float speed = 5.0f;
	int lives = 5;
};

Paddle CreatePaddle(int xPos, int yPos, int width, int height, float speed);
Paddle MoveRight(Paddle paddle);
Paddle MoveLeft(Paddle paddle);