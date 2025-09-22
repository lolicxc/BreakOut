#include "MainMenu.h"
#include "Draw.h"


MAINMENU InputMainMenu()
{
    // Obtener posición del mouse
    int mouseX = slGetMouseX();
    int mouseY = slGetMouseY();

    float screenWidth = 640;
    float buttonWidth = 200;
    float buttonHeight = 50;
    float x = screenWidth / 2; // centro en X

    // Coordenadas centradas en Y
    float playY = 570;
    float creditsY = 460;
    float exitY = 350;

    // Detectar click
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