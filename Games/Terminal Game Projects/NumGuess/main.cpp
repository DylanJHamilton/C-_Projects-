#include <iostream> 
#include <string> 
using namespace std;
using FString = std::string;
using int32 = int;


int32 main()
{
 //Variable Declarations 
 int secretNumber = 43;
 int guess;
 int guessCount = 0;
 int guessLimit = 3;
 bool outOfGuesses = false;

//Loop to run the game
do
{
  if(guessCount < guessLimit){ //condition that takes the guessCount is less than the guessLimit, the game will run
  cout << "Enter The Guess: \n";
  cin >> guess;
  guessCount++;
  } else{
    outOfGuesses = true;
  }
} while(secretNumber != guess && !outOfGuesses);

//Checks to see if user won the game. If outOfGuesses is true, then you lose, if not congrats, you win!
if(outOfGuesses = true){
  cout << "You are going to have to think harder than that!\n";
}
cout << "You win the game! \n";


}