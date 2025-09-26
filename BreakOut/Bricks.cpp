#pragma once
#include "Bricks.h"
#include "Ball.h"

void InitBricks(Brick brick[brickRow][brickCol])
{
	int initialDownPosition = 650;
	int spacingX = 3;
	int spacingY = 5;

	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickCol; j++)
		{
			brick[i][j].width = 60;
			brick[i][j].height = 30;


			brick[i][j].xPos = j * (brick[i][j].width + spacingX) + brick[i][j].width / 2 + 65;
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
            if (!b.active) continue;

            float brickLeft = b.xPos - b.width / 2;
            float brickRight = b.xPos + b.width / 2;
            float brickTop = b.yPos - b.height / 2;
            float brickBottom = b.yPos + b.height / 2;

            float ballLeft = ball.xPos - ball.radius;
            float ballRight = ball.xPos + ball.radius;
            float ballTop = ball.yPos - ball.radius;
            float ballBottom = ball.yPos + ball.radius;

            if (ballRight >= brickLeft &&
                ballLeft <= brickRight &&
                ballBottom >= brickTop &&
                ballTop <= brickBottom)
            {
     
                ball.hitBrick = true;
                b.active = false;

                float overlapLeft = ballRight - brickLeft;
                float overlapRight = brickRight - ballLeft;
                float overlapTop = ballBottom - brickTop;
                float overlapBottom = brickBottom - ballTop;

               /* para ver por que eje la pelota entro menos en el ladrillo*/
                float minOverlapX = std::min(overlapLeft, overlapRight);
                float minOverlapY = std::min(overlapTop, overlapBottom);

                if (minOverlapX < minOverlapY)
                {
                    // rebote en X
                    ball.xVelocity *= -1;
                    if (overlapLeft < overlapRight)
                        ball.xPos -= minOverlapX;
                    else
                        ball.xPos += minOverlapX;
                }
                else
                {
                    // rebote en Y
                    ball.yVelocity *= -1;
                    if (overlapTop < overlapBottom)
                        ball.yPos -= minOverlapY;
                    else
                        ball.yPos += minOverlapY;
                }

                return; // salir para no romper mas de un ladrillo
            }
        }
    }
}
