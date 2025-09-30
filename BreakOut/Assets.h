#pragma once
#include "sl.h"
#include "ball.h"

#pragma once

extern int brickTextures[3];

extern int backgroundGame;
extern int background;
extern int button;
extern int credits;

extern int paddleAsset;

extern int font;

extern int ballText;

extern int powerUpAsset;
extern int powerUpAsset2;

extern int howToPlay;

extern int backgroundSound;
extern int bounceSound;
extern int bookSound;

void LoadAllTextures();
void LoadAllAudio();