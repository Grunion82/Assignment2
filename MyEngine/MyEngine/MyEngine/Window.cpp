#include <stdio.h>

#include "Window.h"

namespace core {
	Window::Window() : System(SystemType::WINDOW), SCREEN_WIDTH(WINDOW_SCREEN_WIDTH), SCREEN_HEIGHT(WINDOW_SCREEN_HEIGHT), TITLE("Space Invaders") {

	}


	Window::~Window() {

	}

	bool Window::Init() {

		bool initResult = true;

		//Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			initResult = WINDOW_INIT_ERROR;
		}
		else
		{
			//Create window
			window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				initResult = WINDOW_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Fill the surface white
				//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

				//Update the surface
				//SDL_UpdateWindowSurface(window);

				//Wait two seconds
				//SDL_Delay(2000);
			}
		}

		return initResult;
	}

	void Window::Update() {

	}

	void Window::Draw() const {
		//Fill the surface blue
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0xFF));
		//Update the surface
		//SDL_UpdateWindowSurface(window);
	}

	bool Window::Shutdown() {
		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		//SDL_Quit();
		return true;
	}

	SDL_Window* Window::getWindow() {

		return window;
	}

	SDL_Surface* Window::getSurface() {

		return screenSurface;
	}
}