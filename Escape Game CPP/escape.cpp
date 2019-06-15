#include <iostream>
#include <ctime>

//StartMessage Function
void StartMessage(int Difficulty)
{
    std::cout << "\n\nYou have been kidnapped and need to escape or its game over. Each room gets harder by a door level" << Difficulty;
    std::cout << "Okay, glad to hear you broke free. Now it is complicated, but I will help you get out. Simply just make sure you have the right ombination.\n";
    std::cout << "I'm a detective and I hacked into this system, but cannot get the combinations completely as they are encrypted, but I do have a couple hints to help you along the way.\n";
    std::cout << "Okay, are you ready now? You kind of have no choice anyways.\n\n";
}

//PlayGame Function
bool PlayGame(int Difficulty)
{
    //Call the StartMessage Function to deliver Introduction Message of the game.
    StartMessage(Difficulty);

    //Declare the 3 number code.
    const int NumOne = rand() % Difficulty + Difficulty;
    const int NumTwo = rand() % Difficulty + Difficulty;
    const int NumThree = rand() % Difficulty + Difficulty;

    const int NumSum = NumOne + NumTwo + NumThree;
    const int NumProduct = NumOne * NumTwo * NumThree;

    // Print the sum and product to the terminal.
    std::cout << std::endl;
    std::cout << "There are three numbers in the code for the door my dude.\n";
    std::cout << "\nThe codes adds up to: " << NumSum << std::endl;
    std::cout << "\nThe codes multiply to give: " << NumProduct << std::endl;

    //Storing the player guess
    int GuessA, GuessB, GuessC; 
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Adding conditional logic to determine victory or defeat!
    if(GuessSum == NumSum && GuessProduct == NumProduct){
        std::cout << "\nKeep going!";
        return true;
    } 
    else{
        std::cout << "\nAre you there?";
        return false;
    }
}

//Main Function
int main()
{
    srand(time(NULL)); //creates new random sequence based on time.

    int LevelDifficulty = 1;
    int const  MaxDifficulty = 12;

    while(LevelDifficulty <= MaxDifficulty) // loop game until all levels are completed
    {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); //Clears errors
    std::cin.ignore(); //Discards buffering
    
        if (bLevelComplete)
        {
            ++LevelDifficulty; //increment level difficulty 
        }
    }

    std::cout << "\nYou made it! Our squad car is just down the street, we will get you home safe!";
    return 0; 
}

