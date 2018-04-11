#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <map>

#include "System.h"

namespace core {
	class InputSystem : public System
	{
	private:
		bool quitRequested;

		//Map for holding key's and if they are pressed or not (true/false)
		std::map<unsigned int, bool> keys;

	public:
		InputSystem();
		~InputSystem();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		inline bool QuitRequested() const { return quitRequested; }

		//Checks for a key press
		bool isKeyDown(unsigned int key);
	};
}

#endif // INPUTSYSTEM_H