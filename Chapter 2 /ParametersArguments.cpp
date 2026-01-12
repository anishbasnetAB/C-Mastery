#include <iostream>

int getIntFromUser(const char* prompt)
{
    std::cout<<prompt;
    int userInput{};
    std::cin>>userInput;
    return userInput;
}

int add(int x, int y)
{
    return x+y;
}

int multiply(int x,int y)
{
    return x*y;
}

void printResult(int value)
{
    std::cout<<value;    
}

void debugPrint(int /*unused parameter*/);

int main()
{
    int a =getIntFromUser("Enter first Integer\n");
    int b =getIntFromUser("Enter second Integer \n");

    printResult(add(a,b));

    // debugPrint(a);
    
}