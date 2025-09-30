#include "Paddle.h"
#include "sl.h"
#include  "Draw.h"
Paddle CreatePaddle(int xPos, int yPos, int width, int height, float speed)
{
	Paddle paddle;
	paddle.xPos = xPos;
	paddle.yPos = yPos;
	paddle.width = width;
	paddle.height = height;
	paddle.speed = speed;
	paddle.lives = 3;

	return paddle;

}

Paddle MoveRight(Paddle paddle)
{
	float deltaTime = slGetDeltaTime();
	paddle.xPos += paddle.speed * deltaTime;
	if (paddle.xPos + paddle.width / 2 > screenWidth)
	{
		paddle.xPos = screenWidth - paddle.width / 2;
	}

	return paddle;
}

Paddle MoveLeft(Paddle paddle)
{
	float deltaTime = slGetDeltaTime();
	paddle.xPos -= paddle.speed * deltaTime;
	if (paddle.xPos < 20)
	{
		paddle.xPos = 20;
	}


	return paddle;
}
