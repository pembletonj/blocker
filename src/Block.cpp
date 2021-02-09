
#include "Block.hpp"
#include <SDL2/SDL.h>
#include <SDL_render.h>



bool Block::is_alive() {
	return alive;
}



bool Block::intersects(Block *other) {

	SDL_Rect other_area = other->get_area();
	return SDL_IntersectRect(&area, &other_area, NULL);

}

SDL_Rect Block::get_area() {
	return area;
}



void Block::render(SDL_Renderer *renderer, double interpolation) {

	SDL_Rect real_area = area;

	real_area.x += interpolation * velocity.x;
	real_area.y += interpolation * velocity.y;

	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderFillRect(renderer, &real_area);

}



void Block::update_position() {

	area.x += velocity.x;
	area.y += velocity.y;

}
