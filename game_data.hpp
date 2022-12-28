#pragma once

#include <unordered_set>

#include "key_states.hpp"
#include "player.hpp"
#include "hud.hpp"
#include "enemy.hpp"

struct GameData {
    KeyStates keys;
    int screen_width;
    int screen_height;
    Player *player;
    Hud *hud;
    std::unordered_set<Enemy*> enemies;
};