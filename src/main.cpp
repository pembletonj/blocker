
#include "Window.hpp"
#include "Vec2.hpp"
#include <SDL2/SDL.h>
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

	SDL_Delay(5000);

	window.destroy_window();
	SDL_Quit();

}
