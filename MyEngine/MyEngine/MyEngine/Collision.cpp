#include "Collision.h"
#include "GameObject.h"


namespace core {

	Collision::Collision() : System(SystemType::COLLISION), quitRequested(false)
	{
	}


	Collision::~Collision()
	{
	}

	bool Collision::Init()
	{
		return true;
	}

	void Collision::Update()
	{
	}

	void Collision::Draw() const
	{
	}

	bool Collision::Shutdown()
	{
		return true;
	}

	//Takes in two game objects to collide and checks for collision
	bool Collision::Collide(GameObject* gameObject1, GameObject* gameObject2)
	{
		/*

		//Check gameObject1 Collision Left/Right
		if (gameObject1->x <= gameObject2->x + gameObject2.width && gameObject1->x + gameObject1.width >= gameObject2->x) { //Checks to see if the gameObject1s are overlapping in the X
			if (gameObject1->y + gameObject1.hight >= gameObject2->y && gameObject1->y <= gameObject2->y + gameObject2.hight) { //Makes sure that the gameObject1s are also overlapping in the Y
			}
		}

		//Check gameObject1 Collision Top/Bottom
		if (gameObject1->y + gameObject1.hight >= gameObject2->y && gameObject1->y <= gameObject2->y + gameObject2.hight) { //Same as above, just in the opposite order to check for collisions from above/below
			if (gameObject1->x <= gameObject2->x + gameObject2.width && gameObject1->x + gameObject1.width >= gameObject2->x) {
			}
		}
		*/
		return false;
	}
}