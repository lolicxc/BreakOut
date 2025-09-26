#include "Ball.h"
#include "sl.h"
#include "Draw.h"

Ball CreateBall(int xPos, int yPos, float xVelocity, float yVelocity, int radius, float speed)
{
	Ball ball;
	ball.xPos = xPos;
	ball.yPos = yPos;
	ball.radius = radius;
	ball.xVelocity = xVelocity;
	ball.yVelocity = yVelocity;
	ball.speed = speed;

	return ball;
}

void Launch(Ball& ball)
{

	int dirX = (rand() % 2 == 0) ? -1 : 1;
	int dirY = (rand() % 2 == 0) ? -1 : 1;

	ball.xVelocity = dirX * ball.speed;
	ball.yVelocity = dirY * ball.speed;   
}

void Update(Ball& ball, Paddle& paddle, Brick brick[brickRow][brickCol])
{
	float deltaTime = slGetDeltaTime();

	if (!ball.isLaunched)
	{
		ball.xPos = paddle.xPos;
		ball.yPos = paddle.yPos + paddle.height / 2 + ball.radius;

		if (slGetKey('L'))
		{
			Launch(ball);
			ball.isLaunched = true;
		}
	}
	else
	{

		ball.xPos += ball.xVelocity * deltaTime;
		ball.yPos += ball.yVelocity * deltaTime;

		if (CheckCollisionWall(ball))
		{
			ball.xVelocity *= -1;
		}

		// rebote contra paddle
		if (CheckCollisionPaddle(ball, paddle))
		{
			ball.yVelocity *= -1;


			ball.yPos = paddle.yPos + paddle.height / 2 + ball.radius;

			float hitPos = (ball.xPos - paddle.xPos) / (paddle.width / 2.0f);
			ball.xVelocity += hitPos * 300.0f;
		}

		BricksCollision(ball, brick);
		CheckLives(ball, paddle);
	}
}




void CheckScore(Ball& ball, Paddle& paddle1)
{
}

bool CheckCollisionPaddle(Ball& ball, Paddle& paddle)
{
	float paddleLeft = paddle.xPos - paddle.width / 2;
	float paddleRight = paddle.xPos + paddle.width / 2;
	float paddleTop = paddle.yPos - paddle.height / 2;
	float paddleBottom = paddle.yPos + paddle.height / 2;

	float ballLeft = ball.xPos - ball.radius;
	float ballRight = ball.xPos + ball.radius;
	float ballTop = ball.yPos - ball.radius;
	float ballBottom = ball.yPos + ball.radius;

	return (ballRight >= paddleLeft &&
		ballLeft <= paddleRight &&
		ballBottom >= paddleTop &&
		ballTop <= paddleBottom);

}

bool CheckCollisionWall(Ball& ball)
{
	if (ball.yPos + ball.radius >= screenHeight)
	{
		ball.yPos = screenHeight - ball.radius;
		ball.yVelocity *= -1;
		ball.xVelocity *= -1;
		return true;
	}
	else if (ball.xPos + ball.radius >= screenWidth)
	{
		ball.xPos = screenWidth - ball.radius;
		return true;
	}
	else if (ball.xPos - ball.radius <= 0)
	{
		ball.xPos = ball.radius;
		return true;
	}
	return false;
}

void CheckLives(Ball& ball, Paddle& paddle)
{
	const float screenWidth = 640;
	const float screenHeight = 720;

	if (ball.yPos - ball.radius <= 0)
	{
		paddle.lives--;

		//reset pos
		ball.xPos = paddle.xPos;
		ball.yPos = paddle.yPos + paddle.height / 2 + ball.radius;

		ball.xVelocity = 0;
		ball.yVelocity = 0;

		ball.isLaunched = false;
		Launch(ball);
	}
}
