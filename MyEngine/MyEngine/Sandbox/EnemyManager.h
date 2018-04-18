
#include "Enemy.h"
#include "Bullet.h"

class EnemyManager
{
private:

	Enemy* enemies[20];
	Bullet* enemyBullets[20];
	int enemySpawnTime, enemySpawnCount, rando3, rando4;

public:
	EnemyManager();
	~EnemyManager();

	void Init(Enemy* _enemies[20], Bullet* _enemyBullets[20]);
	void Update();
};

