#ifndef WINDOW_H
#define WINDOW_H

#define WINDOW_INIT_ERROR		false
#define WINDOW_SHUTDOWN_ERROR	false

#define WINDOW_SCREEN_WIDTH		680
#define WINDOW_SCREEN_HEIGHT	400

#include <SDL.h>

#include "System.h"

namespace core {
	class Window : public System
	{
	private:
		//Screen dimension constants
		const int SCREEN_WIDTH;
		const int SCREEN_HEIGHT;

		const char* TITLE;

		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

	public:
		Window();
		~Window();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		SDL_Window* getWindow();
		SDL_Surface* getSurface();
	};
}
#endif // WINDOW_H