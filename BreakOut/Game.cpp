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
    LoadAllAudio();
    GameLoop();  
	slClose();
}

void GameLoop()
{
	srand(time(NULL));

	Paddle paddle = CreatePaddle(640 / 2, 60, 95, 55, 800.0f);
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
            
            InitMainMenu(currentState, exitGamePlay, paddle, brick);
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

            // Draw
            slSprite(backgroundGame, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
            DrawLives(paddle);
            DrawPaddle(paddle);
            DrawBalls();
            DrawPowerUps();
            DrawBricks(brick);
            DrawPause();

            bool anyBallAlive = false;
            for (int i = 0; i < ballCount; i++)
            {
                if (balls[i].isLaunched)  
                {
                    anyBallAlive = true;
                    break;
                }
            }

            if (!anyBallAlive) 
            {
                slText(180, 270, "Press 'L' to launch ball");
            }

            if (pause)
            {
                DrawPauseScreen();
                PAUSE option = InputPauseScreen();
                if (option == PAUSE::RESUME)
                {
                    pause = false;
                }
                else if (option == PAUSE::EXIT)
                {
                    currentState = GAMESTATE::MAINMENU;
                }
            }

            if (WinCondition(brick))
            {
                currentState = GAMESTATE::WINSCREEN;
            }

            if (paddle.lives <= 0)
            {
                currentState = GAMESTATE::GAMEOVERSCREEN; // o GAMEOVER si lo tienes
            }
            break;
        }

        case GAMESTATE::WINSCREEN:
        {
            slSprite(backgroundGame, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
            slText(screenWidth / 2 - 50, 600, "YOU WIN!");
            DrawWinScreen();

            WINLOSEOPTION option = InputWinScreen();
            if (option == WINLOSEOPTION::MAINMENU)
            {
                currentState = GAMESTATE::MAINMENU;
            }
            else if (option == WINLOSEOPTION::PLAYAGAIN)
            {
               
                paddle = CreatePaddle(640 / 2, 60, 65, 35, 800.0f);
                InitBalls();
                InitBricks(brick);
                currentState = GAMESTATE::PLAYING;
            }
            break;
        }
        case GAMESTATE::GAMEOVERSCREEN:

            slSprite(backgroundGame, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
            slText(screenWidth / 2 - 50, 600, "YOU LOSE!");
            DrawWinScreen();

            WINLOSEOPTION option = InputWinScreen();
            if (option == WINLOSEOPTION::MAINMENU)
            {
                currentState = GAMESTATE::MAINMENU;
            }
            else if (option == WINLOSEOPTION::PLAYAGAIN)
            {

                paddle = CreatePaddle(640 / 2, 60, 65, 35, 800.0f);
                InitBalls();
                InitBricks(brick);
                currentState = GAMESTATE::PLAYING;
            }
            break;
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
				return false; 
			}
		}
	}

	return true; 
}

WINLOSEOPTION InputWinScreen()
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

	WINLOSEOPTION selected = WINLOSEOPTION::NONE;

	if (mousePressed && !mouseWasPressed) // solo detecta el primer frame del click
	{
		if (IsInside(mouseX, mouseY, x, mainMenuY, buttonWidth, buttonHeight))
		{
			selected = WINLOSEOPTION::MAINMENU;
		}
		else if (IsInside(mouseX, mouseY, x, playAgainY, buttonWidth, buttonHeight))
		{
			selected = WINLOSEOPTION::PLAYAGAIN;
		}
	}

	mouseWasPressed = mousePressed;
	return selected;
}


