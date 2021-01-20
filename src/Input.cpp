
#include "Input.hpp"



void Input::set_mouse_pos(Vec2 pos) {
	mouse_pos = pos;
}

Vec2 Input::get_mouse_pos() {
	return mouse_pos;
}

bool Input::mouse_down() {
	return mouse_is_down;
}

void Input::set_mouse(bool down) {
	mouse_is_down = down;
}



void Input::add_key(SDL_Keycode key) {
	keys.insert(std::pair<SDL_Keycode, bool>(key, false));
}

void Input::remove_key(SDL_Keycode key) {
	keys.erase(key);
}



bool Input::listening_for_key(SDL_Keycode key) {
	return keys.find(key) != keys.end();
}

bool Input::get_key(SDL_Keycode key) {
	if (listening_for_key(key)) {
		return keys[key];
	}
	else {
		return false;
	}
}

void Input::set_key(SDL_Keycode key, bool down) {
	if (listening_for_key(key)) {
		keys[key] = down;
	}
}
