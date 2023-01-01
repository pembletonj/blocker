#include <list>

#include "enemy.hpp"
#include "game_data.hpp"
#include "game_utils.hpp"

void Enemy::init(GameData *data) {
    size = 20;
    max_age = 60000;
    age = 0;

    int edge_pos = random_int(0, (2 * data->screen_height) + (2 * data->screen_width) - 1);

    x = x_from_edge_pos(edge_pos, data->screen_width, data->screen_height);
    y = y_from_edge_pos(edge_pos, data->screen_width, data->screen_height);
    dx = random_double(0.0, 0.3);
    dy = random_double(0.0, 0.3);
    colour = colour3(255, 0, 0);

    init_block(data);
}

bool Enemy::update(int dt, GameData *data) {

    // Make desired movements

    x += dx * dt;
    y += dy * dt;

    // Handle bouncing

    if (x < 0 || x > data->screen_width - size) {
        dx *= -1;
    }

    if (y < 0 || y > data->screen_height - size) {
        dy *= -1;
    }

    update_block(dt, data);

    age += dt;
    return age < max_age;
}

int Enemy::x_from_edge_pos(int edge, int w, int h) {
    // Top
    if (edge < w) {
        return edge;
    }

    // Right
    if (edge < w + h) {
        return w;
    }

    // Bottom
    if (edge < (2 * w) + h) {
        return edge - w - h;
    }

    // Left
    return 0;
}

int Enemy::y_from_edge_pos(int edge, int w, int h) {
    // Top
    if (edge < w) {
        return 0;
    }

    // Right
    if (edge < w + h) {
        return edge - w;
    }

    // Bottom
    if (edge < (2 * w) + h) {
        return h;
    }

    // Left
    return edge - (2 * w) - h;
}