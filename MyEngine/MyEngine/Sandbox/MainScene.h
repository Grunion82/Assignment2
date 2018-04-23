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

	int numEnemies, numEnemyBullets, numPlayerBullets;

public:
	MainScene();
	~MainScene();

	bool Init() override;
	void Update(float Deltatime) override;
	void Draw() const override;
	bool Shutdown() override;

	void Collision();
};

#endif //MAINSCENE_H
