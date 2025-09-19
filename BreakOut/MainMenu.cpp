#include "MainMenu.h"
#include "Draw.h"



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