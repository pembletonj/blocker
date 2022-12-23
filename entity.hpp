#pragma once

#include <SDL2/SDL.h>

struct GameData;

class Entity {
public:
    virtual void init(GameData *data);
    virtual void finish(GameData *data);
    virtual bool update(int dt, GameData *data);
    virtual void render(int dt, SDL_Renderer *renderer, GameData *data);
};