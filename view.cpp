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
    // Initialize True type fonts
    if( TTF_Init() == -1 ) {
        return;
    }
	// Load assets
	YouWin = load("assets/win.jpg");
	YouLose = load("assets/lose.jpg");
	hangman[0] = load("assets/Stand.jpg");
	hangman[1] = load("assets/StandHead.jpg");
	hangman[2] = load("assets/StandBody.jpg");
	hangman[3] = load("assets/StandLeftArm.jpg");
	hangman[4] = load("assets/StandRightArm.jpg");
	hangman[5] = load("assets/StandLeftLeg.jpg");
	hangman[6] = load("assets/StandRightLeg.jpg");
    font = TTF_OpenFont( "assets/LiberationSans-Regular.ttf", 28 );
}

View::~View() {
    TTF_CloseFont( font );
    TTF_Quit();
	for (int i = 0; i < 7; i++) {
		SDL_FreeSurface(hangman[i]);
	}
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

void View::showText(string text, int x, int y) {
	SDL_Color textColor = { 0, 0, 0 };
    this->text = TTF_RenderText_Solid( font, text.c_str(), textColor );
	SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_BlitSurface( this->text, NULL, screen, &dest );
	SDL_FreeSurface(this->text);
}

void View::show(Model * model) {

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,
		0xff, 0xff, 0xff));

	SDL_Rect dest;
	dest.x = 0;
	dest.y = 0;

	SDL_BlitSurface( hangman[model->hangmanProgress()], NULL, screen, &dest );
	
	showText(model->getVisible(), 100, 500);
	showText("You used: " + model->getUsed(), 100, 600);

	if (model->won()) 
	{
	SDL_BlitSurface( YouWin, NULL, screen, NULL ); 
	SDL_UpdateWindowSurface(window);
	SDL_Delay(500); 
	}
	 if (model->lost()) 
	 {
	SDL_BlitSurface( YouLose, NULL, screen, NULL); 
	SDL_UpdateWindowSurface(window);
	SDL_Delay(500); 
	 } 
	SDL_UpdateWindowSurface(window);
}

/*
// Show the model, one cell at a time
void View::show(Model * model) {
for (int j = 0; j < model->getWidth(); j++) {
cout << "\t" << j;
}
cout << endl;
for (int i = 0; i < model->getHeight(); i++) {
cout << i;
for (int j = 0; j < model->getWidth(); j++) {
cout << "\t" << model->get(i, j);
}
cout << endl;
}
}
*/