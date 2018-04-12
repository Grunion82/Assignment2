#include "Player.h"
#include <SystemManager.h>


Player::Player()
{
}


Player::~Player()
{
}

bool Player::Init() {
	//Loads Image into variable
	image = SDL_LoadBMP("player.bmp");
	imgRect = new SDL_Rect;
	if (!image)
		return false;

	imgRect->h = image->h;
	imgRect->w = image->w;

	//Have the image show up with the origin in the middle
	imgRect->x = 0 - (imgRect->w / 2);
	imgRect->y = 0 - (imgRect->h / 2);

	lives = 3;

	return true;
}

void Player::Update() {

	int x = 0, y = 0;

	//Gets input system
	core::InputSystem* inputSystem = static_cast<core::InputSystem*>(core::SystemManager::getInstance()->getSystem<core::InputSystem>());

	//Moves left
	if (inputSystem->isKeyDown(SDLK_a)) {
		x = -1;
	}

	//Moves right
	if (inputSystem->isKeyDown(SDLK_d)) {
		x = 1;
	}

	//Moves up
	if (inputSystem->isKeyDown(SDLK_w)) {
		y = -1;
	}

	//Moves down
	if (inputSystem->isKeyDown(SDLK_s)) {
		y = 1;
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
