#ifndef JETSKI_H
#define JETSKI_H

#include <SDL.h>

#include "GameObject.h"

namespace scene {
	class Jetski : public GameObject
	{
	private:
		SDL_Surface* image;
		SDL_Rect imgRect;

	public:
		Jetski();
		~Jetski();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		SDL_Surface* getImage();
		SDL_Rect getRect();
	};
}

#endif // JETSKI_H