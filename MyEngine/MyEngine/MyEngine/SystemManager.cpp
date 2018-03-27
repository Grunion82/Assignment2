#include "SystemManager.h"
#include "InputSystem.h"
#include "Window.h"

namespace core {
	SystemManager* SystemManager::m_instance = nullptr;

	SystemManager::SystemManager() {
		systems.push_back(new InputSystem());
		systems.push_back(new Window());
	}


	SystemManager::~SystemManager() {

	}

	bool SystemManager::Init() {
		for (System* sys : systems) {
			if (!sys->Init())
				return false;
		}

		return true;
	}

	void SystemManager::Update() {
		for(System* sys : systems) {
			sys->Update();
		}
	}

	void SystemManager::Draw() const {
		for (System* sys : systems) {
			sys->Draw();
		}
	}

	bool SystemManager::Shutdown() {
		for (System* sys : systems) {
			if (!sys->Shutdown())
				return false;
			delete sys;
			sys = nullptr;
		}
		return true;
	}
}