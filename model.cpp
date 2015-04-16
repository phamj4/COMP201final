#include "model.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Constructor initializes the object
Model::Model() {
	srand(time(NULL));
	// read in assets/dictionary.txt and pick a random word
	ifstream readFile;
	readFile.open("assets/dictionary.txt");
	string word;
	while (readFile >> word) {
		wordList.push_back(word);
	}
	secret = wordList[rand() % wordList.size()];
	visible = "";
	for (int i = 0; i < secret.length(); i++) {
		visible += '-';
	}
	used = "";
}
// Destructor deletes dynamically allocated memory
Model::~Model() {

}

string Model::getVisible() {
	return visible;
}

string Model::getUsed() {
	return used;
}


bool Model::won() {
	return secret == visible;
}

bool Model::lost() {
	return wrongGuesses == MAX_GUESSES;
}

bool Model::gameOver() {
	return won() || lost();
}

int Model::hangmanProgress() {
	return wrongGuesses;
}

// keep score (figure out if the letter is in the string
bool Model::matched() 
{
	return (secret.find(lastGuess) != string::npos);
}
// Make a guess
void Model::type(char letter) {
	lastGuess = letter;
	// Good guess
	if (matched()) {
		for (int i = 0; i < secret.length(); i++) {
			if (secret[i] == lastGuess) {
				// Tell visible at location "I" is the lastGuess
				visible[i] = lastGuess;
			}
		}
	}
	// Bad guess
	else {
		used += lastGuess;
		wrongGuesses ++;
	}
}
