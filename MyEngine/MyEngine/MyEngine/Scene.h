#ifndef SCENE_H
#define SCENE_H

#include <vector>

namespace scene {
	class Scene	{
	private:
		//std::vector<class GameObject> gameObjects;
	public:
		Scene();
		virtual ~Scene();

		virtual bool Init();
		virtual void Update(float Deltatime);
		virtual void Draw() const;
		virtual bool Shutdown();
	};
}

#endif // SCENE_H