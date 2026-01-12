#include <iostream>
#include <limits>

double calculate(double a, double b, char op)
{
    double result{};
    switch(op)    // switch statement to perform respective calculation.
    {              
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if(b == 0) // making sure number won't be divided by 0
            {
                std::cout << "Number cannot be divided by zero\n";
                return 0;  // Return early to avoid undefined behavior
            }
            result = a / b;
            break;
        default:
            std::cout << "Invalid operator\n";
            break;
    }
    return result;
}

double getValidNumber()
{
    double number{};
    // Check if cin failed (non-numeric input)
    while(true)
    {
        std::cin >> number;
        if(std::cin.fail())
        {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input! Please enter a number: ";
        }
        else
        {
            break;
        }
    }
    return number;
}

int main()
{
    while(true) // loop runs until the user decides to end the program
    {
        char operation{};   // asking what operation user wants to perform
        std::cout << "Enter operator (+, -, *, /, q to quit): ";
        
        std::cin >> operation;
        while(operation != '+' && operation != '-' && operation != '*' // input validation
            && operation != '/' && operation != 'q')
        {
            std::cout << "Please only enter valid operator: ";
            std::cin >> operation;
        }
        
        if(operation == 'q') // if user wants to quit 
        {
            break;
        }
        else  // executes calculations
        {
            std::cout << "Enter first number: ";
            double firstNumber = getValidNumber();

            std::cout << "Enter second number: ";
            double secondNumber = getValidNumber();

            double answer = calculate(firstNumber, secondNumber, operation);
            std::cout << "Result: " << answer << "\n\n";
        }
    }
    return 0;
}