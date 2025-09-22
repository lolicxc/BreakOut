#include "Draw.h"
#include "sl.h"
#include "MainMenu.h"
#include <string>

void DrawMainMenu()
{
    float screenWidth = 640; 
    float buttonWidth = 200;    
    float buttonHeight = 80;
    float x = screenWidth / 2; // centrado horizontal

    float mouseX = slGetMouseX();
    float mouseY = slGetMouseY();

    DrawButton(x, 400, buttonWidth, buttonHeight, "PLAY", IsInside(mouseX, mouseY, x, 400, buttonWidth, buttonHeight));
    DrawButton(x, 300, buttonWidth, buttonHeight, "CREDITS",IsInside(mouseX, mouseY, x, 300, buttonWidth, buttonHeight));
    DrawButton(x, 200, buttonWidth, buttonHeight, "EXIT",IsInside(mouseX, mouseY, x, 200, buttonWidth, buttonHeight));

}

void DrawButton(float x, float y, float width, float height, const char* text, bool hover)
{
    int button = slLoadTexture("../res/button.png");

    if (hover)
    {
        slSetForeColor(0.6f, 0.2f, 0.7f, 1.0f); 
    }
    else
    {
        slSetForeColor(0.44f, 0.0f, 0.39f, 1.0f); 
    }


    slSprite(button, x, y, width, height);
    slSetForeColor(1.0f, 1.0f, 1.0f, 1.0f);
    float textX = x - slGetTextWidth(text) / 2;
    float textY = y - slGetTextHeight(text) / 2;
    slText(textX, textY, text);
 

 
}
void DrawLives(Paddle& paddle)
{
    std::string liveText = "Lives: " + std::to_string(paddle.lives);
    slText(4.0, 10.0, liveText.c_str());
}

void DrawBall(Ball ball)
{
	slCircleFill(ball.xPos, ball.yPos, ball.radius, 12);
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

void DrawBricks(Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE], int brickTextures[3])
{
    
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {

            Brick& b = brick[i][j];

            if (!b.active) continue; // <-- ignora ladrillos "destruidos"

            float x = brick[i][j].xPos - brick[i][j].width / 2;
            float y = brick[i][j].yPos - brick[i][j].height / 2;

            slSprite(brickTextures[b.texture], x, y, b.width, b.height);
        }
    }

}
