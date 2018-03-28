#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "System.h"

namespace core {
	class InputSystem : public System
	{
	private:
		bool quitRequested, upRequested, leftRequested, downRequested, rightRequested;
	public:
		InputSystem();
		~InputSystem();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		inline bool QuitRequested() const { return quitRequested; }

		inline bool UpRequested() const { return upRequested; }
		inline bool LeftRequested() const { return leftRequested; }
		inline bool DownRequested() const { return downRequested; }
		inline bool RightRequested() const { return rightRequested; }
	};
}

#endif // INPUTSYSTEM_H