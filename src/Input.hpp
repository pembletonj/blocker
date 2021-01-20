
#pragma once

#include "Vec2.hpp"
#include <SDL2/SDL.h>
#include <SDL_keycode.h>
#include <map>



class Input {
public:
	void set_mouse_pos(Vec2 pos);
	Vec2 get_mouse_pos();
	bool mouse_down();
	void set_mouse(bool down);

	void add_key(SDL_Keycode key);
	void remove_key(SDL_Keycode key);

	bool listening_for_key(SDL_Keycode key);
	void set_key(SDL_Keycode key, bool down);
	bool get_key(SDL_Keycode key);

private:

	bool mouse_is_down;
	Vec2 mouse_pos;

	std::map<SDL_Keycode, bool> keys;

};
