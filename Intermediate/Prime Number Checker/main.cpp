#include <iostream>

bool isPrime(int number)
{
    if(number<=1) return false;
    
    for(int i =2; i<=(number/2); i++) //logic: if no number less than or equal half of itself can divide equally. then it is prime.
    {
        if(number%i==0) return false ;
    }
    return true;
}

void printPrimesInRange(int start, int end)
{
    for(int a=start; a<=end; a++) 
    {
        if(isPrime(a)) std::cout<< a<<" is prime. \n";
    }
}

int main()
{
    printPrimesInRange(17,19);
    return 0;
}