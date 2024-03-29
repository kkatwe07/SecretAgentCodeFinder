#include <iostream>

// Global variable
int RandomNo = 5;

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty + 1;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % RandomNo;
    const int CodeB = rand() % RandomNo;
    const int CodeC = rand() % RandomNo;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;
    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 0;

    while (LevelDifficulty != 5) // Loop game until all levels completed
    {
        ++RandomNo;
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer
        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
} 