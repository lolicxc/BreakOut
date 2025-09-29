#include "MainMenu.h"
#include "Draw.h"
#include "Game.h"
#include "Assets.h"

void InitMainMenu()
{

	slSetFont(font, 34);
	bool exitGame = false;

	while (!slShouldClose() && !exitGame)
	{
		slSprite(background, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
		DrawMainMenu();

		MAINMENU option = InputMainMenu();

		switch (option)
		{

		case MAINMENU::PLAY:
			GameLoop();
			break;
		case MAINMENU::CREDITS:
			Credits();
			break;
		case MAINMENU::EXIT:
			exitGame = true;
			break;
		default:
			break;
		}

		slRender();
	}
}

MAINMENU InputMainMenu()
{
    
    int mouseX = slGetMouseX();
    int mouseY = slGetMouseY();

    float screenWidth = 640;
    float buttonWidth = 200;
    float buttonHeight = 50;
    float x = screenWidth / 2; // centro en X

    float playY = 400;
    float creditsY = 300;
    float exitY = 200;

    // detectar click
    if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
    {
        if (IsInside(mouseX, mouseY, x, playY, buttonWidth, buttonHeight))
            return MAINMENU::PLAY;

        if (IsInside(mouseX, mouseY, x, creditsY, buttonWidth, buttonHeight))
            return MAINMENU::CREDITS;

        if (IsInside(mouseX, mouseY, x, exitY, buttonWidth, buttonHeight))
            return MAINMENU::EXIT;
    }

    return MAINMENU::NONE;
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