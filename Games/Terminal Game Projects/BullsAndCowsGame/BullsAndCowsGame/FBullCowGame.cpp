#include "FBullCowGame.h"
#pragma once

#include <map>
#define Tmap std::map

using int32 = int;
using FString = std::string; 

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }

int32 FBullCowGame::GetMaxAttempts() const {
	Tmap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

//GameIsWon Method
bool FBullCowGame::GameIsWon() const {
	return bGameIsWon;
}

//Reset Method
void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "harambe";
	MyHiddenWord = HIDDEN_WORD; 
	bGameIsWon = false;
	MyCurrentTry = 1;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (!IsIsogram(Guess)){
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	} 
	else {
		return EGuessStatus::OK;
	}
	
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//Increment the turn number 
	MyCurrentTry++;

	//Setup a return variable 
	FBullCowCount BullCowCount;


	//loop all letters in the guess and compare letters in the hidden word
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) {
		//Compares letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++){
			if (Guess[GChar] == MyHiddenWord[HWChar]) {
				if (HWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					//increment cows 
					BullCowCount.Cows++;
				}
			}
		}
	}
	
	if (BullCowCount.Bulls == HiddenWordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	Tmap<char, bool> LetterSeen; // setup our map
	for (auto Letter : Word) 	// for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) {// if the letter is in the map
			return false; // we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true;// add the letter to the map
		}
	}


	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) // if not a lowercase letter
		{
			return false;
		}
	}
	return true;
}