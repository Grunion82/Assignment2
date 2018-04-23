#include "SceneManager.h"

#include <SDL.h>

namespace core {
	SceneManager* SceneManager::m_instance = nullptr;

	SceneManager::SceneManager() {
		timer = Timer();
	}


	SceneManager::~SceneManager() {

	}

	bool SceneManager::Init() {
		for (scene::Scene* sce : scenes) {
			if (!sce->Init())
				return false;
		}
		timer.Start();
		return true;
	}

	void SceneManager::Update() {
		//Updates time
		timer.UpdateFrameTicks();
		for (scene::Scene* sce : scenes) {
			sce->Update(timer.GetDeltaTime());
		}
		//Caps the framerate at 60
		SDL_Delay(timer.GetSleepTime(60));
	}

	void SceneManager::Draw() const {
		for (scene::Scene* sce : scenes) {
			sce->Draw();
		}
	}

	bool SceneManager::Shutdown() {
		for (scene::Scene* sce : scenes) {
			if (!sce->Shutdown())
				return false;
			delete sce;
			sce = nullptr;
		}
		return true;
	}

	void SceneManager::push_back(scene::Scene* s) {
		scenes.push_back(s);
	}
}