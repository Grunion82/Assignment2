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
		virtual void Update();
		virtual void Draw(SDL_Surface* surfaceToDrawTo, SDL_Window* windowToUpdate) const;
		virtual bool Shutdown();
	};
}
#endif // GAMEOBJECT_H