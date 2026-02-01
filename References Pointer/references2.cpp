//swapping values using references

#include <iostream>

// Write your swap function here
void swap(int& x, int& y)
{
    int temp{x};
    x=y;
    y=temp;
}

int main()
{
    int x { 5 };
    int y { 10 };
    
    std::cout << "Before swap: x=" << x << " y=" << y << '\n';
    
    swap(x, y);
    
    std::cout << "After swap: x=" << x << " y=" << y << '\n';
    
    return 0;
}