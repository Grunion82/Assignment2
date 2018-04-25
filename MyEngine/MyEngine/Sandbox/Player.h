#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <GameObject.h>

class Player : public scene::GameObject
{

private:
	//Image and its Rect variables for drawing
	SDL_Surface * image;
	SDL_Rect* imgRect;

public:
	Player();
	~Player();

	bool Init() override;
	void Update(float Deltatime) override;
	void Draw() const override;
	bool Shutdown() override;

	SDL_Surface* getImage() override;
	SDL_Rect getRect() override;

	void shoot(class Bullet* bullet);
};

#endif // PLAYER_H