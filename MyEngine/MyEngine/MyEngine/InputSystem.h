#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <map>

#include "System.h"

namespace core {
	class InputSystem : public System
	{
	private:

		//Map for holding key's and if they are pressed or not (true/false)
		std::map<unsigned int, bool> keys;

		//Map to contain all the old keys in their previous state
		std::map<unsigned int, bool> oldKeys;

	public:
		InputSystem();
		~InputSystem();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		bool quitRequested;

		//Checks for a key press
		bool isKeyDown(unsigned int key);
		//Checks if the key is not pressed
		bool isKeyUp(unsigned int key);
		//Checks if the key was pressed
		bool wasKeyPressed(unsigned int key);
		//Checks if the key was released
		bool wasKeyReleased(unsigned int key);
	};
}

#endif // INPUTSYSTEM_H