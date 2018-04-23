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
	void Update(float Deltatime) override;
	void Draw() const override;
	bool Shutdown() override;

	SDL_Surface* getImage();
	SDL_Rect getRect();

	//Getters and setters for position
	inline void setX(int x) { imgRect->x = x; }	
	inline void setY(int y) { imgRect->y = y; }
	inline int getX() { return imgRect->x; }
	inline int getY() { return imgRect->y; }
	inline void setSpeed(int _speed) { speed = _speed; }
	inline int getSpeed() { return speed;  }

	inline void spawn(int x, int y) { imgRect->x = x; imgRect->y = y; enabled = true; };

	bool enabled;
};

#endif // ENEMY_H