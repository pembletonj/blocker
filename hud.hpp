#pragma once

#include "entity.hpp"

class Hud : public Entity {
public:
    virtual void init(GameData *data);
    virtual bool update(int dt, GameData *data);
    virtual void render(int dt, SDL_Renderer *renderer, GameData *data);
private:
    double health_percent;
    double last_health_percent;
};