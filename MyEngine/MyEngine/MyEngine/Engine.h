#ifndef ENGINE_H
#define ENGINE_H

#define ENGINE_INIT_ERROR		1
#define ENGINE_SHUTDOWN_ERROR	2

#include <stdio.h>
#include <vector>
#include <SDL.h>

#include "SystemManager.h"
#include "SceneManager.h"

namespace core {
	class Engine {
	private:
		bool isRunning;
		std::vector<class Manager*> managers;

	public:
		Engine(scene::Scene* s);
		~Engine();

		int Init();
		int Run();

	private:
		void Update();
		void Draw() const;
		int Shutdown();

	};
}

#endif // ENGINE_H