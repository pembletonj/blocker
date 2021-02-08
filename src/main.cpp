
#include "Game.hpp"
#include <SDL2/SDL.h>
#include <iostream>



int main(int argc, char* argv[]) {

	Window::init();

	Game game;
	game.launch();

	Window::quit();

	return 0;

}
