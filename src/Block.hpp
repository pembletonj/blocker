
#pragma once

#include "Game.hpp"
#include "Entity.hpp"
#include <SDL2/SDL.h>



class Block : public Entity {
public:

	virtual void spawn(Game* game) = 0;
	virtual void kill(Game* game) = 0;
	bool is_alive();

	bool intersects(Block* other);
	SDL_Rect get_area();

	void render(SDL_Renderer* renderer, double interpolation);

protected:

	void update_position();

	SDL_Rect area;
	Vec2 velocity;
	SDL_Color colour;
	bool alive = false;

};
