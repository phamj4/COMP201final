#include "controller.h"
#include <map>
#include <iostream>


using namespace std;
Controller::Controller() {
	cout << "model" << endl;
	model = new Model();
	cout << "view" << endl;
	view = new View("Game", 1024, 768);
}

Controller::~Controller() {
	delete model;
	delete view;
}
/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop() {
	SDL_Event e;
	unsigned int lastTime = 0, currentTime;
	std::map<SDL_Keycode, char> letter;

	letter[SDLK_a] = 'a';
	letter[SDLK_b] = 'b';
	letter[SDLK_c] = 'c';
	letter[SDLK_d] = 'd';
	letter[SDLK_e] = 'e';
	letter[SDLK_f] = 'f';
	letter[SDLK_g] = 'g';
	letter[SDLK_h] = 'h';
	letter[SDLK_i] = 'i';
	letter[SDLK_j] = 'j';
	letter[SDLK_k] = 'k';
	letter[SDLK_l] = 'l';
	letter[SDLK_m] = 'm';
	letter[SDLK_n] = 'n';
	letter[SDLK_o] = 'o';
	letter[SDLK_p] = 'p';
	letter[SDLK_q] = 'q';
	letter[SDLK_r] = 'r';
	letter[SDLK_s] = 's';
	letter[SDLK_t] = 't';
	letter[SDLK_u] = 'u';
	letter[SDLK_v] = 'v';
	letter[SDLK_w] = 'w';
	letter[SDLK_x] = 'x';
	letter[SDLK_y] = 'y';
	letter[SDLK_z] = 'z';
	letter[SDLK_BACKSPACE] = '\b';
	letter[SDLK_RETURN] = '\r';

	while (!model->gameOver()) {
		currentTime = SDL_GetTicks();

		view->show(model);
		if (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				return;
			case SDL_KEYDOWN:
				model->type(letter[e.key.keysym.sym]);
				break;
			}
		}
	}
	// TODO: show something nice?
	view->show(model);
	SDL_Delay(2000);
}