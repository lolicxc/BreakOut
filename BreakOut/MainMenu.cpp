#include "MainMenu.h"
#include "Draw.h"

MAINMENU InputMainMenu()
{
    int mouseXPos = slGetMouseX();
    int mouseYPos ? slGetMouseY();
    int fontSize = 40;
    float screenWidth = GetScreenWidth() / 2.2;
    // Definimos los rectángulos de cada opción (x, y, ancho, alto)
    Rectangle pvpRect = { screenWidth - 80, 350 , 300, 50 };
    Rectangle cpuRect = { screenWidth - 80, 390, 300, 50 };
    Rectangle creditsRect = { screenWidth, 460, 300, 50 };
    Rectangle exitRect = { screenWidth + 20 , 490, 300, 50 };


    DrawMainMenu();

    // Detección de click
    if (SL_MOUSE_BUTTON_LEFT)
    {
        if (CheckCollisionPointRec(mouse, pvpRect))
            return MAINMENU::PLAYERVSPLAYER;
        if (CheckCollisionPointRec(mouse, cpuRect))
            return MAINMENU::PLAYERVSCPU;
        if (CheckCollisionPointRec(mouse, creditsRect))
            return MAINMENU::CREDITS;
        if (CheckCollisionPointRec(mouse, exitRect))
            return MAINMENU::EXIT;
    }

    return MAINMENU::NONE;
}


void Credits()
{
    bool exitCredits = false;

    while (!slShouldClose() && !exitCredits)
    {
        if (IsKeyPressed(KEY_Z))
        {
            exitCredits = true;
        }

        slRender();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCredits();
        EndDrawing();
    }

}