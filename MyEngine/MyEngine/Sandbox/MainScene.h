#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <Scene.h>

namespace scene {
	class GameObject;
}

class MainScene : public scene::Scene 
{
private: 
	//Vector of GameObjects in the scene
	std::vector<scene::GameObject*> gameObjects;

public:
	MainScene();
	~MainScene();

	bool Init() override;
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;
};

#endif //MAINSCENE_H
