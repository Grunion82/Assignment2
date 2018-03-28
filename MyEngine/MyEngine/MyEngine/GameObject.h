#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "InputSystem.h"
#include "Window.h"

namespace scene {
	class GameObject {
	public:
		GameObject();
		virtual ~GameObject();

		virtual bool Init();
		virtual void Update(int x, int y);
		virtual void Draw(SDL_Surface* surfaceToDrawTo, SDL_Window* windowToUpdate) const;
		virtual bool Shutdown();

		virtual SDL_Surface* getImage() = 0;
		virtual SDL_Rect getRect() = 0;
	};
}
#endif // GAMEOBJECT_H