#pragma once

#include <list>
#include <SDL2/SDL.h>

#include "block.hpp"

class Player : public Block {
public:
    void init(GameData *data);
    bool update(int dt, GameData *data);
private:
    double speed;
    int health;
    int max_health;
};