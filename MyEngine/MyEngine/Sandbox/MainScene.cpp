#include <GameObject.h>
#include <SystemManager.h>

#include "MainScene.h"
#include "Player.h"

MainScene::MainScene() {
	gameObjects.push_back(new Player());
}


MainScene::~MainScene() {

}

bool MainScene::Init() {
	for (scene::GameObject* go : gameObjects) {
		if (!go->Init())
			return false;
	}
	return true;
}

void MainScene::Update() {
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
