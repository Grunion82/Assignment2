#pragma once

#include <SDL.h>
#include <GameObject.h>

class Bullet : public scene::GameObject
{


private:
	//Image and its Rect variables for drawing
	SDL_Surface * image;
	SDL_Rect* imgRect;
	int yVelocity;
	int x, y;
	bool isOnscreen;

public:
	Bullet(bool decider, int x_, int y_, bool onScreen);
	~Bullet();

	bool Init() override;
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;
	void Spawn(int x_, int y_);
	void Remove();

<<<<<<< HEAD:MyEngine/MyEngine/Sandbox/Enemy.h
	SDL_Surface* getImage() override;
	SDL_Rect getRect() override;

	void shoot(class Bullet* b);
=======
	SDL_Surface* getImage();
	SDL_Rect getRect();
	bool isEnemyBullet;
>>>>>>> 196b2fdeaf0653041c70c067f42817da8ee8df8d:MyEngine/MyEngine/Sandbox/Bullet.h
};

