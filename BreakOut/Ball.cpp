#include "Ball.h"
#include "sl.h"
#include "Draw.h"
#include "Paddle.h"
#include "Assets.h"

Ball balls[maxBalls];
int ballCount = 1;

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

void InitBalls()
{
	ballCount = 1;
	balls[0] = CreateBall(320, 100, 5.0f, 5.0f, 20, 300.0f);
	balls[0].isLaunched = false;
	balls[0].isActive = true;
}

void Launch(Ball& ball)
{

	int dirX = (rand() % 2 == 0) ? -1 : 1;
	int dirY = (rand() % 2 == 0) ? -1 : 1;

	ball.xVelocity = dirX * ball.speed;
	ball.yVelocity = dirY * ball.speed;
}

void UpdateBalls(Paddle& paddle, Brick bricks[brickRow][brickCol])
{
	for (int i = 0; i < ballCount; i++)
	{
		if (balls[i].isActive)
			Update(balls[i], paddle, bricks);
	}

	bool anyActive = false;
	for (int i = 0; i < ballCount; i++)
	{
		if (balls[i].isActive)
		{
			anyActive = true;
			break;
		}
	}

	if (!anyActive)
	{
		CheckLives(paddle);
	}
}
void DrawBalls()
{
	for (int i = 0; i < ballCount; i++)
	{
		DrawBall(balls[i]);
	}

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

		CheckCollisionWall(ball);


		// rebote contra paddle
		if (CheckCollisionPaddle(ball, paddle))
		{
			slSoundPlay(bounceSound);
			ball.yVelocity *= -1;


			ball.yPos = paddle.yPos + paddle.height / 2 + ball.radius;

			float hitPos = (ball.xPos - paddle.xPos) / (paddle.width / 2.0f);
			ball.xVelocity += hitPos * 300.0f;
		}

		BricksCollision(ball, brick);

		if (ball.yPos + ball.radius < 0)
		{
			ball.isActive = false;  
			ball.isLaunched = false; 
			return;                
		}
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
	if (ball.yPos + ball.radius >= screenHeight)   // techo
	{
		ball.yPos = screenHeight - ball.radius;
		ball.yVelocity *= -1;
		return true;
	}
	else if (ball.xPos + ball.radius >= screenWidth)  // derecha
	{
		ball.xPos = screenWidth - ball.radius;
		ball.xVelocity *= -1;
		return true;
	}
	else if (ball.xPos - ball.radius <= 0)            // izquierda
	{
		ball.xPos = ball.radius;
		ball.xVelocity *= -1;

		if (fabs(ball.xVelocity) < 100.0f)
		{
			ball.xVelocity = (ball.xVelocity < 0 ? -1 : 1) * 100.0f;
		}

		return true;
	}
	return false;
}

void CheckLives(Paddle& paddle)
{

	paddle.lives--;

	// Reinicia una sola pelota en el paddle
	ballCount = 1;
	balls[0] = CreateBall(paddle.xPos, paddle.yPos + paddle.height / 2 + 12, 5.0f, 5.0f, 20, 300.0f);
	balls[0].isLaunched = false;
}
