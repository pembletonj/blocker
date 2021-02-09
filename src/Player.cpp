
#include "Player.hpp"
#include <SDL2/SDL.h>



void Player::update(Game *game) {

	Input* input = game->get_input();
	Vec2 screen_size = game->get_screen_size();

	handle_input(input);
	update_position();
	clamp_to_screen(screen_size);

}



void Player::spawn(Game *game) {

	Input* input = game->get_input();
	Vec2 screen_size = game->get_screen_size();

	input->add_key(SDLK_LEFT);
	input->add_key(SDLK_RIGHT);
	input->add_key(SDLK_UP);
	input->add_key(SDLK_DOWN);

	area.w = 64;
	area.h = 64;

	area.x = (screen_size.x - area.w) / 2;
	area.y = (screen_size.y - area.h) / 2;

	colour.r = 255;
	colour.g = 255;
	colour.b = 255;
	colour.a = 255;

	alive = true;

}

void Player::kill(Game *game) {

	Input* input = game->get_input();

	input->remove_key(SDLK_LEFT);
	input->remove_key(SDLK_RIGHT);
	input->remove_key(SDLK_UP);
	input->remove_key(SDLK_DOWN);
	
	alive = false;
}

void Player::set_max_velocity(int max_velocity) {
	this->max_velocity = max_velocity;
}



void Player::handle_input(Input* input) {

	velocity.x = 0;
	if (input->get_key(SDLK_LEFT)) {
		velocity.x -= max_velocity;
	}
	if (input->get_key(SDLK_RIGHT)) {
		velocity.x += max_velocity;
	}

	velocity.y = 0;
	if (input->get_key(SDLK_UP)) {
		velocity.y -= max_velocity;
	}
	if (input->get_key(SDLK_DOWN)) {
		velocity.y += max_velocity;
	}


}

void Player::clamp_to_screen(Vec2 screen_size) {

	if (area.x <= 0) {

		area.x = 0;

		if (velocity.x < 0) {
			velocity.x = 0;
		}

	}
	else if (area.x + area.w >= screen_size.x) {

		area.x = screen_size.x - area.w;

		if (velocity.x > 0) {
			velocity.x = 0;
		}

	}

	if (area.y <= 0) {

		area.y = 0;

		if (velocity.y < 0) {
			velocity.y = 0;
		}

	}
	if (area.y + area.h >= screen_size.y) {

		area.y = screen_size.y - area.h;

		if (velocity.y > 0) {
			velocity.y = 0;
		}

	}

}
