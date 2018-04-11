#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>

#include "Manager.h"
#include "Scene.h"


namespace core {
	class SceneManager : public Manager
	{
	private:
		std::vector<scene::Scene*> scenes;
		SceneManager();

		static SceneManager* m_instance;
	public:
		~SceneManager();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		static SceneManager* getInstance() {
			if (!m_instance) {
				m_instance = new SceneManager();
			}
			return m_instance;
		}

		void push_back(scene::Scene* s);
	};
}

#endif // SCENEMANAGER_H