
#include "Game.hpp"
#include <SDL2/SDL.h>
#include <iostream>



int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "E: Failed to initialize SDL2: "  << SDL_GetError() << std::endl;
		return 1;
	}

	Game game;

	game.launch();

	SDL_Quit();

}
