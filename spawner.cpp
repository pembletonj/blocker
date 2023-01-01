#include "spawner.hpp"
#include "game_data.hpp"
#include "game_utils.hpp"
#include "enemy.hpp"

void try_spawn(double chance, GameData *data) {
    if (random_bool(chance) && data->enemies.size() < 15) {
        Enemy *enemy = new Enemy();
        enemy->init(data);
        data->enemies.insert(enemy);
    }
}