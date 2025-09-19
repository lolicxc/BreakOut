#include "sl.h"
//#include "MainMenu.h"
#include "Game.h"
#include "Draw.h"
#include <ctime>
int main()
{
    srand(time(NULL));

    const int screenWidth = 640;
    const int screenHeight = 720;


    slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);


    bool exitGame = false;

    while (!slShouldClose()&& !exitGame)
    {
        GameLoop();
        //switch (option)
        //{
        ////case MAINMENU::PLAYERVSCPU:
        ////    GameLoop(GameMode::CPU);
        ////    break;
        ////case MAINMENU::PLAYERVSPLAYER:
        ////    GameLoop(GameMode::Player);
        ////    break;
        ////case MAINMENU::CREDITS:
        ////    Credits();
        ////    break;
        ////case MAINMENU::EXIT:
        ////    exitGame = true;
        //    break;
        //default:
        //    break;
        //}

        slRender();
    }

    slClose();
    return 0;
}
	