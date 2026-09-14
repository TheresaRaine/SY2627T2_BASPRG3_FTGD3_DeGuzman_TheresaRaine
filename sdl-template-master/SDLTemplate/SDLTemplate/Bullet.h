#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
class Bullet : public GameObject
{
public:
	Bullet(int positionX, int positionY, int directionX, int directionY, int speed);
	virtual void start() override;
	virtual void update() override;
	virtual void draw() override;
	int getX();
	int getY();
private:
	int x;
	int y;
	int width;
	int height;
	int speed;

	int directionX;
	int directionY;

	SDL_Texture* texture;

};

