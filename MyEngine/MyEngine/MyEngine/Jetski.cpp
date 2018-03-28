#include "Jetski.h"
#include "SystemManager.h"

namespace scene {
	Jetski::Jetski() {

	}

	Jetski::~Jetski() {

	}

	bool Jetski::Init() {
		image = SDL_LoadBMP("jetski.bmp");
		imgRect = new SDL_Rect;
		if (!image)
			return false;

		imgRect->h = image->h;
		imgRect->w = image->w;

		//Have the image show up with the origin in the middle
		imgRect->x = 0 - (imgRect->w / 2);
		imgRect->y = 0 - (imgRect->h / 2);

		return true;
	}

	void Jetski::Update() {
		imgRect->x += 1;
		imgRect->y += 1;
	}

	void Jetski::Draw(SDL_Surface* surfaceToDrawTo, SDL_Window* windowToUpdate) const {
		//Have the gameobject put itself on the screen
		SDL_BlitSurface(image, NULL, surfaceToDrawTo, imgRect);
	}

	bool Jetski::Shutdown() {

		return true;
	}

	SDL_Surface* Jetski::getImage() {

		return image;
	}

	SDL_Rect Jetski::getRect() {

		return *imgRect;
	}
}