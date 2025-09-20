#pragma once

#include "Ball.h"



void DrawMainMenu();
void DrawButton(float x, float y, float width, float height, const char* text, int buttonColor, int textColor);
void DrawScore(Paddle& paddle);
void DrawBall(Ball ball);
void DrawPaddle(Paddle paddle);
void DrawWinner(Paddle& paddle1, Paddle& paddle2);
void DrawField();
void DrawCredits();
void DrawPause();
