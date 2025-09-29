#include "Game.h"
#include "Draw.h"
#include "Bricks.h"
#include "MainMenu.h"
#include "PauseScreen.h"
#include "Assets.h"
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
	Ball ball = CreateBall(640 / 2, 100, 5.0f, 5.0f, 12, 300.0f);
	ball.isLaunched = false;

	Brick brick[brickRow][brickCol];
	InitBricks(brick);

	const int maxScore = 10;

	bool pause = false;
	bool pWasPressed = false;
	bool exitGamePlay = false;
	//gameloop
	while (!slShouldClose() && !exitGamePlay && paddle.lives > 0)
	{

		// dentro del loop
		if (slGetKey('P'))
		{
			if (!pWasPressed)
			{   // solo entra cuando recien se presiona
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
			if (slGetKey(SL_KEY_RIGHT))
			{
				paddle = MoveRight(paddle);
			}
			if (slGetKey(SL_KEY_LEFT))
			{
				paddle = MoveLeft(paddle);
			}

			Update(ball, paddle, brick);
		}
		slSprite(backgroundGame, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
		DrawPause();
		DrawLives(paddle);
		DrawPaddle(paddle);
		DrawBall(ball);
		DrawBricks(brick);
		if (!ball.isLaunched)
		{
			slText(170, 360, "Press 'L' to launch ball");
		}
		if (pause)
		{

			DrawPauseScreen();
			// Input solo cuando el juego esta en pausa
			PAUSE option = InputPauseScreen();
			switch (option)
			{
			case PAUSE::RESUME:
				pause = false;
				break;
			case PAUSE::EXIT:
				exitGamePlay = true; // Volver al menu
				break;
			default:
				break;
			}
		}
		//if (WinCondition(brick))
		//{

		//	bool winScreen = true;
		//	while (winScreen && !slShouldClose())
		//	{
		//		slSprite(backgroundGame, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
		//		slSetTextAlign(SL_ALIGN_CENTER);
		//		slText(screenWidth / 2, 600, "YOU WIN!");
		//		DrawWinScreen();

		//		WINOPTION option = InputWinScreen();
		//		switch (option)
		//		{
		//		case WINOPTION::MAINMENU:
		//			exitGamePlay = true;
		//			winScreen = false;
		//			break;
		//		case WINOPTION::PLAYAGAIN:
		//			winScreen = false;
		//			// Resetear el juego completo: reiniciar paddle, ball y bricks
		//			paddle = CreatePaddle(640 / 2, 60, 65, 35, 800.0f);
		//			ball = CreateBall(640 / 2, 100, 5.0f, 5.0f, 12, 300.0f);
		//			ball.isLaunched = false;
		//			InitBricks(brick);
		//			break;
		//		default:
		//			break;
		//		}


		//	}
			slRender();

		/*}*/
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
	float buttonWidth = 200;
	float buttonHeight = 80;
	float x = screenWidth / 2;

	float mouseX = slGetMouseX();
	float mouseY = slGetMouseY();

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
	{
		if (IsInside(mouseX, mouseY, x, 410, buttonWidth, buttonHeight))
			return WINOPTION::MAINMENU;

		if (IsInside(mouseX, mouseY, x, 510, buttonWidth, buttonHeight))
			return WINOPTION::PLAYAGAIN;
	}

	return WINOPTION::NONE;

}

