#include "Bullet.h"
#include <SystemManager.h>


//Sets isOnscreen to true for testing bullet spawning
Bullet::Bullet(bool decider, int x_, int y_) : isEnemyBullet(decider), x(x_), y(y_)
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

	enabled = false;

	imgRect = new SDL_Rect;
	if (!image)
		return false;

	imgRect->h = image->h;
	imgRect->w = image->w;

	//Sets's object's location
	imgRect->x = x;
	imgRect->y = y;

	if (isEnemyBullet) {
		//Set the velocity in the x
		xVelocity = -10;
	}
	else {
		//Set the velocity in the x
		xVelocity = 10;
	}

	//Have the image be created at the given x and y
	imgRect->x = x;
	imgRect->y = y;

	return true;
}

void Bullet::Update(float Deltatime) {
	//Update Coordinates
	if (enabled) {
		imgRect->x += xVelocity; //If the bullet is enabled then update position
		if (imgRect->x > 1210 || imgRect ->x <= 10 ) {
			enabled = false;
		}
	}
}

void Bullet::Draw() const {
	//Only draw the bullet if it is considered "on screen" and is enabled
	if (enabled) {
		//Have the scene/level create the surfaceToDrawTo and windowToUpdate variables so that each game object doesn't have to create new ones independently
		SDL_Surface* surfaceToDrawTo = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getSurface();

		//Have the gameobject put itself on the screen
		SDL_BlitSurface(image, NULL, surfaceToDrawTo, imgRect);
	}
}

bool Bullet::Shutdown() {

	return true;
}

void Bullet::Spawn(int x_, int y_)
{
	//Have the bullet 'spawn' at the given x and y with the tag of enemy or player bullet. Sets on screen to true
	imgRect->x = x_;
	imgRect->y = y_;
	enabled = true;
}

void Bullet::Remove()
{
	//Have the bullet be 'despawned' off the map. Stop drawing this
	isOnscreen = false;
	enabled = false;
}

SDL_Surface* Bullet::getImage() {

	return image;
}

SDL_Rect Bullet::getRect() {

	return *imgRect;
}
