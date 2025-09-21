#pragma once

#include "Ball.h"
#include "Bricks.h"


void DrawMainMenu();
void DrawButton(float x, float y, float width, float height, const char* text, bool hover);
void DrawLives(Paddle& paddle);
void DrawBall(Ball ball);
void DrawPaddle(Paddle paddle);
void DrawWinner(Paddle& paddle1, Paddle& paddle2);
void DrawField();
void DrawCredits();
void DrawPause();
void DrawBricks(Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE]);