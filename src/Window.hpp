
#pragma once

#include "Vec2.hpp"
#include <SDL2/SDL.h>
#include <string>



class Window {
public:

	bool create_window(std::string title, Vec2 size);
	void destroy_window();

	SDL_Renderer* get_renderer();
	Vec2 get_size();

private:

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	Vec2 size;

};
