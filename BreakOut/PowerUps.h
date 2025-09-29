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
	float speedY;  // velocidad de ca�da vertical
};


extern const int maxPowerUps;
extern PowerUp powerUps[];

void UpdatePowerUp();
bool CheckCollisionPowerUp(PowerUp& p, Paddle& paddle);
void ApplyPowerUpEffect(PowerUp& p, Paddle& paddle);
void UpdatePowerUpLogic(Paddle& paddle);
