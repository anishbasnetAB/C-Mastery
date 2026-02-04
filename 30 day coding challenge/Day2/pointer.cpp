// Task: Write code demonstrating all 5 pointer const patterns and test what operations are allowed/forbidden.
// For each pattern, write:

// The declaration with initialization
// Try to modify the value through the pointer
// Try to reassign the pointer to a different address
// Document which operations compile and which don't

// Patterns to demonstrate:

// int* ptr
// int** pptr
// const int* ptr
// int* const ptr
// const int* const ptr
#include <iostream>

int ptrToInt(int* ptrInt) //int* ptr
{
    int demo{};
    //modify value
    *ptrInt=20;
    ptrInt=&demo;
    return 0;
}

int ptrToPtr(int* ptr)
{
    int** ptr2=&ptr;
    **ptr2 = 30;
    return 0;

}

int main()
{

    int test={10};  //pointer to int
    ptrToInt(&test);
    std::cout<<test<<"\n";

    ptrToPtr(&test); //pointer to pointer
    std::cout<<test<<"\n";

    return 0;
}