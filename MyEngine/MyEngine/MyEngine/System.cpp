#include "System.h"

namespace core {
	System::System(SystemType st) : type(st) {

	}


	System::~System() {

	}

	bool System::Init() {

		return true;
	}

	void System::Update() {

	}

	void System::Draw() const {

	}

	bool System::Shutdown() {

		return true;
	}
}