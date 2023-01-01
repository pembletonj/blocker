#pragma once

int clamp(int value, int min, int max);
SDL_Colour colour4(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
SDL_Colour colour3(Uint8 r, Uint8 g, Uint8 b);
int random_int(int min, int max);
double random_double(double min, double max);
bool random_bool(double chance);