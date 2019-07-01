#include <iostream> 
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>


using namespace std;


void StartMessage()
{
	cout << "Hey there, I am thinking of a number, tell me what it is.\n";
}

bool ReplayGame(int guessCount)
{
	//This function asks the player if they would like to replay the game
	bool bPlayersChoice = true;
	char PlayerReplay = 0;
	std::string Response = "";
	
	std::cout << std::endl;
	std::cout << "Would you like to play again? Yy for Yes, Nn for No.";
	std::cin >> Response;
	if ((Response[0] == 'y') || (Response[0] == 'Y'))
	{
		bPlayersChoice = true;
		guessCount--; //we always want it at the last level for the user to get all of the hints
	}
	else
	{
		bPlayersChoice = false;
        std::cout << "Game Over\n";
        exit(0);
	}

	return bPlayersChoice;
}


int main()
{
	srand(time(NULL));
	//Variable Declarations 
	int secretNumber = rand();
	int secretSum = secretNumber + secretNumber;
	int secretProduct = secretNumber * secretNumber;
	int secretByTwo = secretNumber / 2;
	int guess;
	int guessCount = 0;
	int guessLimit = 3;

	StartMessage(); //StartMessage Call
	
	//Loop to run the game
	while (guessCount <= guessLimit)
	{
		cout << "Enter The Guess: \n";
		cin >> guess;

		if (guess == secretNumber) {
			cout << "You Win! Congrats!";
			ReplayGame(guessCount);
		} 
		else if(guess != secretNumber) {
			guessCount++;
		}

		if (guessCount == 1) {
			cout << "Here is a couple of hints, the sum of the number is: " << secretSum << ".\n";
			cout << "The Product of this number is: " << secretProduct << ".\n";
		}
		if (guessCount == 2) {
			cout << "Here is another couple of hints, the sum of the number is: " << secretSum << ".\n";
			cout << "The Product of this number is: " << secretProduct << ".\n";
			cout << "The number divided by 2 is: " << secretByTwo << ".\n";
		}
		if (guessCount == 3) {
			std::cout << "You lose!";
			ReplayGame(guessCount);
		}
	}


} 
