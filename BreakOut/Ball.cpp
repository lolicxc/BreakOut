#include "Ball.h"
#include "sl.h"

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
	// Elegir dirección aleatoria X y Y
	int dirX = (std::rand() % 2 == 0) ? -1 : 1;
	int dirY = (std::rand() % 2 == 0) ? -1 : 1;

	ball.xVelocity = dirX * ball.speed;
	ball.yVelocity = dirY * ball.speed;
	//ball.xVelocity = ball.speed;    
	//ball.yVelocity = -ball.speed;    
}

void Update(Ball& ball, Paddle& paddle, Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE])
{
	float deltaTime = slGetDeltaTime();

	ball.xPos += ball.xVelocity * deltaTime;
	ball.yPos += ball.yVelocity * deltaTime;


	if (CheckCollisionWall(ball))
	{
		ball.xVelocity *= -1;
	}
	// Rebote contra paddle
	if (CheckCollisionPaddle(ball, paddle))
	{

		if (ball.yVelocity < 0)
		{
			ball.yVelocity *= -1;
	
			ball.yPos = paddle.yPos - paddle.height / 2 - ball.radius;
		}
		ball.yPos = paddle.yPos + paddle.width/2;
	}

	BricksCollision(ball, brick);
	CheckLives(ball, paddle);
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
	if (ball.yPos + ball.radius >= 720)
	{
		ball.yPos = 720 - ball.radius;
		ball.yVelocity *= -1;
		return true;
	}
	else if (ball.xPos + ball.radius >= 640)
	{
		ball.xPos = 640 - ball.radius;
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

	if (ball.yPos - ball.radius <= 0) // "se pasó de la pantalla"
	{
		paddle.lives--;

		// Reiniciar posición al centro
		ball.xPos = screenWidth / 2;
		ball.yPos = screenHeight / 2;

		Launch(ball);
	}
}
