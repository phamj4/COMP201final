#ifndef _MODEL_H
#define _MODEL_H

#include <string>
#include <vector>

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
	void type(char letter);
private:
	char lastGuess;
	// The secret word
	std::string secret;
	// What the user sees
	std::string visible;
	// What letters have been used
	std::string guesses;
	// The dictionary
	std::vector<std::string> wordList;
	// How many wrong guesses have been made
	int wrongGuesses;
};

#endif