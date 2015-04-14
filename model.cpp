#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {
	// read in assets/dictionary.txt and pick a random word
	readFile.open("assets/dictionary.txt");

	while (getline(readFile, word)) {
		if (!word.empty())
			wordList.push_back(word);
	}
	word = wordList[0];
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return false;
}

// keep score (figure out if the letter is in the string
void Model::type(unsigned int time, char letter) {

}