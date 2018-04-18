#include "Enemy.h"
#include <SystemManager.h>


Enemy::Enemy() : speed(1) {

}


Enemy::~Enemy() {

}

bool Enemy::Init() {
	//Loads Image into variable
	image = SDL_LoadBMP("Sprites/enemy.bmp");
	imgRect = new SDL_Rect;
	if (!image)
		return false;

	imgRect->h = image->h;
	imgRect->w = image->w;

	//Have the image show up with the origin in the middle
	imgRect->x = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getWidth() - imgRect->w - 10;// 0 - (imgRect->w / 2);
	imgRect->y = 10;// -(imgRect->h / 2);

	enabled = false; //Set the enemy to not be enabled when starting

	return true;
}

void Enemy::Update() {
	if (enabled) { //If the enemy is enabled then update it
		if (imgRect->y <= 5)
			speed *= -1;
		if (imgRect->y + imgRect->h == static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getHeight() - 5)
			speed *= -1;

		--imgRect->x;

		imgRect->y += speed;

		if (imgRect->x <= 10) {
			enabled = false;
		}
	}
}

void Enemy::Draw() const {
	if (enabled) { //If the enemy is enabled then draw it
		//Have the scene/level create the surfaceToDrawTo and windowToUpdate variables so that each game object doesn't have to create new ones independently
		SDL_Surface* surfaceToDrawTo = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getSurface();

		//Have the gameobject put itself on the screen
		SDL_BlitSurface(image, NULL, surfaceToDrawTo, imgRect);
	}
}



bool Enemy::Shutdown() {

	return true;
}

SDL_Surface* Enemy::getImage() {
	
	return image;
}

SDL_Rect Enemy::getRect() {

	return *imgRect;
}