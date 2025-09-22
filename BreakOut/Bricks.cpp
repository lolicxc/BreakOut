#pragma once
#include "Bricks.h"
#include "Ball.h"

void InitBricks(Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE])
{
    int initialDownPosition = 600; 
    int spacingX = 5; 
    int spacingY = 5; 

    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            brick[i][j].width = 50;
            brick[i][j].height = 25;

 
            brick[i][j].xPos = j * (brick[i][j].width + spacingX) + brick[i][j].width / 2 + 50; 
            brick[i][j].yPos = initialDownPosition - i * (brick[i][j].height + spacingY) - brick[i][j].height / 2;

            brick[i][j].active = true;

            brick[i][j].texture = rand() % 3; 
        }
    }
}

void BricksCollision(Ball& ball, Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE])
{
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            Brick& b = brick[i][j];

            if (!b.active) continue; //pasa de largo los ya destruidos

       
            if (ball.xPos + ball.radius >= b.xPos - b.width / 2 &&
                ball.xPos - ball.radius <= b.xPos + b.width / 2 &&
                ball.yPos + ball.radius >= b.yPos - b.height / 2 &&
                ball.yPos - ball.radius <= b.yPos + b.height / 2)
            {
                b.active = false;

        
                float overlapX = (b.width / 2 + ball.radius) - fabs(ball.xPos - b.xPos);
                float overlapY = (b.height / 2 + ball.radius) - fabs(ball.yPos - b.yPos);

                if (overlapX < overlapY)
                    ball.xVelocity *= -1; 
                else
                    ball.yVelocity *= -1; 
            }
        }
    }

}
