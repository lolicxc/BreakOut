#pragma once
#include "Paddle.h"

struct Ball
{
	int xPos;
	int yPos;
	int radius;
	float xVelocity;
	float yVelocity;
	float speed;
};

Ball CreateBall(int xPos, int yPos, float xVelocity, float yVelocity, int radius, float speed);
void Launch(Ball& ball);
void Update(Ball& ball, Paddle& paddle1);
void CheckScore(Ball& ball, Paddle& paddle1);
bool CheckCollisionPaddle(Ball& ball, Paddle& paddle);
bool CheckCollisionWall(Ball& ball);

