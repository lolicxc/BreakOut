#pragma once
#include "Bricks.h"
#include "Ball.h"
#include "PowerUps.h"

void InitBricks(Brick brick[brickRow][brickCol])
{
	int initialDownPosition = 600;
	int spacingX = 3;
	int spacingY = 5;

	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickCol; j++)
		{
			brick[i][j].width = 60;
			brick[i][j].height = 30;


			brick[i][j].xPos = j * (brick[i][j].width + spacingX) + brick[i][j].width / 2 + 40;
			brick[i][j].yPos = initialDownPosition - i * (brick[i][j].height + spacingY) - brick[i][j].height / 2;

			brick[i][j].active = true;

			brick[i][j].texture = rand() % 3;
		}
	}
}

void BricksCollision(Ball& ball, Brick brick[brickRow][brickCol])
{
	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickCol; j++)
		{
			Brick& b = brick[i][j];

			if (!b.active)
				continue;

			// Datos del ladrillo
			float brickLeft = b.xPos - b.width / 2;
			float brickRight = b.xPos + b.width / 2;
			float brickTop = b.yPos + b.height / 2;
			float brickBottom = b.yPos - b.height / 2;

			// Datos de la pelota
			float ballLeft = ball.xPos - ball.radius;
			float ballRight = ball.xPos + ball.radius;
			float ballTop = ball.yPos + ball.radius;
			float ballBottom = ball.yPos - ball.radius;

			// Verificamos colisión general
			bool collisionX = ballRight >= brickLeft && ballLeft <= brickRight;
			bool collisionY = ballTop >= brickBottom && ballBottom <= brickTop;

			if (collisionX && collisionY)
			{
				// Determinar qué lado golpeó: chequear la profundidad de penetración
				float overlapLeft = ballRight - brickLeft;
				float overlapRight = brickRight - ballLeft;
				float overlapTop = brickTop - ballBottom;
				float overlapBottom = ballTop - brickBottom;

				// Determinar la menor superposición
				bool ballFromLeft = overlapLeft < overlapRight;
				bool ballFromBottom = overlapBottom < overlapTop;

				float minXOverlap = ballFromLeft ? overlapLeft : overlapRight;
				float minYOverlap = ballFromBottom ? overlapBottom : overlapTop;

				// Decide si rebotar en X o Y
				if (minXOverlap < minYOverlap)
				{
					// Rebotar horizontal
					ball.xVelocity *= -1;
					if (ballFromLeft)
						ball.xPos = brickLeft - ball.radius;
					else
						ball.xPos = brickRight + ball.radius;
				}
				else
				{
					// Rebotar vertical
					ball.yVelocity *= -1;
					if (ballFromBottom)
						ball.yPos = brickBottom - ball.radius;
					else
						ball.yPos = brickTop + ball.radius;
				}

				b.active = false;

				if (rand() % 100 < 30) // 30% chance
				{
					for (int k = 0; k < maxPowerUps; k++)
					{
						if (!powerUps[k].active)
						{
							powerUps[k].type = (POWERUPTYPE)(rand() % 4);
							powerUps[k].xPos = b.xPos;
							powerUps[k].yPos = b.yPos;
							powerUps[k].speedY = 150.0f;
							powerUps[k].active = true;
							break;
						}
					}
				}
				return;
			}
		}
	}
}


