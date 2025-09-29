#include "Game.h"
#include "Draw.h"
#include "Bricks.h"
#include "MainMenu.h"
#include "PauseScreen.h"
#include "Assets.h"
#include "GameState.h"
#include "PowerUps.h"

void InitGame()
{
	srand(time(NULL));

	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	LoadAllTextures();
	InitMainMenu();
	slClose();
}

void GameLoop()
{
	srand(time(NULL));

	Paddle paddle = CreatePaddle(640 / 2, 60, 65, 35, 800.0f);
	Brick brick[brickRow][brickCol];
	InitBricks(brick);

	const int maxScore = 10;

	bool pause = false;
	bool pWasPressed = false;
	bool exitGamePlay = false;

	GAMESTATE currentState = GAMESTATE::MAINMENU;
    while (!slShouldClose() && !exitGamePlay)
    {
        switch (currentState)
        {
        case GAMESTATE::MAINMENU:
        {
            
            MAINMENU option = InputMainMenu();
            if (option == MAINMENU::PLAY)
            {
     
                paddle = CreatePaddle(640 / 2, 60, 65, 35, 800.0f);
                InitBalls();
                InitBricks(brick);
                currentState = GAMESTATE::PLAYING;
            }
            else if (option == MAINMENU::EXIT)
            {
                exitGamePlay = true;
            }
            // Aquí podrías manejar otros estados como CREDITS si quieres
            break;
        }

        case GAMESTATE::PLAYING:
        {

            // Control pausa
            if (slGetKey('P'))
            {
                if (!pWasPressed)
                {
                    pause = !pause;
                    pWasPressed = true;
                }
            }
            else
            {
                pWasPressed = false;
            }

            if (!pause)
            {
                // Movimiento
                if (slGetKey(SL_KEY_RIGHT))
                    paddle = MoveRight(paddle);
                if (slGetKey(SL_KEY_LEFT))
                    paddle = MoveLeft(paddle);

                UpdateBalls(paddle, brick);
            }

            UpdatePowerUp();         // para que caigan
            UpdatePowerUpLogic(paddle);  // para aplicar si colisionan

            // Dibujar juego
            slSprite(backgroundGame, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
            DrawLives(paddle);
            DrawPaddle(paddle);
            DrawBalls();
            DrawPowerUps();
            DrawBricks(brick);
            DrawPause();

            if (!balls[0].isLaunched)
                slText(170, 360, "Press 'L' to launch ball");

            if (pause)
            {
                DrawPauseScreen();
                PAUSE option = InputPauseScreen();
                if (option == PAUSE::RESUME)
                    pause = false;
                else if (option == PAUSE::EXIT)
                    currentState = GAMESTATE::MAINMENU;
            }

            if (WinCondition(brick))
            {
                currentState = GAMESTATE::WINSCREEN;
            }

            if (paddle.lives <= 0)
            {
                currentState = GAMESTATE::MAINMENU; // o GAMEOVER si lo tienes
            }
            break;
        }

        case GAMESTATE::WINSCREEN:
        {
            slSprite(backgroundGame, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
            slText(screenWidth / 2 - 50, 600, "YOU WIN!");
            DrawWinScreen();

            WINOPTION option = InputWinScreen();
            if (option == WINOPTION::MAINMENU)
            {
                currentState = GAMESTATE::MAINMENU;
            }
            else if (option == WINOPTION::PLAYAGAIN)
            {
               
                paddle = CreatePaddle(640 / 2, 60, 65, 35, 800.0f);
                InitBalls();
                InitBricks(brick);
                currentState = GAMESTATE::PLAYING;
            }
            break;
        }
        }

        slRender();
    }
}

bool WinCondition(Brick brick[brickRow][brickCol])
{

	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickCol; j++)
		{
			if (brick[i][j].active)
			{
				return false; // Si encontramos uno activo, no ganó todavía
			}
		}
	}

	return true; // Si ninguno estaba activo, se ganó
}

WINOPTION InputWinScreen()
{
	static bool mouseWasPressed = false;

	int mouseX = slGetMouseX();
	int mouseY = slGetMouseY();

	float buttonWidth = 200;
	float buttonHeight = 80;
	float x = screenWidth / 2;

	float mainMenuY = 410;
	float playAgainY = 510;

	bool mousePressed = slGetMouseButton(SL_MOUSE_BUTTON_LEFT);

	WINOPTION selected = WINOPTION::NONE;

	if (mousePressed && !mouseWasPressed) // solo detecta el primer frame del click
	{
		if (IsInside(mouseX, mouseY, x, mainMenuY, buttonWidth, buttonHeight))
		{
			selected = WINOPTION::MAINMENU;
		}
		else if (IsInside(mouseX, mouseY, x, playAgainY, buttonWidth, buttonHeight))
		{
			selected = WINOPTION::PLAYAGAIN;
		}
	}

	mouseWasPressed = mousePressed;
	return selected;
}


