
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <SDL_render.h>
#include <iostream>


bool Window::initialized = false;



bool Window::init() {

	if (is_initialized()) {
		std::cerr << "E: SDL2 is already initialized." << std::endl;
		return false;
	}

	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "E: Failed to initialize SDL2: "  << SDL_GetError() << std::endl;
		return false;
	}

	initialized = true;
	return true;

}

void Window::quit() {

	if (!is_initialized()) {
		std::cerr << "E: Could not quit SDL2, it is not initialized." << std::endl;
	}

	SDL_Quit();

	initialized = false;

}

bool Window::is_initialized() {
	return initialized;
}



bool Window::create_window(std::string title, Vec2 size) {

	if (!is_initialized()) {
		std::cerr << "E: SDL2 must be initialized before a Window can be created." << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			size.x,
			size.y,
			NULL);

	if (window == NULL) {
		std::cerr << "E: Failed to create window: " << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		std::cerr << "E: Failed to create renderer: " << SDL_GetError() << std::endl;
		destroy_window();
		return false;
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	this->size = size;

	return true;

}

void Window::destroy_window() {

	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}

	if (window != NULL) {
		SDL_DestroyWindow(window);
		window = NULL;
	}
}



SDL_Renderer* Window::get_renderer() {
	return renderer;
}

Vec2 Window::get_size() {
	return size;
}
