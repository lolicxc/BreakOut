#include "Assets.h"

int brickTextures[3];

int backgroundGame;
int background;
int button;
int credits;

int paddleAsset;

int font;

int ballText;


void LoadAllTextures()
{

	brickTextures[0] = slLoadTexture("../res/brick1.png");
	brickTextures[1] = slLoadTexture("../res/brick2.png");
	brickTextures[2] = slLoadTexture("../res/brick3.png");

	backgroundGame = slLoadTexture("../res/Background1.png");
	ballText = slLoadTexture("../res/ball.png");
	paddleAsset = slLoadTexture("../res/paddle.png");
	background = slLoadTexture("../res/Background.PNG");
	button = slLoadTexture("../res/button.png");

	credits = slLoadTexture("../res/credits.png");
	font = slLoadFont("../res/LEGO.ttf");
}