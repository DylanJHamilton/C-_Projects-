#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>
using namespace std;

//Introduction to Game
void IntroMessage()
{
	cout << "Rock, Paper Scissors Time! Get to playing!\n";
	cout << "We all know the rules, but this time, you are playing the computer!\n";
}


int main()
{
	IntroMessage(); //Introduction call
	
	//Variable Declarations
	char setup; //used later for Player Replay Functionality
	int win = 0; //win tally
	int lose = 0; //loss tally
	int tie = 0; //tie tally

	//Run Loop to Start Game 
	do {
		//User Input
		int choice;
		cout << "Press 1 for rock, 2 for paper and 3 for scissors.";
		cin >> choice;

		//Computer Data
		int comChoice = rand() % 3 + 1;
		cout << "The computer chose: " << comChoice << endl;

		//Choice One
		if (choice == 1 && comChoice == 1) {
			cout << "Rock meets Rock its a tie!" << endl;
			tie++;
		}
		else if (choice == 1 && comChoice == 2) {
			cout << "Rock is covered by Paper the computer wins!." << endl;
			lose++;
		}
		else if (choice == 1 && comChoice == 3) {
			cout << "Rock crushes Scissors you win!" << endl;
			win++;
		}
		//Choice Two
		else if (choice == 2 && comChoice == 1) {
			cout << "Paper covers Rock you win!" << endl;
			win++;
		}
		else if (choice == 2 && comChoice == 2) {
			cout << "Paper meets Paper its a tie!" << endl;
			tie++;
		}
		else if (choice == 2 && comChoice == 3) {
			cout << "Paper is cut by Scissors the computer wins!" << endl;
			lose++;
		}
		//Choice Three
		else if (choice == 3 && comChoice == 1) {
			cout << "Scissors are crushed by Rock computer wins!" << endl;
			lose++;
		}
		else if (choice == 3 && comChoice == 2) {
			cout << "Scissors cuts Paper you win!" << endl;
			win++;
		}
		else if (choice == 3 && comChoice == 3) {
			cout << "Scissors meet Scissors its a tie!" << endl;
			tie++;
		}
		// quick error handling 
		else {
			cout << "You didn't select 1, 2, or 3" << endl;
		}

		cout << "Wins: " << win << endl;
		cout << "Ties:" << tie << endl;
		cout << "Losses:" << lose << endl;
		cout << "Would you like to play again? Y/N" << endl;
		cin >> setup;
		system("CLS");

	} while (setup == 'Y' || setup == 'y');
}