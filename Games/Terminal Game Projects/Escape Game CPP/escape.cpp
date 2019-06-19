#include <iostream>
#include <ctime>

//StartMessage Function
void StartMessage(int Difficulty)
{
    std::cout << "-----------------------------------------------------------------------------------------------------";
    std:: cout << "                                                      /\\     /\\    \n"
                         "                                               ||______||    \n"
                         "                                               || ^  ^ ||    \n"
                         "                                               \\| |  | |/    \n"
                         "                                                |______|     \n"
                         "              __                                |  __  |     \n"
                         "             /  \\       ________________________|_/  \\_|__   \n"
                         "            / ^^ \\     /=========================/ ^^ \\===|  \n"
                         "           /  []  \\   /=========================/  []  \\==|  \n"
                         "          /________\\ /=========================/________\\=|  \n"
                         "       *  |        |/==========================|        |=|  \n" 
                         "      *** | ^^  ^^ |---------------------------| ^^  ^^ |--  \n"
                         "     *****| []  [] |           _____           | []  [] | |  \n"
                         "    *******        |          /_____\\          |      * | |  \n"
                         "   *********^^  ^^ |  ^^  ^^  |  |  |  ^^  ^^  |     ***| |  \n"
                         "  ***********]  [] |  []  []  |  |  |  []  []  | ===***** |  \n"
                         " *************     |         @|__|__|@         |/ |*******|  \n"
                         "***************   ***********--=====--**********| *********  \n"
                         "***************___*********** |=====| **********|*********** \n"
                         " *************     ********* /=======\\ ******** | *********  \n";

    
    std::cout << "\n\nYou have been kidnapped and need to escape or its game over. Each room gets harder by a door level" << Difficulty;
    std::cout << "Okay, glad to hear you broke free. Now it is complicated, but I will help you get out. Simply just make sure you have the right ombination.\n";
    std::cout << "I'm a detective and I hacked into this system, but cannot get the combinations completely as they are encrypted, but I do have a couple hints to help you along the way.\n";
    std::cout << "Okay, are you ready now? You kind of have no choice anyways.\n\n";
}

//ReplayGame Function, Needs to be before PlayGame Because we need to call it when the Player Loses.
bool ReplayGame(int Difficulty)
{
	//This function asks the player if they would like to replay the game
	bool bPlayersChoice = true;
	char PlayerReplay = 0;
	
	std::cout << std::endl;
	std::cout << "		Would you like to play again? ";
	std::cin >> PlayerReplay;
	if ((PlayerReplay == 89) || (PlayerReplay == 121))
	{
		bPlayersChoice = true;
		Difficulty = 1;
	}
	else
	{
		bPlayersChoice = false;
	}

	return bPlayersChoice;
}

//PlayGame Function
bool PlayGame(int Difficulty, int MaxLevel)
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
    std::cout << "There are three numbers in the code for the door.\n";
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

        if(Difficulty != MaxLevel){
            std::cout << "\nLooks like there is another door. Lets crack this code! You can do it!";
        }
        return true;
    } 
    else{
        std::cout << "\nAre you there?";
        return false;

        ReplayGame(Difficulty);
    }
}

//Winner Function
void Winner(int Difficulty)
{
    std::cout << "\nYou made it! Our squad car is just down the street, we will get you home safe!";
    ReplayGame(Difficulty);
}

//Main Function
int main()
{
    srand(time(NULL)); //creates new random sequence based on time.

    int LevelDifficulty = 1;
    int const  MaxDifficulty = 12;

    while(LevelDifficulty <= MaxDifficulty) // loop game until all levels are completed
    {
    bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty);
    std::cin.clear(); //Clears errors
    std::cin.ignore(); //Discards buffering
    
        if (bLevelComplete)
        {
            ++LevelDifficulty; //increment level difficulty 
        }
    }   
    
    /*
    Calls Winner Dialogue, then option to replay using LevelDifficulty Params equaling to 1 to restart game. 
    Should player want to play again.
    */
    Winner(LevelDifficulty);
    
    return 0; 
  
}

