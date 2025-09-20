#include "MainMenu.h"
#include "Draw.h"


MAINMENU InputMainMenu()
{

    // Obtener posición del mouse
    int mouseX = slGetMouseX();
    int mouseY = slGetMouseY();

    int fontSize = 40;
    float screenWidth = 640 / 2.2f;

    // Definimos rectángulos (x, y, ancho, alto)
    int pvpX = screenWidth - 80, pvpY = 350, pvpW = 300, pvpH = 50;
    int cpuX = screenWidth - 80, cpuY = 390, cpuW = 300, cpuH = 50;
    int creditsX = screenWidth, creditsY = 460, creditsW = 300, creditsH = 50;
    int exitX = screenWidth + 20, exitY = 490, exitW = 300, exitH = 50;

    DrawMainMenu();

    // Detectar click
    if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
    {
        // PVP
        if (mouseX >= pvpX && mouseX <= pvpX + pvpW &&
            mouseY >= pvpY && mouseY <= pvpY + pvpH)
            return MAINMENU::PLAY;

        // Credits
        if (mouseX >= creditsX && mouseX <= creditsX + creditsW &&
            mouseY >= creditsY && mouseY <= creditsY + creditsH)
            return MAINMENU::CREDITS;

        // Exit
        if (mouseX >= exitX && mouseX <= exitX + exitW &&
            mouseY >= exitY && mouseY <= exitY + exitH)
            return MAINMENU::EXIT;
    }

    return MAINMENU::NONE;
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

		slRender();
		DrawCredits();

	}

}