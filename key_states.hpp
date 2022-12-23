#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>

class KeyStates {
public:
    bool get(SDL_Keycode keycode);
    void set(SDL_Keycode keycode, bool state);
private:
    std::unordered_map<SDL_Keycode, bool> keys;
};