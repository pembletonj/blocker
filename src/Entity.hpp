
#pragma once

#include "Game.hpp"



class Game;

class Entity {
public:

	virtual void update(Game* game) = 0;
	virtual void render(SDL_Renderer* renderer, double interpolation) = 0;

};
