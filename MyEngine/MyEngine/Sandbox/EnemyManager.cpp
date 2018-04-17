#include "EnemyManager.h"



EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

void EnemyManager::Init(Enemy * _enemies[20], Bullet * _enemyBullets[20])
{
	//Copy all of the enemy and enemyBullet pointers into here
	memcpy(enemies, _enemies, sizeof(enemies));
	memcpy(enemyBullets, _enemyBullets, sizeof(enemyBullets));
}

void EnemyManager::Update()
{
}
