
#pragma once

#include "Game.hpp"
#include "Entity.hpp"
#include "Block.hpp"


class Game;

class Player : public Block {
public:

	void update(Game* game);

	void spawn(Game* game);
	void kill(Game* game);

	void set_max_velocity(int max_velocity);

private:

	void handle_input(Input* input);
	void clamp_to_screen(Vec2 screen_size);

	int max_velocity;

};
