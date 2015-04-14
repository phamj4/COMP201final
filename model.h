#ifndef _MODEL_H
#define _MODEL_H

#include <string>

enum Direction { UP, DOWN, LEFT, RIGHT };

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
    // TODO: Put your stuff here
	void type(unsigned int time, char letter);
private:
	std::string secret;
	std::string visible;
	int guesses;
	int wrongGuesses;
};

#endif