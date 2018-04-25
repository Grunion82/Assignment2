#include "EnemyManager.h"
#include <stdlib.h> 



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
	enemySpawnTime = 0;
}

void EnemyManager::Update(float Deltatime)
{
	enemySpawnTime -= Deltatime;
	if (0 >= enemySpawnTime) {

		enemySpawnTime = rand() % 7 + 1; //Random number of seconds until the next wave of enemies


		enemySpawnCount = rand() % 5 + 2; //Random number of enemies to spawn

		for (int i = 0; i < enemySpawnCount; ++i) {
			for (int j = 0; j < 20; ++j) { //Go through all of the possible enemies
				if (enemies[j]->enabled == false) { //Check for any that aren't enabled
					enemies[j]->spawn(rand() % 2000 + 1200, rand() % 300 + 0); //Spawn the enemy off screen and across the y to ensure that they don't come in a big block
					break;
				}
			}
		}
	}
}
