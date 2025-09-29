#pragma once

#include "PowerUps.h"
struct Ball;

struct Brick
{
    float xPos;
    float yPos;
    float width;   
    float height;
    bool active;
    int texture;


};

const int brickRow = 6;
const int  brickCol = 9;

void InitBricks(Brick brick[brickRow][brickCol]);
void BricksCollision(Ball& ball, Brick brick[brickRow][brickCol]);