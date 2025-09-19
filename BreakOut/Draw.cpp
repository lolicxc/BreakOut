#include "Draw.h"
#include "sl.h"
void DrawMainMenu()
{
}

void DrawScore(Paddle& paddle)
{
}

void DrawBall(Ball ball)
{
	slCircleFill(ball.xPos, ball.yPos, ball.radius, 6);
}

void DrawPaddle(Paddle paddle)
{
	slRectangleFill(paddle.xPos, paddle.yPos, paddle.width, paddle.height);
}

void DrawWinner(Paddle& paddle1, Paddle& paddle2)
{
}

void DrawField()
{
}

void DrawCredits()
{


}

void DrawPause()
{

}
