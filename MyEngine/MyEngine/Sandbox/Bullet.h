#pragma once

#include <SDL.h>
#include <GameObject.h>

class Bullet : public scene::GameObject
{


private:
	//Image and its Rect variables for drawing
	SDL_Surface * image;
	SDL_Rect* imgRect;
	int xVelocity;
	int x, y;
	bool isOnscreen;

public:
	Bullet(bool decider, int x_, int y_);
	~Bullet();

	bool Init() override;
	void Update(float Deltatime) override;
	void Draw() const override;
	bool Shutdown() override;
	void Spawn(int x_, int y_);
	void Remove();

	SDL_Surface* getImage() override;
	SDL_Rect getRect() override;

	bool isEnemyBullet;
	bool enabled;
};

