#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <Scene.h>
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyManager.h"

namespace scene {
	class GameObject;
}

class MainScene : public scene::Scene 
{
private: 
	//Vector of GameObjects in the scene
	std::vector<scene::GameObject*> gameObjects;

	//Creating seperate arrays to iterate through
	Enemy* enemies [20];
	Bullet* enemyBullets[20];
	Bullet* playerBullets[20];

	EnemyManager* enemyManager;

public:
	MainScene();
	~MainScene();

	bool Init() override;
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;
};

#endif //MAINSCENE_H
