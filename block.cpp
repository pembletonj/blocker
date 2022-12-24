#include <list>

#include "block.hpp"
#include "game_data.hpp"
#include "game_utils.hpp"

void Block::init(GameData *data) {
    init_block(data);
}

void Block::finish(GameData *data) {
    finish_block(data);
}

bool Block::update(int dt, GameData *data) {
    update_block(dt, data);
    return true;
}

void Block::render(int dt, SDL_Renderer *renderer, GameData *data) {

    // Block

    SDL_Rect rect;
    rect.x = clamp(x + (dx * dt), 0, data->screen_width - size);
    rect.y = clamp(y + (dy * dt), 0, data->screen_height - size);
    rect.h = size;
    rect.w = size;
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rect);

    // Trail

    int da = 63 / trail_max_len;
    int alpha = 63;
    for (auto it = trail.begin(); it != trail.end(); it++) {
        SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a * (alpha / 255.0));
        SDL_RenderFillRect(renderer, &(*it));
        alpha -= da;
    }
}

SDL_Rect Block::get_rect() {
    return SDL_Rect {
        .x = x,
        .y = y,
        .w = size,
        .h = size
    };
}

void Block::init_block(GameData *data) {
    trail.clear();
    trail_max_len = 10;
}

void Block::finish_block(GameData *data) {
    trail.clear();
}

void Block::update_block(int dt, GameData *data) {

    // Keep in the bounds

    x = clamp(x, 0, data->screen_width - size);
    y = clamp(y, 0, data->screen_height - size);

    // Trail

    SDL_Rect rect = get_rect();

    trail.push_front(rect);
    if (trail.size() > trail_max_len) {
        trail.pop_back();
    }

}