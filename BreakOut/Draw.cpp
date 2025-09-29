#include "Draw.h"
#include "sl.h"
#include "MainMenu.h"
#include <string>
#include "Assets.h"


void DrawMainMenu()
{
	float buttonWidth = 200;
	float buttonHeight = 80;
	float x = screenWidth / 2; // centrado horizontal

	float mouseX = slGetMouseX();
	float mouseY = slGetMouseY();

	DrawButton(x, 400, buttonWidth, buttonHeight, "PLAY", IsInside(mouseX, mouseY, x, 400, buttonWidth, buttonHeight));
	DrawButton(x, 300, buttonWidth, buttonHeight, "Credits", IsInside(mouseX, mouseY, x, 300, buttonWidth, buttonHeight));
	DrawButton(x, 200, buttonWidth, buttonHeight, "Exit", IsInside(mouseX, mouseY, x, 200, buttonWidth, buttonHeight));

}

void DrawButton(float x, float y, float width, float height, const char* text, bool hover)
{

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
	slText(45, screenHeight - 55, liveText.c_str());
	slSetForeColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawBall(Ball& ball)
{

	slSprite(ballText, ball.xPos, ball.yPos, ball.radius * 2, ball.radius * 2);
	ball.hitBrick = false;
}

void DrawPaddle(Paddle paddle)
{
	/*slRectangleFill(paddle.xPos, paddle.yPos, paddle.width, paddle.height);*/
	slSprite(paddleAsset, paddle.xPos, paddle.yPos, paddle.width, paddle.height);
}

void DrawWinner(Paddle& paddle1, Paddle& paddle2)
{
}


void DrawCredits()
{

	slSprite(credits, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
	slText(120, 180, "(Press 'Z' to back main menu)");
}

void DrawPause()
{
	slSetFontSize(25);
	slSetForeColor(1.0f, 0.0f, 0.0f, 1.0f);
	slText(460, screenHeight - 55, "'P' to pause");
	slSetForeColor(1.0f, 1.0f, 1.0f, 1.0f);
	slSetFontSize(30);
}

void DrawBricks(Brick brick[brickRow][brickCol])
{

	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickCol; j++)
		{

			Brick& b = brick[i][j];

			if (!b.active) continue;

			slSprite(brickTextures[b.texture], b.xPos, b.yPos, b.width, b.height);
		}
	}

}

void DrawPauseScreen()
{
	float buttonWidth = 200;
	float buttonHeight = 80;
	float x = screenWidth / 2; // centrado horizontal

	float mouseX = slGetMouseX();
	float mouseY = slGetMouseY();

	DrawButton(x, 400, buttonWidth, buttonHeight, "Resume", IsInside(mouseX, mouseY, x, 400, buttonWidth, buttonHeight));
	DrawButton(x, 300, buttonWidth, buttonHeight, "How to play", IsInside(mouseX, mouseY, x, 300, buttonWidth, buttonHeight));
	DrawButton(x, 200, buttonWidth, buttonHeight, "Exit", IsInside(mouseX, mouseY, x, 200, buttonWidth, buttonHeight));

}

void DrawWinScreen()
{
	float buttonWidth = 200;
	float buttonHeight = 80;
	float x = screenWidth / 2; // centrado horizontal

	float mouseX = slGetMouseX();
	float mouseY = slGetMouseY();

	DrawButton(x, 410, buttonWidth, buttonHeight, "Main menu", IsInside(mouseX, mouseY, x, 410, buttonWidth, buttonHeight));
	DrawButton(x, 510, buttonWidth, buttonHeight, "Play again", IsInside(mouseX, mouseY, x, 510, buttonWidth, buttonHeight));
}

void DrawPowerUps()
{
	for (int i = 0; i < maxPowerUps; i++)
	{
		if (!powerUps[i].active)
			continue; 

		switch (powerUps[i].type)
		{
		case POWERUPTYPE::MAXPADDLE:
			slRectangleFill(powerUps[i].xPos, powerUps[i].yPos, 20, 20);
			break;
		case POWERUPTYPE::SHOOTPADDLE:
			slRectangleFill(powerUps[i].xPos, powerUps[i].yPos, 20, 20);
			break;
		case POWERUPTYPE::THREEBALLS:
			slRectangleFill(powerUps[i].xPos, powerUps[i].yPos, 20, 20);
			break;
		case POWERUPTYPE::LAUNCH:
			slRectangleFill(powerUps[i].xPos, powerUps[i].yPos, 20, 20);
			break;
		default:
			slRectangleFill(powerUps[i].xPos, powerUps[i].yPos, 20, 20);
			break;
	
		}

	}
}

