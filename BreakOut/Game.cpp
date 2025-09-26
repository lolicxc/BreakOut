#include "Game.h"
#include "Draw.h"
#include "Bricks.h"



void GameLoop()
{
	srand(time(NULL));

	Paddle paddle = CreatePaddle(640 / 2, 60, 75, 35, 800.0f);
	Ball ball = CreateBall(640 / 2, 100, 5.0f, 5.0f, 15, 300.0f);
	ball.isLaunched = false;

	int brickTextures[3];
	brickTextures[0] = slLoadTexture("../res/rune1.png");
	brickTextures[1] = slLoadTexture("../res/rune2.png");
	brickTextures[2] = slLoadTexture("../res/rune3.png");

	int backgroundGame = slLoadTexture("../res/Background1.png");
	ball.normalBallS = slLoadTexture("../res/ball.png");
	ball.hitBallS = slLoadTexture("../res/ball2.png");
	int paddleAsset = slLoadTexture("../res/paddle.png");

	Brick brick[brickRow][brickCol];
	InitBricks(brick);

	const int maxScore = 10;

	bool pause = false;
	bool pWasPressed = false;

	//gameloop
	while (!slShouldClose() && paddle.lives > 0)
	{

		// dentro del loop
		if (slGetKey('P')) {
			if (!pWasPressed) {   // solo entra cuando recién se presiona
				pause = !pause;
				pWasPressed = true;
			}
		}
		else {
			pWasPressed = false;  // se suelta la tecla, listo para la próxima
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

