#include "Game.h"
#include "Draw.h"
#include "Bricks.h"
#include "MainMenu.h"


void InitGame()
{
	srand(time(NULL));

	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	InitMainMenu();
	slClose();
}

void GameLoop()
{
	srand(time(NULL));

	Paddle paddle = CreatePaddle(640 / 2, 60, 65, 35, 800.0f);
	Ball ball = CreateBall(640 / 2, 100, 5.0f, 5.0f, 12, 300.0f);
	ball.isLaunched = false;

	int brickTextures[3];
	brickTextures[0] = slLoadTexture("../res/brick1.png");
	brickTextures[1] = slLoadTexture("../res/brick2.png");
	brickTextures[2] = slLoadTexture("../res/brick3.png");

	int backgroundGame = slLoadTexture("../res/Background1.png");
	ball.normalBallS = slLoadTexture("../res/ball.png");
	ball.hitBallS = slLoadTexture("../res/ball2.png");
	int paddleAsset = slLoadTexture("../res/paddle.png");

	Brick brick[brickRow][brickCol];
	InitBricks(brick);

	const int maxScore = 10;

	bool pause = false;
	bool pWasPressed = false;
	bool exitGamePlay = false;
	//gameloop
	while (!slShouldClose() && !exitGamePlay)
	{
			
		// dentro del loop
		if (slGetKey('P')) 
		{
			if (!pWasPressed)
			{   // solo entra cuando recien se presiona
				pause = !pause;
				pWasPressed = true;
			}
			if (slGetKey('Z'))
			{
				exitGamePlay = true;
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
		DrawPaddle(paddle, paddleAsset);
		DrawBall(ball);
		DrawBricks(brick, brickTextures);
		if (!ball.isLaunched)
		{
			slText(170, 360, "Press 'L' to launch ball");
		}
		slRender();

	}
}

