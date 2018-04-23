#include "Timer.h"
#include <SDL.h>

namespace core {
	Timer::Timer() {
		prevTicks = 0;
		currTicks = 0;
	}

	Timer::~Timer() {

	}

	void Timer::Start() {
		//Sets both to the current tick value
		prevTicks = SDL_GetTicks();
		currTicks = SDL_GetTicks();
	}

	void Timer::UpdateFrameTicks() {
		//Updates the ticks
		prevTicks = currTicks;
		currTicks = SDL_GetTicks();
	}

	float Timer::GetDeltaTime() const {
		return (float(currTicks - prevTicks) / 1000.0f);
	}

	unsigned int Timer::GetSleepTime(const unsigned int fps) const {
		//Caps the framerate at the passed FPS
		unsigned int milliSecsPerFrame = 1000 / fps;
		if (milliSecsPerFrame == 0) {
			return 0;
		}

		unsigned int sleepTime = milliSecsPerFrame - (SDL_GetTicks() - currTicks);
		if (sleepTime > milliSecsPerFrame) {
			return milliSecsPerFrame;
		}
		return sleepTime;
	}
}