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

const int LINES_OF_BRICKS = 5;
const int  BRICKS_PER_LINE = 11;

void InitBricks(Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE]);
void BricksCollision(Ball& ball, Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE]);