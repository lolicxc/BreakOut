#include "PowerUps.h"
#include "sl.h"
#include "Ball.h"

const int maxPowerUps = 10;
PowerUp powerUps[maxPowerUps] = {}; 

void UpdatePowerUp()
{
	float deltaTime = slGetDeltaTime();
	for (int i = 0; i < maxPowerUps; i++)
	{
		if (powerUps[i].active)
		{
			powerUps[i].yPos -= powerUps[i].speedY * deltaTime;

			if (powerUps[i].yPos < 0)
			{
				powerUps[i].active = false;
			}
		}
	}
}

bool CheckCollisionPowerUp(PowerUp& p, Paddle& paddle)
{
	if (!p.active)
		return false;

	float powerUpBottom = p.yPos - 20.0f;

	float paddleTop = paddle.yPos + paddle.height / 2.0f;

	if (powerUpBottom <= paddleTop)
	{
		
		if (p.xPos >= paddle.xPos - paddle.width / 2.0f &&
			p.xPos <= paddle.xPos + paddle.width / 2.0f)
		{
	
			p.yPos = paddleTop + 20.0f;
			p.active = false;

			return true;
		}
	}

	return false;

}

void ApplyPowerUpEffect(PowerUp& p, Paddle& paddle)
{
	const float maxPaddleWidth = 200.0f; 
	switch (p.type)
	{
	case POWERUPTYPE::MAXPADDLE:
		if (paddle.width < maxPaddleWidth)
		{
			paddle.width *= 1.5f;

			if (paddle.width > maxPaddleWidth) 
			{
				paddle.width = maxPaddleWidth;
			}
		}
		break;

	case POWERUPTYPE::THREEBALLS:
		if (ballCount < maxBalls - 2)
		{
			// clonar la pelota

			balls[ballCount] = balls[0];
			balls[ballCount].xVelocity *= -1;
			ballCount++;

			balls[ballCount] = balls[0];
			balls[ballCount].yVelocity *= -1;
			ballCount++;
		}
		break;
	}
}

void UpdatePowerUpLogic(Paddle& paddle)
{
	for (int i = 0; i < maxPowerUps; i++)
	{
		if (CheckCollisionPowerUp(powerUps[i], paddle))
		{
			ApplyPowerUpEffect(powerUps[i], paddle);
		}
	}
}
