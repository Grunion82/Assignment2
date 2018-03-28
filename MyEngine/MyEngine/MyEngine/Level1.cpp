#include "Level1.h"
#include "Jetski.h"
#include "SystemManager.h"
#include "Window.h"

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
		//Have the scene/level create the surfaceToDrawTo and windowToUpdate variables so that each game object doesn't have to create new ones independently
		SDL_Surface* surfaceToDrawTo = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getSurface();
		SDL_Window* windowToUpdate = static_cast<core::Window*>(core::SystemManager::getInstance()->getSystem<core::Window>())->getWindow();

		for (GameObject* go : gameObjects) {
			go->Draw(surfaceToDrawTo, windowToUpdate);

			//SDL_BlitSurface(go->getImage(), NULL, surfaceToDrawTo, &go->getRect());
		}

		SDL_UpdateWindowSurface(windowToUpdate);
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