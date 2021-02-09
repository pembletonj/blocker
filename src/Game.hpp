
#pragma once

#include "Window.hpp"
#include "Input.hpp"
#include "GameState.hpp"
#include "Entity.hpp"
#include <list>



class Player;

class Game {
public:

	bool launch();

	GameState get_game_state();
	bool set_game_state(GameState state);

	Input* get_input();
	Vec2 get_screen_size();

private:

	bool setup();
	bool run();
	void clean_up();

	void poll_input();
	void update();
	void render();

	void stop_playing();
	void start_playing();
	
	Window window;
	Input input;
	GameState state;

	Player* player;

	Uint32 last_update = 0;

};
