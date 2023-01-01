#pragma once

#include <unordered_set>
#include <memory>

#include "key_states.hpp"
#include "player.hpp"
#include "hud.hpp"
#include "enemy.hpp"

struct GameData {
    KeyStates keys;
    int screen_width;
    int screen_height;
    std::unique_ptr<Player> player;
    std::unique_ptr<Hud> hud;
    std::unordered_set<Enemy*> enemies;
};