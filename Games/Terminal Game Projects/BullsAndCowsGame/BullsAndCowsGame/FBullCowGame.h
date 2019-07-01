#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK, 
	Not_Isogram, 
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public: 
	FBullCowGame(); //constructor
	void Reset(); // Makes a more rich return value 
	int32 GetMaxAttempts() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
	bool GameIsWon() const;
	EGuessStatus CheckGuessValidity(FString) const; //Make a more rich return value
	FBullCowCount SubmitValidGuess(FString);

private: 
	//Constructor Initializes Values
	int MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
};
