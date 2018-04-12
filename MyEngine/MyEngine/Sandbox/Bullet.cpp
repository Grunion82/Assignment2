#include "Bullet.h"
#include <SystemManager.h>



Bullet::Bullet(bool decider, int x_, int y_, bool onScreen) : isEnemyBullet(decider), x(x_), y(y_), isOnscreen(false)
{
}


Bullet::~Bullet()
{
}

bool Bullet::Init() {
	//Loads Image into variable
	if (isEnemyBullet) {
		//Load enemy bullet
		image = SDL_LoadBMP("Sprites/enemy_bullet.bmp");
	}
	else {
		//Load player bullet
		image = SDL_LoadBMP("Sprites/player_bullet.bmp");
	}

	imgRect = new SDL_Rect;
	if (!image)
		return false;

	imgRect->h = image->h;
	imgRect->w = image->w;

	//Have the image show up with the origin in the middle
	imgRect->x = 0 - (imgRect->w / 2);
	imgRect->y = 0 - (imgRect->h / 2);

	if (isEnemyBullet) {
		//Set the velocity in the x
		yVelocity = 10;
	}
	else {
		//Set the velocity in the x
		yVelocity = -10;
	}

	//Have the image be created at the given x and y
	imgRect->x = x;
	imgRect->y = y;

	return true;
}

void Bullet::Update() {
	//Update Coordinates
	imgRect->y += yVelocity;
}

void Bullet::Draw() const {
	//Have the scene/level create the surfaceToDrawTo and windowToUpdate variables so that each game object doesn't have to create new ones independently
	SDL_Surface* surfaceToDrawTo = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getSurface();

	//Have the gameobject put itself on the screen
	SDL_BlitSurface(image, NULL, surfaceToDrawTo, imgRect);
}

bool Bullet::Shutdown() {

	return true;
}

void Bullet::Spawn(bool decider, int x_, int y_)
{
	//Have the bullet 'spawn' at the given x and y with the tag of enemy or player bullet
	imgRect->x = x;
	imgRect->y = y;

	isEnemyBullet = decider;
}

void Bullet::Remove()
{
	//Have the bullet be 'despawned' off the map
	imgRect->x = 10000000;
	imgRect->y = 10000000;
}

SDL_Surface* Bullet::getImage() {

	return image;
}

SDL_Rect Bullet::getRect() {

	return *imgRect;
}
