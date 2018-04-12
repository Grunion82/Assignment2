#include "SceneManager.h"

namespace core {
	SceneManager* SceneManager::m_instance = nullptr;

	SceneManager::SceneManager() {

	}


	SceneManager::~SceneManager() {

	}

	bool SceneManager::Init() {
		for (scene::Scene* sce : scenes) {
			if (!sce->Init())
				return false;
		}
		return true;
	}

	void SceneManager::Update() {
		for (scene::Scene* sce : scenes) {
			sce->Update();
		}
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