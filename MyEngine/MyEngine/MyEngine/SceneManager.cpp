#include "SceneManager.h"
#include "Level1.h"

namespace core {
	SceneManager* SceneManager::m_instance = nullptr;

	SceneManager::SceneManager() {
		scenes.push_back(new scene::Level1());
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
}