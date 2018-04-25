#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H


#include "Enemy.h"
#include "Bullet.h"

class EnemyManager
{
private:

	Enemy* enemies[20];
	Bullet* enemyBullets[20];
	int enemySpawnCount;
	float enemySpawnTime;

public:
	EnemyManager();
	~EnemyManager();

	void Init(Enemy* _enemies[20], Bullet* _enemyBullets[20]);
	void Update(float Deltatime);
};

#endif // ENEMYMANAGER_H