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
