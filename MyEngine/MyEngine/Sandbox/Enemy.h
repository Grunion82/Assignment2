#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>
#include <GameObject.h>

class Enemy : public scene::GameObject
{
private:
	//Image and its Rect variables for drawing
	SDL_Surface * image;
	SDL_Rect* imgRect;

	int speed;

public:
	Enemy();
	~Enemy();

	bool Init() override;
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;

	SDL_Surface* getImage() override;
	SDL_Rect getRect() override;

	void shoot(class Bullet* b);
};

#endif // ENEMY_H