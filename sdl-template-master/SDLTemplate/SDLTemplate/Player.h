#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "Bullet.h"
#include <vector>

class Player : public GameObject
{
public:
	~Player();
	virtual void start() override;
	virtual void update() override;
	virtual void draw() override;
private:
	int x;
	int y;
	int width;
	int height;

	SDL_Texture* texture;
	Mix_Chunk* sound;

	int speed;
	int increase;
	int normal;

	float reloadTime;
	float secondReloadTime;
	float currentReloadTime;
	float secondcurrentReloadTime;

	std::vector<Bullet*> bullets;
};

