#include "sl.h"
//#include "MainMenu.h"
//#include "GameLoop.h"
#include "Draw.h"
#include <ctime>
int main()
{
    srand(time(NULL));

    const int screenWidth = 1280;
    const int screenHeight = 720;


    slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);


    bool exitGame = false;

    while (!slShouldClose()&& !exitGame)
    {

        switch (option)
        {
        //case MAINMENU::PLAYERVSCPU:
        //    GameLoop(GameMode::CPU);
        //    break;
        //case MAINMENU::PLAYERVSPLAYER:
        //    GameLoop(GameMode::Player);
        //    break;
        //case MAINMENU::CREDITS:
        //    Credits();
        //    break;
        //case MAINMENU::EXIT:
        //    exitGame = true;
            break;
        default:
            break;
        }

        slRender();
    }

    slClose();
    return 0;
}
	//const int width = 400;
	//const int height = 400;

	//slWindow(width, height, "Simple SIGIL Example", false);

	//while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	//{
	//	slSetBackColor(0.5, 0.75, 1.0);

	//	slSetForeColor(1, 0, 0, 1);
	//	slRectangleFill(width * 0.5, height * 0.5, 100, 100);

	//	slRender();
	//}

	//slClose();

	//return 0;