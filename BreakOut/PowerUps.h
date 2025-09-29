#pragma once
#include "Paddle.h"

enum class POWERUPTYPE
{
	MAXPADDLE,
	SHOOTPADDLE,
	THREEBALLS,
	LAUNCH
};
struct PowerUp
{
	POWERUPTYPE type;
	float xPos;
	float yPos;
	bool active;
	float speedY;  // velocidad de caída vertical
};


extern const int maxPowerUps;
extern PowerUp powerUps[];

void UpdatePowerUp();
bool CheckCollisionPowerUp(PowerUp& p, Paddle& paddle);
void ApplyPowerUpEffect(PowerUp& p, Paddle& paddle);
void UpdatePowerUpLogic(Paddle& paddle);
