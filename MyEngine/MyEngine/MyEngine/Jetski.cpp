#include "Jetski.h"
#include "SystemManager.h"
#include "InputSystem.h"
#include "Window.h"

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

		imgRect.x = 50;
		imgRect.y = 50;	

		return true;
	}

	void Jetski::Update() {

	}

	void Jetski::Draw() const {
		SDL_Surface* surfaceToDrawTo = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getSurface();
		SDL_Window* windowToUpdate = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getWindow();

		SDL_BlitSurface(image, NULL, surfaceToDrawTo, &image->clip_rect);
		//SDL_UpdateWindowSurface(windowToUpdate);
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