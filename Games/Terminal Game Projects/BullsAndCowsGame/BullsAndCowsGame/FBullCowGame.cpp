#include "FBullCowGame.h"
using int32 = int;
using FString = std::string; 

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxAttempts() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD; 

	MyCurrentTry = 1;
	return;
}


bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//Increment the turn number 
	MyCurrentTry++;

	//Setup a return variable 
	FBullCowCount BullCowCount;


	//loop all letters in the guess and compare letters in the hidden word
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		//Compares letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++){
			if (Guess[i] == MyHiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					//increment cows 
					BullCowCount.Cows++;
				}
			}
		}
	}
	
	
	return BullCowCount;
}


