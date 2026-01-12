#include <iostream>
#include <random>

int inputValidation()
{
    int input{};
    
    while(true)
    {
        std::cout << "Enter a number (0-100): ";
        std::cin >> input;
        
        // Check if cin failed (non-numeric input)
        if(std::cin.fail())
        {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(10000, '\n'); // Discard invalid input
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        // Check if number is in valid range
        if(input < 0 || input > 100)
        {
            std::cout << "Invalid input! Should be between 0-100.\n";
        }
        else
        {
            break; // Valid input, exit loop
        }
    }
    
    return input;
}

int generateRandom()
{
    std::random_device rd; //create a random device(uses hardware if availabe)

    std::mt19937 gen(rd()); //create a mersenne twister generator, seeded with random_device

    std::uniform_int_distribution<> dist(0,100); // Create a distribution for integers from 0 to 100

    int randomNum = dist(gen); //generate a random number

    return randomNum;
}


int game()
{

    std::cout<<"You get 7 attempts to guess the correct number. (0 to 100) \n";
    int numberOfAttempts = 7;
    int targetValue={generateRandom()};

    while (numberOfAttempts>0)
    {
        std::cout<<"Enter your guess. \n";
        int userGuess = {inputValidation()};
        if(userGuess == targetValue)
        {
            std::cout<<"Congratulations, you got it right in "<<(7 - numberOfAttempts + 1)<<"\n";
            break;
        }
        else 
        if(userGuess < targetValue)
        {
            std::cout << "Too low! Try a higher number.\n";
        }
        else
        {
            std::cout << "Too high! Try a lower number.\n";
        }
        numberOfAttempts--;
    }
    std::cout<<"Correct number is "<<targetValue;
    return 0;
}


int main()
{
    while(true)
    {
        game();
        
        std::cout << "\nDo you want to play again? (Y/N): ";
        char userChoice;
        std::cin >> userChoice;  // Actually read input
        
        if(userChoice == 'n' || userChoice == 'N')
        {
            std::cout << "Thanks for playing!\n";
            break;
        }
        else if(userChoice == 'y' || userChoice == 'Y')
        {
            continue;  // Play again
        }
        else
        {
            std::cout << "Invalid input. Exiting...\n";
            break;
        }
    }
    return 0;
}