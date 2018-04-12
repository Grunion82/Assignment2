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
		virtual void Draw() const;
		virtual bool Shutdown();

		inline virtual SDL_Surface* getImage() {
			return new SDL_Surface();
		}
		inline virtual SDL_Rect getRect() {
			return SDL_Rect();
		}
	};
}
#endif // GAMEOBJECT_H