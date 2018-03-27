#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <vector>

#include "Manager.h"
#include "System.h"

/*

template<class T>
class Singleton{

	static T* getInstance()

	private:
	Singleton()

	T* m_instance;

};

*/

namespace core {
	class SystemManager : public Manager
	{
	private:
		std::vector<System*> systems;
		SystemManager();

		static SystemManager* m_instance;
	public:
		~SystemManager();

		template<class T>
		T* getSystem() {
			for (System* sys : systems) {
				T* s = dynamic_cast<T*>(sys);
				if (s != nullptr)
					return s;
			}

			return nullptr;
		}

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		static SystemManager* getInstance() {
			if (!m_instance) {
				m_instance = new SystemManager();
			}
			return m_instance;
		}
	};
}

#endif // SYSTEMMANAGER_H