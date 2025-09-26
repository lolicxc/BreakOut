#pragma once

#include "Ball.h"
#include "Bricks.h"


const int screenWidth = 640;
const int screenHeight = 720;


void DrawMainMenu();
void DrawButton(float x, float y, float width, float height, const char* text, bool hover);
void DrawLives(Paddle& paddle);
void DrawBall(Ball& ball);
void DrawPaddle(Paddle paddle, int paddleAsset);
void DrawWinner(Paddle& paddle1, Paddle& paddle2);
void DrawField();
void DrawCredits();
void DrawPause();
void DrawBricks(Brick brick[brickRow][brickCol], int brickTextures[3]);