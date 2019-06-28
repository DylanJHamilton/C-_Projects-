#include <iostream>
#include <string>

using namespace std; //Including standard library 

void StartMessage();
void PlayGame();
string PlayerGuess();
bool PlayAgain();

//Main Point of the Application
int main() 
{
	
	//Function Calls 
	StartMessage();
	PlayGame();
	cout << PlayAgain();
	return 0;
}

//Main Message of the Application 
void StartMessage()
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls & Cows!\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	//loop to run the game
	constexpr int NumberOfTurns = 5;
	for (int i = 1; i <= NumberOfTurns; i++) {
		PlayerGuess();
		cout << endl;
	}
}


string PlayerGuess()
{
	//Get Player Guess
	cout << "What is your guess?";
	string Guess = "";
	getline(cin, Guess);
	cin >> Guess;

	//Repeat the guess back to the Player
	cout << "Your Guess was: " << Guess << endl;
}


bool PlayAgain() 
{
	cout << "Would you like to play again?";
	string Response = "";
	getline(cin, Response);

	cout << "Is it y? " << (Response[0] == 'y') || (Response[0] == 'Y');
	return false;
}