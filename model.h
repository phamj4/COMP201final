#ifndef _MODEL_H
#define _MODEL_H

#include <string>
#include <vector>

const int MAX_GUESSES = 6;

// The model manages the state of the game
class Model {
public:
	// Constructor (instantiates object)
	Model();
	// Destructor deletes all dynamically allocated stuff
	~Model();
	// Is the game over?
	bool gameOver();
	std::string getVisible();
	std::string getUsed();

	// TODO: Put your stuff here
	void type(char letter);
	bool won();
	bool lost();
	bool matched();
	int hangmanProgress();
private:
	char lastGuess;
	// The secret word
	std::string secret;
	// What the user sees
	std::string visible;
	// What letters have been used
	std::string used;
	// The dictionary
	std::vector<std::string> wordList;
	// How many wrong guesses have been made
	int wrongGuesses = 0;
};

#endif