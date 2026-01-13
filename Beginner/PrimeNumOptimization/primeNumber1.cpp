#include <iostream>


bool isPrime(int num)
{
    if(num<2) return false;
    for(int i =2; i<num; i++)
    {
        if(num%i==0) return false; 
    }
    std::cout<<"Prime";
    return true;
}

int main() 
{
    int a{};
    std::cin>>a;
    std::cout<<isPrime(a);
    return 0;
}