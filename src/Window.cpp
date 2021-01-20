
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <iostream>



bool Window::create_window(std::string title, Vec2 size) {

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
	if (window != NULL) {
		SDL_DestroyWindow(window);
		window = NULL;
		renderer = NULL;
	}
}



SDL_Renderer* Window::get_renderer() {
	return renderer;
}

Vec2 Window::get_size() {
	return size;
}
