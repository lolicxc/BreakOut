#pragma once

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

const int brickRow = 1;
const int  brickCol = 1;

void InitBricks(Brick brick[brickRow][brickCol]);
void BricksCollision(Ball& ball, Brick brick[brickRow][brickCol]);