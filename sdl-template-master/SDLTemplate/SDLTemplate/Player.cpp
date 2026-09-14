#include "Player.h"
#include "GameScene.h"

Player::~Player()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		delete bullets[i];
	}


}

void Player::start()
{
	
	texture = loadTexture("gfx/player.png");
	sound = SoundManager::loadSound("sound/sparkle.mp3");

	x = 100;
	y = 100;
	width = 0;
	height = 0;
	speed = 1;
	increase = 5;
	normal = 1;

	reloadTime = 8;
	secondReloadTime = 20;
	currentReloadTime = 0;
	secondcurrentReloadTime = 0;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Player::update()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->getX() > SCREEN_WIDTH)
		{
			Bullet* bulletToDelete = bullets[i];
			bullets.erase(bullets.begin() + i);
			delete bulletToDelete;

			break;
		}

	}
	if (currentReloadTime > 0)
	{
		currentReloadTime--;
	}
	if (secondcurrentReloadTime > 0)
	{
		secondcurrentReloadTime--;
	}
	if (app.keyboard[SDL_SCANCODE_F] && currentReloadTime <= 0)
	{
		SoundManager::playSound(sound);
		Bullet* bullet = new Bullet
		(
			x + width - 5,
			y + height / 2 - 5,
			1,
			0,
			5
		
		);
		getScene()->addGameObject(bullet);
		bullets.push_back(bullet);

		currentReloadTime = reloadTime;
	}
	if (app.keyboard[SDL_SCANCODE_G] && secondcurrentReloadTime <= 0)
	{
		SoundManager::playSound(sound);
		Bullet* bullet = new Bullet
		(
			x + width - 5,
			y + height / 2 - 30,
			1,
			0,
			5

		);
		getScene()->addGameObject(bullet);
		bullets.push_back(bullet);

		SoundManager::playSound(sound);
		Bullet* bullet1 = new Bullet
		(
			x + width - 5,
			y + height / 2 + 30,
			1,
			0,
			5

		);
		getScene()->addGameObject(bullet1);
		bullets.push_back(bullet1);

		secondcurrentReloadTime = secondReloadTime;

	}

	
	if (app.keyboard[SDL_SCANCODE_W])
	{
		y -= speed;
	}
	if (app.keyboard[SDL_SCANCODE_S])
	{
		y += speed;
	}
	if (app.keyboard[SDL_SCANCODE_A])
	{
		x -= speed;
	}
	if (app.keyboard[SDL_SCANCODE_D])
	{
		x += speed;
	}
	if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		speed = increase;
	
	}
	if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		speed = normal;
	
	}

}


void Player::draw()
{
	blit(texture, x, y);

}

