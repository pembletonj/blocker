#include <list>

#include "player.hpp"
#include "game_data.hpp"
#include "game_utils.hpp"

void Player::init(GameData *data) {
    size = 50;
    x = (data->screen_width / 2) - (size / 2);
    y = (data->screen_height / 2) - (size / 2);
    max_health = 100;
    health = 100;
    speed = 0.2;
    colour = colour3(255, 255, 255);
    init_block(data);
}

bool Player::update(int dt, GameData *data) {

    // Handle user input

    int vx = 0;
    if (data->keys.get(SDLK_LEFT)) {
        vx--;
    }
    if (data->keys.get(SDLK_RIGHT)) {
        vx++;
    }

    int vy = 0;
    if (data->keys.get(SDLK_UP)) {
        vy--;
    }
    if (data->keys.get(SDLK_DOWN)) {
        vy++;
    }

    // Make desired movements

    x += vx * dt * speed;
    y += vy * dt * speed;

    // For render interpolation
    dx = vx * speed;
    dy = vy * speed;

    // Hit any enemies?

    colour = colour3(255, 255, 255);
    SDL_Rect playerRect = get_rect();

    for (auto it = data->enemies.begin(); it != data->enemies.end(); it++) {
        SDL_Rect enemyRect = (*it)->get_rect();
        if (SDL_HasIntersection(&playerRect, &enemyRect)) {
            colour = colour3(255, 255, 0);
            break;
        }
    }

    update_block(dt, data);

    return true;
}