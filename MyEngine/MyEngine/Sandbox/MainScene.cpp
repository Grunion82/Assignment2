#include <GameObject.h>
#include <SystemManager.h>

#include "MainScene.h"
#include "Player.h"

MainScene::MainScene() {
	gameObjects.push_back(new Player());
	enemyManager = new EnemyManager();
}


MainScene::~MainScene() {

}

bool MainScene::Init() {
	for (scene::GameObject* go : gameObjects) {
		if (!go->Init())
			return false;
	}

	for (int i = 0; i < 20; ++i) {
		gameObjects.push_back(new Bullet(true, 1, 1, true)); //Spawns 20 player bullets at position 1, 1 and tell them that they are on screen.
		playerBullets[i] = dynamic_cast<Bullet*>(gameObjects[i + 1]); //Copies the pointers into an array for easier usage
		playerBullets[i]->Init(); //Initialize the object within the pointer
	}

	for (int i = 0; i < 20; ++i) {
		gameObjects.push_back(new Bullet(false, 1, 1, true)); //Spawns 20 enemy bullets at position 1, 1 and tell them that they are on screen.
		enemyBullets[i] = dynamic_cast<Bullet*>(gameObjects[i + 21]); //Copies the pointers into an array for easier usage
		enemyBullets[i]->Init(); //Initialize the object within the pointer
	}

	for (int i = 0; i < 20; ++i) {
		gameObjects.push_back(new Enemy()); //Spawns 20 enemies
		enemies[i] = dynamic_cast<Enemy*>(gameObjects[i + 41]); //Copies the pointers into an array for easier usage
		enemies[i]->Init(); //Initialize the object within the pointer
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
