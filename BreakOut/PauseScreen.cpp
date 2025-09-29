#include "PauseScreen.h"
#include "sl.h"
#include "MainMenu.h"
#include "Draw.h"

PAUSE InputPauseScreen()
{
    static bool mouseWasPressed = false;

    int mouseX = slGetMouseX();
    int mouseY = slGetMouseY();

    float buttonWidth = 200;
    float buttonHeight = 80;
    float x = screenWidth / 2;

    float resumeY = 400;
    float exitY = 200;

    bool mousePressed = slGetMouseButton(SL_MOUSE_BUTTON_LEFT);

    PAUSE selected = PAUSE::NONE;

    if (mousePressed && !mouseWasPressed) // solo detecta el primer frame del click
    {
        if (IsInside(mouseX, mouseY, x, resumeY, buttonWidth, buttonHeight))
        {
            selected = PAUSE::RESUME;
        }
        else if (IsInside(mouseX, mouseY, x, exitY, buttonWidth, buttonHeight))
        {
            selected = PAUSE::EXIT;
        }
    }

    mouseWasPressed = mousePressed;
    return selected;
}
