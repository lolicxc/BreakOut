#include "Assets.h"

int brickTextures[3];

int backgroundGame;
int background;
int button;
int credits;

int paddleAsset;

int font;

int ballText;
int powerUpAsset;
int powerUpAsset2;

int howToPlay;

//sonidos
int backgroundSound;
int bounceSound;
int bookSound;

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
	font = slLoadFont("../res/Baisteach.ttf");
	powerUpAsset = slLoadTexture("../res/power.png");
	powerUpAsset2 = slLoadTexture("../res/power2.png");
	howToPlay = slLoadTexture("../res/HowToPlay.png");
}

void LoadAllAudio()
{
	backgroundSound = slLoadWAV("../res/music.wav");
	bounceSound = slLoadWAV("../res/bounce.wav");
	bookSound = slLoadWAV("../res/bookSound.wav");
	slSoundLoop(backgroundSound);
}