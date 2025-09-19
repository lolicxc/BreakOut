#include "Paddle.h"

Paddle CreatePaddle(int xPos, int yPos, int width, int height, float speed)
{
	Paddle paddle;
	paddle.xPos = xPos;
	paddle.yPos = yPos;
	paddle.width = width;
	paddle.height = height;
	paddle.speed = speed;

	return paddle;

}

Paddle MoveRight(Paddle paddle)
{
	return Paddle();
}

Paddle MoveLeft(Paddle paddle)
{
	return Paddle();
}
