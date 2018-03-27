#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "System.h"

namespace core {
	class InputSystem : public System
	{
	private:
		bool quitRequested;
	public:
		InputSystem();
		~InputSystem();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		inline bool QuitRequested() const { return quitRequested; }
	};
}

#endif // INPUTSYSTEM_H