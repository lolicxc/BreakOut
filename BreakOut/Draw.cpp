#include "Draw.h"
#include "sl.h"
#include "MainMenu.h"
#include <string>

void DrawMainMenu()
{
    float buttonWidth = 200;
    float buttonHeight = 80;
    float x = screenWidth / 2; // centrado horizontal

    float mouseX = slGetMouseX();
    float mouseY = slGetMouseY();

    DrawButton(x, 400, buttonWidth, buttonHeight, "PLAY", IsInside(mouseX, mouseY, x, 400, buttonWidth, buttonHeight));
    DrawButton(x, 300, buttonWidth, buttonHeight, "Credits",IsInside(mouseX, mouseY, x, 300, buttonWidth, buttonHeight));
    DrawButton(x, 200, buttonWidth, buttonHeight, "Exit",IsInside(mouseX, mouseY, x, 200, buttonWidth, buttonHeight));

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
        slSetForeColor(1.0f, 1.0f, 1.0f, 1.0f);
    }


    slSprite(button, x, y, width, height);
    slSetForeColor(1.0f, 1.0f, 1.0f, 1.0f);
    float textX = x - slGetTextWidth(text) / 2;
    float textY = y - slGetTextHeight(text) / 2;
    slText(textX, textY, text);
 
}

void DrawLives(Paddle& paddle)
{
    slSetForeColor(1.0f, 0.0f, 0.0f, 1.0f);
    std::string liveText = "Lives: " + std::to_string(paddle.lives);
    slText(45.0, screenHeight - 55, liveText.c_str());
    slSetForeColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawBall(Ball& ball)
{

    int spriteToDraw = ball.hitBrick ? ball.hitBallS : ball.normalBallS;
    slSprite(spriteToDraw, ball.xPos, ball.yPos, ball.radius * 2, ball.radius * 2);

    // opcional: resetear para que solo dure 1 frame

    ///*slCircleFill(ball.xPos, ball.yPos, ball.radius, 12);*/
    //slSprite(ballAsset, ball.xPos, ball.yPos, ball.radius * 2, ball.radius * 2);
    ball.hitBrick = false;
}

void DrawPaddle(Paddle paddle, int paddleAsset)
{
	/*slRectangleFill(paddle.xPos, paddle.yPos, paddle.width, paddle.height);*/
    slSprite(paddleAsset, paddle.xPos, paddle.yPos, paddle.width, paddle.height);
}

void DrawWinner(Paddle& paddle1, Paddle& paddle2)
{
}

void DrawField()
{
}

void DrawCredits()
{
    int credits = slLoadTexture("../res/credits.png");
    slSprite(credits, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
}

void DrawPause()
{

}

void DrawBricks(Brick brick[brickRow][brickCol], int brickTextures[3])
{
    
    for (int i = 0; i < brickRow; i++)
    {
        for (int j = 0; j < brickCol; j++)
        {

            Brick& b = brick[i][j];

            if (!b.active) continue; 

            float x = brick[i][j].xPos - brick[i][j].width / 2;
            float y = brick[i][j].yPos - brick[i][j].height / 2;

            slSprite(brickTextures[b.texture], x, y, b.width, b.height);
        }
    }

}
