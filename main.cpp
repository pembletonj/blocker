#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>

#include "key_states.hpp"
#include "game_data.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char **argv) {

    srand(time(NULL));

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL." << std::endl << "SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Blocker v0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cerr << "Failed to create window." << std::endl << "SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // TODO: Switch to SDL_RENDERER_PRESENTVSYNC on supported platforms.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cerr << "Failed to create renderer." << std::endl << "SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }



    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    bool running = true;

    SDL_Event e;

    Uint64 time = 0;
    Uint64 prev_render_time = 0;
    Uint64 prev_update_time = 0;

    Uint32 prev_fps_time = 0;
    int frames = 0;
    int fps = 0;

    GameData data;
    data.screen_width = SCREEN_WIDTH;
    data.screen_height = SCREEN_HEIGHT;
    data.player = new Player();
    data.player->init(&data);

    Enemy *enemy = new Enemy();
    enemy->init(&data);
    data.enemies.insert(enemy);

    while (running) {

        time = SDL_GetTicks64();
        int render_dt = time - prev_render_time;
        int update_dt = time - prev_update_time;
        int fps_dt = time - prev_fps_time;

        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                data.keys.set(e.key.keysym.sym, true);
                break;
            case SDL_KEYUP:
                data.keys.set(e.key.keysym.sym, false);
                break;
            }
        }

        // Update

        if (update_dt > 50) {
            prev_update_time = time;
            data.player->update(update_dt, &data);
            for (auto it = data.enemies.begin(); it != data.enemies.end(); it++) {
                (*it)->update(update_dt, &data);
            }
        }

        // Render

        if (render_dt > 16) {
            prev_render_time = time;
            frames++;
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            data.player->render(time - prev_update_time, renderer, &data);
            for (auto it = data.enemies.begin(); it != data.enemies.end(); it++) {
                (*it)->render(time - prev_update_time, renderer, &data);
            }
            SDL_RenderPresent(renderer);
        }

        // FPS calculation

        if (fps_dt > 1000) {
            prev_fps_time = time;
            fps = frames;
            frames = 0;
            std::cout << "FPS: " << fps << std::endl;
        }
    }



    for (auto it = data.enemies.begin(); it != data.enemies.end(); it++) {
        delete *it;
    }

    data.player->finish(&data);
    delete data.player;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}