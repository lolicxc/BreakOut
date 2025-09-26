#pragma once
#include "sl.h"

enum class MAINMENU
{
	NONE,
	PLAY,
	CREDITS,
	EXIT

};

void InitMainMenu();
MAINMENU InputMainMenu();
bool IsInside(float mouseX, float mouseY, float x, float y, float w, float h);
void Credits();


