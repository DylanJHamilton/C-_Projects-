#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
using double64 = double;
using float32 = float; 



//Function and Object Declarations
void StartMessage();
void PlayGame();
FText GetValidGuess();
bool PlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //Instantiate a new game (Global Access)


//Main Point of the Application
int32 main() 
{	
	bool PlayerWantsToPlayAgain = false;
	
	//Loop to run game 
	do {
		StartMessage(); //StartMessage Function Call
		PlayGame(); //PlayGame Function Call
		PlayerWantsToPlayAgain = PlayAgain(); //PlayAgain Function Call 
	} while(PlayerWantsToPlayAgain);
	return 0;
}

//Main Message of the Application 
void StartMessage()
{
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Welcome to Bulls & Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxAttempts();
	int32 CurrentTry = BCGame.GetCurrentTry();

	//loop to run game
		while (!BCGame.GameIsWon() && BCGame.GetCurrentTry() <= MaxTries) {

			FText Guess = GetValidGuess();

			// submit valid guess to the game
			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
			//prints number of bulls and cows
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << "Cows = " << BullCowCount.Cows;



			std::cout << "Your guess was: " << Guess << std::endl << "\n\n";
		}
}


FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
		do {
			//Get Player Guess
			int32 CurrentTry = BCGame.GetCurrentTry();
			std::cout << "Try " << CurrentTry << ". Enter Your Guess: ";
			FText Guess = "";
			std::getline(std::cin, Guess);

			EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
			switch (Status)
			{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters.\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter all lowercase letters\n";
				break;
			default:
				//assumes the guess is valid
				break;
			}
		} while (Status != EGuessStatus::OK);
		return Guess;
	
}


bool PlayAgain() 
{
	std::cout << "Would you like to play again (y/n)?";
	FText Response = "";
	getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.GameIsWon())
	{
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time, keep trying!\n";
	}
}