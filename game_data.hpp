#pragma once

#include <unordered_set>

#include "key_states.hpp"
#include "player.hpp"
#include "enemy.hpp"

struct GameData {
    KeyStates keys;
    int screen_width;
    int screen_height;
    Player *player;
    std::unordered_set<Enemy*> enemies;
};