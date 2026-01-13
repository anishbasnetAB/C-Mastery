#include "input.h"
#include <iostream>
#include <string>
#include <limits>

double getPositiveDouble(const std::string& prompt)
{
    double value{};
    
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        
        // Guard clause: handle invalid input
        if (std::cin.fail() || value <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid. Must be positive.\n";
            continue;
        }
        
        // Valid input: clean buffer and return
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

int getIntegerInRange(const std::string& prompt, int min, int max)
{
    int value{};
    
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        
        // Guard clause: handle invalid input
        if (std::cin.fail() || value < min || value > max)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid. Enter " << min << "-" << max << ".\n";
            continue;
        }
        
        // Valid input: clean buffer and return
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

std::string getStockSymbol(const std::string& prompt)
{
    std::cout << prompt;
    std::string symbol;
    std::getline(std::cin, symbol);
    return symbol;
}