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
FText PlayerGuess();
bool PlayAgain();

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
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls & Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxAttempts();
	int32 CurrentTry = BCGame.GetCurrentTry();
	//For Loop to run turns in game.
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = PlayerGuess();
	 
		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//prints number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows;



		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}


FText PlayerGuess()
{
	//Get Player Guess
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter Your Guess: ";
	FText Guess = "";
	getline(std::cin, Guess);
	return Guess;
}


bool PlayAgain() 
{
	std::cout << "Would you like to play again (y/n)?";
	FText Response = "";
	getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}