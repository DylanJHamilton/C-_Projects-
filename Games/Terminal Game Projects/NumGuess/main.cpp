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
	bool outOfGuesses = false;

	//Loop to run the game
		do
		{
			if (guessCount < guessLimit) { //condition that takes the guessCount is less than the guessLimit, the game will run
				StartMessage();
				cout << "Enter The Guess: \n";
				cin >> guess;
				guessCount++;

				if (guessCount == 1) {
					cout << "Here is a couple of hints, the sum of the number is: " << secretSum << ".\n";
					cout << "The Product of this number is: " << secretProduct << ".\n";
				}
				if (guessCount == 2) {
					cout << "Here is another couple of hints, the sum of the number is: " << secretSum << ".\n";
					cout << "The Product of this number is: " << secretProduct << ".\n";
					cout << "The number divided by 2 is: " << secretByTwo << ".\n";
				}
			}
			else {
				outOfGuesses = true;

	
			}
		} while (secretNumber != guess && !outOfGuesses);

	//Checks to see if user won the game. If outOfGuesses is true, then you lose, if not congrats, you win!
	if (outOfGuesses == true) {
		cout << "You are going to have to think harder than that!\n";
	}
	else {
		cout << "You win the game! \n";
	}
}