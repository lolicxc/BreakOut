#pragma once

#include "Ball.h"
#include "Bricks.h"
#include "PowerUps.h"

const int screenWidth = 640;
const int screenHeight = 720;


void DrawMainMenu();
void DrawButton(float x, float y, float width, float height, const char* text, bool hover);
void DrawLives(Paddle& paddle);
void DrawBall(Ball& ball);
void DrawPaddle(Paddle paddle);
void DrawWinner(Paddle& paddle1, Paddle& paddle2);
void DrawCredits();
void DrawPause();
void DrawBricks(Brick brick[brickRow][brickCol]);
void DrawPauseScreen();
void DrawWinScreen();
void DrawPowerUps();
void DrawHowToPlay();