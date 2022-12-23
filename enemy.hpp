#pragma once

#include <list>
#include <SDL2/SDL.h>

#include "block.hpp"

class Enemy : public Block {
public:
    void init(GameData *data);
    bool update(int dt, GameData *data);
private:

    static int x_from_edge_pos(int edge_pos, int w, int h);
    static int y_from_edge_pos(int edge_pos, int w, int h);

    double vx;
    double vy;
};