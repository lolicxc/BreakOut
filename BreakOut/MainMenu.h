#pragma once
#include "sl.h"
#include "GameState.h"
#include "Paddle.h"
#include "Bricks.h"

enum class MAINMENU
{
	NONE,
	PLAY,
	HOWTO,
	CREDITS,
	EXIT

};

void InitMainMenu(GAMESTATE& currentState, bool& exitGamePlay, Paddle& paddle, Brick bricks[brickRow][brickCol]);
MAINMENU InputMainMenu();
bool IsInside(float mouseX, float mouseY, float x, float y, float w, float h);
void Credits();
void HowToPlayScreen();


