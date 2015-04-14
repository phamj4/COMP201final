#include "view.h"	

using namespace std;

// Initialize SDL
View::View(string title, int width, int height) {
	fail = false;
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		fail = true;
		return;
	}
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		fail = true;
		return;
	}
	// Get the screen
	screen = SDL_GetWindowSurface(window);
	//Initialize JPEG and PNG loading
	if (!(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) & (IMG_INIT_JPG | IMG_INIT_PNG))) {
		fail = true;
		return;
	}
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		fail = true;
		return;
	}

	// Initialize True type fonts
	if (TTF_Init() == -1) {
		return;
	}
	// Load assets
	Stand = load("assets/Stand.jpg");
	StandBody = load("assets/Standbody.jpg");
	StandLeftArm = load("assets/StandLeftArm.jpg");
	StandRightArm = load("assets/StandRightArm.jpg");
	StandLeftLeg = load("assets/StandLeftLeg.jpg");
	StandRightLeg = load("assets/StandRightLeg.jpg");
	//    music = Mix_LoadMUS("assets/2Inventions_-_Johaness_Gilther_-_Don_t_leave_me.mp3");
	//    if (music != NULL) {
	//       Mix_PlayMusic( music, -1 );
	//    }
	//    food = Mix_LoadWAV("assets/yummy.wav");
	font = TTF_OpenFont("assets/LiberationSans-Regular.ttf", 28);

}

View::~View() {
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

/**
*  Load an image from a file to a SDL_Surface
*/
SDL_Surface* View::load(char * path) {
	// Load image
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL) {
		return NULL;
	}
	// Convert surface to screen format
	optimizedSurface = SDL_ConvertSurface(loadedSurface, screen->format, 0);

	// Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);

	return optimizedSurface;
}

void View::show(Model * model) {

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,
		0xff, 0xff, 0xff));

	SDL_Rect dest;
	dest.x = 30;
	dest.y = 30;

	SDL_Rect dest2;
	dest2.x = 30;
	dest2.y = 30;

	SDL_Rect dest3;
	dest3.x = 30;
	dest3.y = 30;
	
	SDL_Rect dest4;
	dest4.x = 30;
	dest4.y = 30;

	SDL_Rect dest5;
	dest5.x = 30;
	dest5.y = 30;

	SDL_Rect dest6;
	dest6.x = 30;
	dest6.y = 30;

	SDL_SetColorKey(Stand, SDL_TRUE, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(Stand, NULL, screen, &dest);
	SDL_SetColorKey(StandBody, SDL_TRUE, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(StandBody, NULL, screen, &dest2);
	SDL_SetColorKey(StandLeftArm, SDL_TRUE, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(StandLeftArm, NULL, screen, &dest3);
	SDL_SetColorKey(StandRightArm, SDL_TRUE, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(StandRightArm, NULL, screen, &dest4);
	SDL_SetColorKey(StandLeftLeg, SDL_TRUE, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(StandLeftLeg, NULL, screen, &dest5);
	SDL_SetColorKey(StandRightLeg, SDL_TRUE, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(StandRightLeg, NULL, screen, &dest6);
	


	// Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)

	SDL_UpdateWindowSurface(window);
}