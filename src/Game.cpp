
#include "Game.hpp"
#include "GameState.hpp"
#include <SDL_render.h>



bool Game::launch() {

	if (!setup()) {
		return false;
	}

	bool success = run();

	clean_up();
	return success;

}



GameState Game::get_game_state() {
	return state;
}

bool Game::set_game_state(GameState state) {

	this->state = state;

}



bool Game::setup() {

	if (!window.create_window("Blocker", Vec2(800, 600))) {
		SDL_Quit();
		return false;
	}

	input.add_key(SDLK_q);

	return true;

}

bool Game::run() {

	set_game_state(PLAYING);


	while (get_game_state() != QUIT) {

		get_input();
		update();
		render();

	}

	return true;

}

void Game::clean_up() {

	input.remove_key(SDLK_q);
	window.destroy_window();

}



void Game::get_input() {
	
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			set_game_state(QUIT);
			break;
		case SDL_KEYDOWN:
			input.set_key(event.key.keysym.sym, true);
			break;
		case SDL_KEYUP:
			input.set_key(event.key.keysym.sym, false);
			break;
		}
	}

}

void Game::update() {

	if (input.get_key(SDLK_q)) {
		set_game_state(QUIT);
	}

}

void Game::render() {

	SDL_Renderer* renderer = window.get_renderer();

	SDL_SetRenderDrawColor(renderer, 0, 100, 50, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

}

