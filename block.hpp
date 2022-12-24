#pragma once

#include <list>
#include <SDL2/SDL.h>

#include "entity.hpp"

class Block : public Entity {
public:
    virtual void init(GameData *data);
    virtual void finish(GameData *data);
    virtual bool update(int dt, GameData *data);
    void render(int dt, SDL_Renderer *renderer, GameData *data);

    SDL_Rect get_rect();
protected:
    void init_block(GameData *data);
    void finish_block(GameData *data);
    void update_block(int dt, GameData *data);
    double dx;
    double dy;
    int x;
    int y;
    int size;
    SDL_Colour colour;
private:
    std::list<SDL_Rect> trail;
    int trail_max_len;
};