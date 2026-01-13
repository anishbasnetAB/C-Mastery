#include <iostream>
#include <limits>

// Centralized calculation function
double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                std::cout << "You cannot divide by 0.\n";
                return 0;
            }
            return a / b;
        default:
            return 0;
    }
}

// Safe number input function
double getValidNumber(const std::string& prompt) {
    double value;
    std::cout << prompt;

    while (!(std::cin >> value)) {
        std::cout << "Invalid number. Try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return value;
}

// Safe operator input function
char getValidOperator() {
    char op;
    std::cout << "Enter operation (+, -, *, /, X to exit): ";
    std::cin >> op;

    while (op != '+' && op != '-' && op != '*' && op != '/' &&
           op != 'x' && op != 'X') {
        std::cout << "Invalid operator. Try again: ";
        std::cin >> op;
    }

    return op;
}

int main() {
    bool program_run = true;

    while (program_run) {

        // Step 1: Get operator FIRST
        char input_operator = getValidOperator();

        // Exit immediately if user chooses X
        if (input_operator == 'x' || input_operator == 'X') {
            std::cout << "Exiting program...\n";
            program_run = false;
            break;
        }

        // Step 2: Get numbers only if not exiting
        double firstNum = getValidNumber("Enter First Number: ");
        double secondNum = getValidNumber("Enter Second Number: ");

        // Step 3: Calculate and display result
        double result = calculate(firstNum, secondNum, input_operator);
        std::cout << "Result: " << result << "\n\n";
    }

    return 0;
}
