
#include "Window.hpp"
#include "Vec2.hpp"
#include "Input.hpp"
#include <SDL2/SDL.h>
#include <SDL_events.h>
#include <SDL_keycode.h>
#include <iostream>



int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "E: Failed to initialize SDL2: "  << SDL_GetError() << std::endl;
		return 1;
	}

	Window window;

	if (!window.create_window("Test window", Vec2(800, 600))) {
		SDL_Quit();
		return 2;
	}

	Input input;
	input.add_key(SDLK_q);

	SDL_Event event;

	bool quit = false;

	while (!quit) {

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				input.set_key(event.key.keysym.sym, true);
				break;
			case SDL_KEYUP:
				input.set_key(event.key.keysym.sym, false);
				break;
			}
		}

		if (input.get_key(SDLK_q)) {
			quit = true;
		}

	}

	window.destroy_window();
	SDL_Quit();

}
