#include "MainMenu.h"
#include "Draw.h"
#include "Game.h"
#include "Assets.h"

void InitMainMenu(GAMESTATE& currentState, bool& exitGamePlay, Paddle& paddle, Brick bricks[brickRow][brickCol])
{

	slSetFont(font, 34);
	slSprite(background, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
	DrawMainMenu();

	MAINMENU option = InputMainMenu();

	switch (option)
	{
	case MAINMENU::PLAY:
		paddle = CreatePaddle(640 / 2, 60, 95, 55, 800.0f);
		InitBricks(bricks);
		InitBalls();
		currentState = GAMESTATE::PLAYING;
		break;
	case MAINMENU::HOWTO:
		HowToPlayScreen();
		break;
	case MAINMENU::CREDITS:
		Credits();
		break;
	case MAINMENU::EXIT:
		exitGamePlay = true;
		break;
	default:
		break;
	}

	


}

MAINMENU InputMainMenu()
{

	static bool mouseWasPressed = false; // esto asegura detectar solo clicks nuevos

	int mouseX = slGetMouseX();
	int mouseY = slGetMouseY();

	float screenWidth = 640;
	float buttonWidth = 200;
	float buttonHeight = 50;
	float x = screenWidth / 2;

	float playY = 400;
	float howToY = 320;
	float creditsY = 240;
	float exitY = 160;

	bool mousePressed = slGetMouseButton(SL_MOUSE_BUTTON_LEFT);

	MAINMENU selected = MAINMENU::NONE;

	if (mousePressed && !mouseWasPressed) // solo detecta el primer frame del click
	{
		if (IsInside(mouseX, mouseY, x, playY, buttonWidth, buttonHeight))
			selected = MAINMENU::PLAY;
		else if (IsInside(mouseX, mouseY, x, howToY, buttonWidth, buttonHeight))
			selected = MAINMENU::HOWTO;
		else if (IsInside(mouseX, mouseY, x, creditsY, buttonWidth, buttonHeight))
			selected = MAINMENU::CREDITS;
		else if (IsInside(mouseX, mouseY, x, exitY, buttonWidth, buttonHeight))
			selected = MAINMENU::EXIT;
	}

	mouseWasPressed = mousePressed;
	return selected;
}

bool IsInside(float mouseX, float mouseY, float x, float y, float w, float h)
{
	return (mouseX >= x - w / 2 && mouseX <= x + w / 2 &&
		mouseY >= y - h / 2 && mouseY <= y + h / 2);

}

void Credits()
{
	bool exitCredits = false;

	while (!slShouldClose() && !exitCredits)
	{
		if (slGetKey('Z'))
		{
			exitCredits = true;
		}

		DrawCredits();
		slRender();
	}

}

void HowToPlayScreen()
{
	bool exitHowToPlay = false;

	while (!slShouldClose() && !exitHowToPlay)
	{
		if (slGetKey('Z'))
		{
			exitHowToPlay = true;
		}

		DrawHowToPlay();
		slRender();
	}

}
