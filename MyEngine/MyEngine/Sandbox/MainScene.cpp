#include <GameObject.h>
#include <SystemManager.h>

#include "MainScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

MainScene::MainScene() {
	gameObjects.push_back(new Player());
	gameObjects.push_back(new Enemy());
	gameObjects.push_back(new Enemy());
}


MainScene::~MainScene() {

}

bool MainScene::Init() {
	for (scene::GameObject* go : gameObjects) {
		if (!go->Init())
			return false;
	}

	dynamic_cast<Enemy*>(gameObjects[2])->setX(10);
	dynamic_cast<Enemy*>(gameObjects[2])->setY(95);
	dynamic_cast<Enemy*>(gameObjects[2])->setSpeed(1);

	return true;
}

void MainScene::Update() {
	//Adds a bullet to the gameObjects vector when space is pressed
	core::InputSystem* inputSystem = static_cast<core::InputSystem*>(core::SystemManager::getInstance()->getSystem<core::InputSystem>());
	if (inputSystem->isKeyDown(SDLK_SPACE))
		gameObjects.push_back(dynamic_cast<Player*>(gameObjects[0])->shoot());

	for (scene::GameObject* go : gameObjects) {
		go->Update();
	}
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
