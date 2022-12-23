
#include <map>
#include <SDL2/SDL.h>

#include "key_states.hpp"

bool KeyStates::get(SDL_Keycode keycode) {
    return keys[keycode];
}

void KeyStates::set(SDL_Keycode keycode, bool state) {
    keys[keycode] = state;
}