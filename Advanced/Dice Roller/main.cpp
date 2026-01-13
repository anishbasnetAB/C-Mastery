#include <iostream>
#include <random>

// Create RNG once, globally
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1, 6);

int rollDice()
{
    return dist(gen);
}

void playGame()
{
    std::cout << "========= DICE GAME SIMULATOR =========\n";
    std::cout << "First to win 3 rounds wins the game!\n\n";

    int userRoundWin = 0;
    int computerRoundWin = 0;

    for (int i = 1; i <= 5; i++)
    {
        // Check if someone already won
        if (userRoundWin == 3 || computerRoundWin == 3)
            break;

        std::cout << "========== Round " << i << " ==========\n";
        
        int userDice1 = rollDice();
        std::cout << "User roll 1: " << userDice1 << "\n";
        int userDice2 = rollDice();
        std::cout << "User roll 2: " << userDice2 << "\n";
        
        int computerDice1 = rollDice();
        std::cout << "Computer roll 1: " << computerDice1 << "\n";
        int computerDice2 = rollDice();
        std::cout << "Computer roll 2: " << computerDice2 << "\n";
        
        int userTotal = userDice1 + userDice2;
        int computerTotal = computerDice1 + computerDice2;

        std::cout << "User total: " << userTotal << " | Computer total: " << computerTotal << "\n";

        if (userTotal > computerTotal)
        {
            userRoundWin++;
            std::cout << "User wins this round!\n\n";
        }
        else if (computerTotal > userTotal)
        {
            computerRoundWin++;
            std::cout << "Computer wins this round!\n\n";
        }
        else
        {
            std::cout << "It's a tie! No points awarded.\n\n";
        }
    }

    std::cout << "========== FINAL SCORE ==========\n";
    std::cout << "User: " << userRoundWin << " | Computer: " << computerRoundWin << "\n";
    
    if (userRoundWin > computerRoundWin)
        std::cout << " User wins the game!\n";
    else if (computerRoundWin > userRoundWin)
        std::cout << " Computer wins the game!\n";
    else
        std::cout << "It's a draw!\n";
}

int main()
{
    playGame();
    return 0;
}