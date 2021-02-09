
#include "Game.hpp"
#include "GameState.hpp"
#include "Player.hpp"
#include <SDL2/SDL.h>



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

	switch (this->state) {
	case PLAYING:
		stop_playing();
		break;
	}

	switch (state) {
	case PLAYING:
		start_playing();
		break;
	}

	this->state = state;

}



Input* Game::get_input() {
	return &input;
}

Vec2 Game::get_screen_size() {
	return window.get_size();
}



bool Game::setup() {

	if (!window.create_window("Blocker", Vec2(800, 600))) {
		SDL_Quit();
		return false;
	}

	input.add_key(SDLK_q);

	player = new Player;

	return true;

}

bool Game::run() {

	set_game_state(PLAYING);

	while (get_game_state() != QUIT) {

		poll_input();
		update();
		render();

	}

	return true;

}

void Game::clean_up() {

	input.remove_key(SDLK_q);
	window.destroy_window();

	delete player;

}



void Game::poll_input() {
	
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

	Uint32 now = SDL_GetTicks();
	if (now < last_update + 50) {
		return;
	}

	last_update = now;

	if (input.get_key(SDLK_q)) {
		set_game_state(QUIT);
	}

	player->update(this);

}

void Game::render() {

	SDL_Renderer* renderer = window.get_renderer();

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	player->render(renderer, 0.0);

	SDL_RenderPresent(renderer);

}



void Game::stop_playing() {
	if(player->is_alive()) {
		player->kill(this);
	}
}

void Game::start_playing() {
	player->spawn(this);
	player->set_max_velocity(8);
}
