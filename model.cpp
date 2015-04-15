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
void Model::type(char letter) {
	
}

bool Model::visible(){
	while (playerWrongGuesses != wrongGuesses || playerGuesses != 27)
	{

		cin << guess;

		if (guess != letter)
		{

			playerWrongGuesses++;
			playerGuesses++;
		}
		else
		{
			playerGuesses++;
		}
		
		if (playerWrongGuesses = 0) {
			Stand.visible = true;
		}
		if (playerWrongGuesses = 1) {
			Stand.visible = true
			StandHead.visible = true;
		}
		if (playerWrongGuesses = 2) {
			Stand.visible = true;
			StandHead.visible = true;
			StandBody.visible = true;
		}
		if (playerWrongGuesses = 3) {
			Stand.visible = true;
			StandHead.visible = true;
			StandBody.visible = true;
			StandLeftArm.visible = true;
		}
		if (playerWrongGuesses = 4) {
			Stand.visible = true;
			StandHead.visible = true;
			StandBody.visible = true;
			StandLeftArm.visible = true;
			StandRightArm.visbile = true;
		}
		if (playerWrongGuesses = 5) {
			Stand.visible = true;
			StandHead.visible = true;
			StandBody.visible = true;
			StandLeftArm.visible = true;
			StandRightArm.visible = true;
			StandLeftLeg.visible = true;
		}
		if (playerWrongGuesses = 6) {
			Stand.visible = true;
			StandHead.visible = true;
			StandBody.visible = true;
			StandLeftArm.visible = true;
			StandRightArm.visible = true;
			StandLeftLeg.visible = true;
		}
	}
	
}
