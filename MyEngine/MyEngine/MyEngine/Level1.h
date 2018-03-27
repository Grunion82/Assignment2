#ifndef LEVEL1_H
#define LEVEL1_H

#include "Scene.h"
#include "GameObject.h"

namespace scene {
	class Level1 : public Scene
	{
	private:
		std::vector<GameObject*> gameObjects;

	public:
		Level1();
		~Level1();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
	};
}

#endif // LEVEL1_H