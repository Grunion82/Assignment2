#include "InputSystem.h"

#include <SDL.h>
#include <iostream>

namespace core {
	InputSystem::InputSystem() : System(SystemType::INPUT),  quitRequested(false), upRequested(false), downRequested(false),
		leftRequested(false), rightRequested(false) {
		
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
					upRequested = true;
					break;
				case SDLK_a: //Make image move left
					leftRequested = true;
					break;
				case SDLK_s: //Make image move down
					downRequested = true;
					break;
				case SDLK_d: //Make image move right
					rightRequested = true;
					break;
				default:
					break;
				}
				break; 
			case SDL_KEYUP:
					switch (e.key.keysym.sym) {
					case SDLK_w: //Make image stop moving up
						upRequested = false;
						break;
					case SDLK_a: //Make image stop moving left
						leftRequested = false;
						break;
					case SDLK_s: //Make image stop moving down
						downRequested = false;
						break;
					case SDLK_d: //Make image stop moving right
						rightRequested = false;
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