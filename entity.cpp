#include "entity.hpp"

void Entity::init(GameData *data) {}

void Entity::finish(GameData *data) {}

bool Entity::update(int dt, GameData *data) {
    return true;
}

void Entity::render(int dt, SDL_Renderer *renderer, GameData *data) {}