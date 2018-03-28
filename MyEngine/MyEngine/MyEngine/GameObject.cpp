#include "GameObject.h"

namespace scene {
	GameObject::GameObject() {

	}


	GameObject::~GameObject() {

	}

	bool GameObject::Init() {

		return true;
	}

	void GameObject::Update(int x, int y) {

	}

	void GameObject::Draw(SDL_Surface* surfaceToDrawTo, SDL_Window* windowToUpdate) const {

	}

	bool GameObject::Shutdown() {

		return true;
	}
}