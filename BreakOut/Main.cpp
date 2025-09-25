#include "sl.h"
#include "MainMenu.h"
#include "Game.h"
#include "Draw.h"
#include <ctime>
int main()
{
    srand(time(NULL));


    //fondo

    slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);

    int background = slLoadTexture("../res/Background.PNG");

    int font = slLoadFont("../res/LEGO.ttf");
    slSetFont(font, 34);   

    bool exitGame = false;

    while (!slShouldClose()&& !exitGame)
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

    slClose();
    return 0;
}
	