#include <GameObject.h>
#include <SystemManager.h>

#include "MainScene.h"
#include "Player.h"

MainScene::MainScene() {
	gameObjects.push_back(new Player());
	enemyManager = new EnemyManager(); 
	numEnemies = 20;
	numEnemyBullets = 20;
	numPlayerBullets = 20;
}


MainScene::~MainScene() {

}

bool MainScene::Init() {
	for (scene::GameObject* go : gameObjects) {
		if (!go->Init())
			return false;
	}

	for (int i = 0; i < numEnemies; ++i) {
		gameObjects.push_back(new Enemy()); //Spawns 20 enemies
		enemies[i] = dynamic_cast<Enemy*>(gameObjects[i + 1]); //Copies the pointers into an array for easier usage
		enemies[i]->Init(); //Initialize the object within the pointer
	}

	for (int i = 0; i < numEnemyBullets; ++i) {
		gameObjects.push_back(new Bullet(true, 1, 1)); //Spawns 20 enemy bullets at position 1, 1 and tell them that they are on screen.
		enemyBullets[i] = dynamic_cast<Bullet*>(gameObjects[i + 21]); //Copies the pointers into an array for easier usage
		enemyBullets[i]->Init(); //Initialize the object within the pointer
	}

	for (int i = 0; i < numPlayerBullets; ++i) {
		gameObjects.push_back(new Bullet(false, 1, 1)); //Spawns 20 player bullets at position 1, 1 and tell them that they are on screen.
		playerBullets[i] = dynamic_cast<Bullet*>(gameObjects[i + 41]); //Copies the pointers into an array for easier usage
		playerBullets[i]->Init(); //Initialize the object within the pointer
	}

	enemyManager->Init(enemies, enemyBullets);

	return true;
}

void MainScene::Update() {
	//Adds a bullet to the gameObjects vector when space is pressed
	core::InputSystem* inputSystem = static_cast<core::InputSystem*>(core::SystemManager::getInstance()->getSystem<core::InputSystem>());
	if (inputSystem->wasKeyPressed(SDLK_SPACE)) {
		for (int i = 0; i < 20; ++i) { //Go through all of the possible playerBullets
			if (playerBullets[i]->enabled == false) { //Check for any that aren't enabled
				dynamic_cast<Player*>(gameObjects[0])->shoot(playerBullets[i]); //If they aren't enabled then spawn them infront of the player
				break;
			}
		}
	}

	for (scene::GameObject* go : gameObjects) {
		go->Update();
	}

	Collision();

	//Update enemyManager
	enemyManager->Update();
}

void MainScene::Draw() const {
	//Have all the objects 
	for (scene::GameObject* go : gameObjects) {
		go->Draw();
	}
}

bool MainScene::Shutdown() {
	for (scene::GameObject* go : gameObjects) {
		if (!go->Shutdown())
			return false;
		delete go;
		go = nullptr;
	}
	return true;
}

void MainScene::Collision()
{
	SDL_Rect* imgRect1;
	SDL_Rect* imgRect2;
	imgRect1 = &gameObjects[0]->getRect();
	for (int i = 0; i < numEnemies; ++i) {
		if (enemies[i]->enabled) {
			imgRect2 = &enemies[i]->getRect();
			//Check gameObject1 Collision Left/Right
			if (imgRect1->x <= imgRect2->x + imgRect2->w && imgRect1->x + imgRect1->w >= imgRect2->x) { //Checks to see if the gameObject1s are overlapping in the X
				if (imgRect1->y + imgRect1->h >= imgRect2->y && imgRect1->y <= imgRect2->y + imgRect2->h) { //Makes sure that the gameObject1s are also overlapping in the Y
					enemies[i]->enabled = false;
				}
			}

			//Check gameObject1 Collision Top/Bottom
			if (imgRect1->y + imgRect1->h >= imgRect2->y && imgRect1->y <= imgRect2->y + imgRect2->h) { //Same as above, just in the opposite order to check for collisions from above/below
				if (imgRect1->x <= imgRect2->x + imgRect2->w && imgRect1->x + imgRect1->w >= imgRect2->x) {
					enemies[i]->enabled = false;
				}
			}
		}
	}

	for (int i = 0; i < numEnemyBullets; ++i) {
		if (enemyBullets[i]->enabled) {
			imgRect2 = &enemyBullets[i]->getRect();
			//Check gameObject1 Collision Left/Right
			if (imgRect1->x <= imgRect2->x + imgRect2->w && imgRect1->x + imgRect1->w >= imgRect2->x) { //Checks to see if the gameObject1s are overlapping in the X
				if (imgRect1->y + imgRect1->h >= imgRect2->y && imgRect1->y <= imgRect2->y + imgRect2->h) { //Makes sure that the gameObject1s are also overlapping in the Y
					enemyBullets[i]->enabled = false;
				}
			}

			//Check gameObject1 Collision Top/Bottom
			if (imgRect1->y + imgRect1->h >= imgRect2->y && imgRect1->y <= imgRect2->y + imgRect2->h) { //Same as above, just in the opposite order to check for collisions from above/below
				if (imgRect1->x <= imgRect2->x + imgRect2->w && imgRect1->x + imgRect1->w >= imgRect2->x) {
					enemyBullets[i]->enabled = false;
				}
			}
		}
	}

	for (int i = 0; i < numEnemies; ++i) {
		for (int j = 0; j < numPlayerBullets; ++j) {
			if (enemies[i]->enabled && playerBullets[j]->enabled) {
				imgRect1 = &playerBullets[j]->getRect();
				imgRect2 = &enemies[i]->getRect();
				//Check gameObject1 Collision Left/Right
				if (imgRect1->x <= imgRect2->x + imgRect2->w && imgRect1->x + imgRect1->w >= imgRect2->x) { //Checks to see if the gameObject1s are overlapping in the X
					if (imgRect1->y + imgRect1->h >= imgRect2->y && imgRect1->y <= imgRect2->y + imgRect2->h) { //Makes sure that the gameObject1s are also overlapping in the Y
						enemies[i]->enabled = false;
						playerBullets[j]->enabled = false;
					}
				}

				//Check gameObject1 Collision Top/Bottom
				if (imgRect1->y + imgRect1->h >= imgRect2->y && imgRect1->y <= imgRect2->y + imgRect2->h) { //Same as above, just in the opposite order to check for collisions from above/below
					if (imgRect1->x <= imgRect2->x + imgRect2->w && imgRect1->x + imgRect1->w >= imgRect2->x) {
						enemies[i]->enabled = false;
						playerBullets[j]->enabled = false;
					}
				}
			}
		}
	}
}
