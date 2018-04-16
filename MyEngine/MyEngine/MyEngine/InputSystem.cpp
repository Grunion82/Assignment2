#include "InputSystem.h"

#include <SDL.h>
#include <iostream>

namespace core {
	InputSystem::InputSystem() : System(SystemType::INPUT),  quitRequested(false) {
		
	}


	InputSystem::~InputSystem() {

	}

	bool InputSystem::Init() {

		return true;
	}

	void InputSystem::Update() {

		oldKeys = keys;

		SDL_Event e;
				
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quitRequested = true;
				break;
			case SDL_KEYDOWN:
				//Adds the pressed button to a map, sets value at that key to true
				//printf("%d\n", e.key.repeat); //Observing the repeat variable from SDL_KeyEvent
				keys[e.key.keysym.sym] = true;
				break; 
			case SDL_KEYUP:
				//Gets the passed button key, sets value to false
				keys[e.key.keysym.sym] = false;
					break;
			default:
				break;
			}
		}
	}

	void InputSystem::Draw() const {

	}

	bool InputSystem::Shutdown() {

		return true;
	}

	bool InputSystem::isKeyDown(unsigned int key) {
		//Finds the pressed key's key and adds to map
		auto pressed = keys.find(key);

		//If Key exists, return it
		if (pressed != keys.end()) {
			return keys[key];
		}

		return false;
	}

	bool InputSystem::isKeyUp(unsigned int key) {

		auto up = keys.find(key);

		if (up != keys.end())
			return !keys[key]; //Returns the opposite boolean

		//If key can't be found, it will be up by default
		return true;
	}

	bool InputSystem::wasKeyPressed(unsigned int key) {

		auto was = oldKeys.find(key);

		if (was != oldKeys.end())
			return !oldKeys[key] && keys[key];

		return keys[key];
	}

	bool InputSystem::wasKeyReleased(unsigned int key) {

		auto was = oldKeys.find(key);

		if (was != oldKeys.end())
			return oldKeys[key] && !keys[key];
		else
			return false;
	}
}