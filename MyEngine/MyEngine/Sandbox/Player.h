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
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;

	SDL_Surface* getImage();
	SDL_Rect getRect();
};

#endif // PLAYER_H