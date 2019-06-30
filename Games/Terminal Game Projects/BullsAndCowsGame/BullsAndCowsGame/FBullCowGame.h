#pragma once
#include <string>
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame {
public: 
	FBullCowGame(); //constructor
	void Reset(); // Makes a more rich return value 
	int32 GetMaxAttempts() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); //Make a more rich return value
	FBullCowCount SubmitGuess(FString);

private: 
	//Constructor Initializes Values
	int MyCurrentTry;
	int MyMaxTries;
	FString MyHiddenWord;
};
