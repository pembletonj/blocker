#include <cstdlib>
#include <SDL2/SDL.h>
#include "game_utils.hpp"

int clamp(int value, int min, int max) {
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}

SDL_Colour colour4(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    return SDL_Colour {
        .r = r,
        .g = g,
        .b = b,
        .a = a
    };
}

SDL_Colour colour3(Uint8 r, Uint8 g, Uint8 b) {
    return colour4(r, g, b, 255);
}

int random_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}

double random_double(double min, double max) {
    double fraction = (double) rand() / RAND_MAX;
    return min + (fraction * (max - min));
}