#include "Game.h"
#include "Draw.h"

void GameLoop()
{

	bool pause = false;

	Paddle paddle = CreatePaddle(640 / 2, 60, 150, 10, 800.0f);
	Ball ball = CreateBall(640 / 2, 100, 5.0f, 5.0f, 15, 300.0f);
	Launch(ball);

	const int maxScore = 10;

	//gameloop
	while (!slShouldClose())
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

			Update(ball, paddle);
		}

		DrawPaddle(paddle);
		DrawBall(ball);
		slRender();
	}
}
