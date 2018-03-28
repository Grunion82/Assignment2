#include "Engine.h"
#include "InputSystem.h"
#include "Window.h"

namespace core {
	Engine::Engine(scene::Scene* s) : isRunning(false) { //Initializing this way avoids doubley initializing variables (calling constructor)
		managers.push_back(SystemManager::getInstance());
		managers.push_back(SceneManager::getInstance());
	}

	Engine::~Engine() {

	}

	int Engine::Init() {

		for (Manager* man : managers) {
			if (!man->Init())
				return false;
		}

		return 0;
	}

	int Engine::Run() {

		

		while (!isRunning) {
			Update();
			Draw();
		}

		return Shutdown();
	}

	void Engine::Update() {
		for (Manager* man : managers) {
			man->Update();
		}

		isRunning = static_cast<SystemManager*>(SystemManager::getInstance())->getSystem<InputSystem>()->QuitRequested();
	}

	void Engine::Draw() const {
		for (Manager* man : managers) {
			man->Draw();
		}
		SDL_UpdateWindowSurface(static_cast<Window*>(SystemManager::getInstance()->getSystem<Window>())->getWindow());
	}

	int Engine::Shutdown() {
		for (Manager* man : managers) {
			if (!man->Shutdown())
				return false;
			delete man;
			man = nullptr;
		}

		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}
}
