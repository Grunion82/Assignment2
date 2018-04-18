#include <SystemManager.h>
#include "Player.h"

#include "Bullet.h"

Player::Player()
{
}


Player::~Player()
{
}

bool Player::Init() {
	//Loads Image into variable
	image = SDL_LoadBMP("Sprites/player.bmp");
	imgRect = new SDL_Rect;
	if (!image)
		return false;

	imgRect->h = image->h;
	imgRect->w = image->w;

	//Have the image show up with the origin in the middle
	imgRect->x = (static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getWidth() / 10) - imgRect->w;
	imgRect->y = 600 - imgRect->h;

	lives = 3;

	return true;
}

void Player::Update() {

	int x = 0, y = 0;

	//Gets input system
	core::InputSystem* inputSystem = static_cast<core::InputSystem*>(core::SystemManager::getInstance()->getSystem<core::InputSystem>());

	//Moves left
	if (inputSystem->isKeyDown(SDLK_w)) {
		y = -1;
	}

	//Moves right
	if (inputSystem->isKeyDown(SDLK_s) && ((imgRect->y + imgRect->h) < static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getHeight())) {
		y = 1;
	}

	//Space bar shoots bullet
	//if (inputSystem->isKeyDown(SDLK_SPACE)) {}

	///Disabled Up and Down movement
	//Moves up
	if (inputSystem->isKeyDown(SDLK_a)) {
		x = -1;
	}

	//Moves down
	if (inputSystem->isKeyDown(SDLK_d) && ((imgRect->x + imgRect->w) < static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getWidth() / 2)) {
		x = 1;
	}

	//Update Coordinates
	imgRect->x += x;
	imgRect->y += y;
	}

void Player::Draw() const {
	//Have the scene/level create the surfaceToDrawTo and windowToUpdate variables so that each game object doesn't have to create new ones independently
	SDL_Surface* surfaceToDrawTo = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getSurface();

	//Have the gameobject put itself on the screen
	SDL_BlitSurface(image, NULL, surfaceToDrawTo, imgRect);
}

bool Player::Shutdown() {

	return true;
}

SDL_Surface* Player::getImage() {

	return image;
}

SDL_Rect Player::getRect() {

	return *imgRect;
}

void Player::shoot(Bullet* bullet) {

	//Spawn a new player bullet
	bullet->Spawn(imgRect->x + imgRect->w, (imgRect->h / 2) + imgRect->y);

}