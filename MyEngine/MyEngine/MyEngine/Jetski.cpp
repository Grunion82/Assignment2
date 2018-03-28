#include "Jetski.h"
#include "SystemManager.h"

namespace scene {
	Jetski::Jetski() {

	}

	Jetski::~Jetski() {

	}

	bool Jetski::Init() {
		image = SDL_LoadBMP("jetski.bmp");
		if (!image)
			return false;

		imgRect.h = image->h;
		imgRect.w = image->w;

		//Have the image show up with the origin in the middle
		imgRect.x = 0 - (imgRect.w / 2);
		imgRect.y = 0 - (imgRect.h / 2);

		return true;
	}

	void Jetski::Update() {

	}

	void Jetski::Draw(SDL_Surface* surfaceToDrawTo, SDL_Window* windowToUpdate) const {
		SDL_BlitSurface(image, NULL, surfaceToDrawTo, &image->clip_rect);
	}

	bool Jetski::Shutdown() {

		return true;
	}

	SDL_Surface* Jetski::getImage() {

		return image;
	}

	SDL_Rect Jetski::getRect() {

		return imgRect;
	}
}