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
		SDL_Event e;
				
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quitRequested = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					quitRequested = true;
					break;
				case SDLK_w: //Make image move up
					break;
				case SDLK_a: //Make image move left
					break;
				case SDLK_s: //Make image move down
					break;
				case SDLK_d: //Make image move right
					break;
				default:
					break;
				}
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
}