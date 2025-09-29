#pragma once
#include "Paddle.h"
#include "Bricks.h"
struct Ball
{
	int xPos;
	int yPos;
	int radius;
	float xVelocity;
	float yVelocity;
	float speed;
	bool hitBrick;
	int normalBallS;
	int hitBallS;
	bool isLaunched;
	float prevXPos;
	float prevYPos;
	bool isActive;
};

const int maxBalls = 10;
extern Ball balls[maxBalls];
extern int ballCount;

Ball CreateBall(int xPos, int yPos, float xVelocity, float yVelocity, int radius, float speed);
void InitBalls();
void Launch(Ball& ball);
void UpdateBalls(Paddle& paddle, Brick bricks[brickRow][brickCol]);
void DrawBalls();
void Update(Ball& ball, Paddle& paddle, Brick bricks[brickRow][brickCol]);
void CheckScore(Ball& ball, Paddle& paddle);
bool CheckCollisionPaddle(Ball& ball, Paddle& paddle);
bool CheckCollisionWall(Ball& ball);
void CheckLives(Paddle& paddle);

