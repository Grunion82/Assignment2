#ifndef COLLISION_H
#define COLLISION_H


#include "System.h"

namespace core {
	class Collision : public System
	{
	private:
		bool quitRequested;

	public:
		Collision();
		~Collision();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		bool Collide(class GameObject* gameObject1, class GameObject* gameObject2);

		inline bool QuitRequested() const { return quitRequested; }
	};

}


#endif // !COLLISION_H