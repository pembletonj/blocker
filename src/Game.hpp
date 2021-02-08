
#pragma once

#include "Window.hpp"
#include "Input.hpp"
#include "GameState.hpp"



class Game {
public:

	bool launch();

	GameState get_game_state();
	bool set_game_state(GameState state);

private:

	bool setup();
	bool run();
	void clean_up();

	void get_input();
	void update();
	void render();
	
	Window window;
	Input input;
	GameState state;

};
