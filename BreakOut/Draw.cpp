#include "Draw.h"
#include "sl.h"
void DrawMainMenu()
{
    DrawButton(640 - 80, 350, 300, 50, "PVP", 5, 6);
    DrawButton(640 - 80, 390, 300, 50, "CPU", 5, 6);
    DrawButton(640, 460, 300, 50, "CREDITS", 5, 6);
    DrawButton(640 + 20, 490, 300, 50, "EXIT", 5, 6);
}

void DrawButton(float x, float y, float width, float height, const char* text, int buttonColor, int textColor)
{
    slSetForeColor(buttonColor, buttonColor, buttonColor, 1.0); // color del botón
    slRectangleFill(x, y, width, height);

    slSetForeColor(textColor, textColor, textColor, 1.0); // color del texto
  /*  slText(x - slGetTextWidth(text) / 2, y - slGetTextHeight(text) / 2, text);*/
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
