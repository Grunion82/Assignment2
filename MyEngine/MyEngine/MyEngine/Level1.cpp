#include "Level1.h"
#include "Jetski.h"

namespace scene {
	Level1::Level1() {
		gameObjects.push_back(new Jetski());
	}
	
	Level1::~Level1() {

	}

	bool Level1::Init() {
		for (GameObject* go : gameObjects) {
			if (!go->Init())
				return false;
		}
		return true;
	}

	void Level1::Update() {
		for (GameObject* go : gameObjects) {
			go->Update();
		}
	}

	void Level1::Draw() const {
		for (GameObject* go : gameObjects) {
			go->Draw();
		}
	}

	bool Level1::Shutdown() {
		for (GameObject* go : gameObjects) {
			if (!go->Shutdown())
				return false;
			delete go;
			go = nullptr;
		}
		return true;
	}
}