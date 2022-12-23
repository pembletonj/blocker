#pragma once

#include "key_states.hpp"
#include "player.hpp"

struct GameData {
    KeyStates keys;
    int screen_width;
    int screen_height;
    Player *player;
};