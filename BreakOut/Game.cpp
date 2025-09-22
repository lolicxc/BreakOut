#include "Game.h"
#include "Draw.h"
#include "Bricks.h"



void GameLoop()
{
	srand(time(NULL));
	bool pause = false;

	Paddle paddle = CreatePaddle(640 / 2, 60, 150, 10, 800.0f);
	Ball ball = CreateBall(640 / 2, 100, 5.0f, 5.0f, 15, 300.0f);

	int brickTextures[3];
	brickTextures[0] = slLoadTexture("../res/rune1.png");
	brickTextures[1] = slLoadTexture("../res/rune2.png");
	brickTextures[2] = slLoadTexture("../res/rune3.png");

	Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE];
	InitBricks(brick);

	Launch(ball);

	const int maxScore = 10;

	//gameloop
	while (!slShouldClose() && paddle.lives > 0)
	{

		if (slGetKey('P')) pause = !pause;
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

		DrawLives(paddle);
		DrawPaddle(paddle);
		DrawBall(ball);
		DrawBricks(brick, brickTextures);
		slRender();
	}
}

