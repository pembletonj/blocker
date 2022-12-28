#include "hud.hpp"
#include "game_data.hpp"

void Hud::init(GameData *data) {
    health_percent = 1.0;
    last_health_percent = 1.0;
}

bool Hud::update(int dt, GameData *data) {
    last_health_percent = health_percent;
    health_percent = (double) data->player->get_health() / data->player->get_max_health();
    return true;
}

void Hud::render(int dt, SDL_Renderer *renderer, GameData *data) {

    SDL_Rect health_bar_outline = SDL_Rect {
        .x = 5,
        .y = 5,
        .w = 106,
        .h = 26
    };

    SDL_Rect health_bar = SDL_Rect {
        .x = 8,
        .y = 8,
        .w = (int) (100 * health_percent),
        .h = 20
    };

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
    SDL_RenderDrawRect(renderer, &health_bar_outline);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 100);
    SDL_RenderFillRect(renderer, &health_bar);

}