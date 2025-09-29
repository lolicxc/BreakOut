#pragma once
#include "sl.h"
#include "Ball.h"
#include "Paddle.h"

enum class WINOPTION
{
	NONE,
	MAINMENU,
	PLAYAGAIN
};

void InitGame();
void GameLoop();
bool WinCondition(Brick brick[brickRow][brickCol]);
WINOPTION InputWinScreen();


