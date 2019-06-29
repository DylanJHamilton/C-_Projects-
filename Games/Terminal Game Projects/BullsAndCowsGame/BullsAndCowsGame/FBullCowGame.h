#pragma once
#include <string>
using int32 = int;

class FBullCowGame {
public: 
	FBullCowGame(); //constructor
	void Reset(); // Makes a more rich return value 
	int32 GetMaxAttempts() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string); //Make a more rich return value



private: 
	//Constructor Initializes Values
	int MyCurrentTry;
	int MyMaxTries;
};
