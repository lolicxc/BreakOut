#include "MainMenu.h"
#include "Draw.h"

MAINMENU InputMainMenu()
{
    int mouseXPos = slGetMouseX();
    int mouseYPos = slGetMouseY();
    int fontSize = 40;

    DrawMainMenu();
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