// Task: Given a sorted array of 9 integers, find and return the median value using pointer arithmetic.
// Requirements:

// Array: {1, 3, 5, 7, 9, 11, 13, 15, 17}
// Calculate middle position
// Access using pointer arithmetic only
// Return the median value
#include <iostream>

int main()
{
    int arr[9] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    
    int* ptrStart = arr;        // Points to first element
    int* ptrEnd = arr + 8;      // Points to last element
    
    // Move pointers toward center until they meet
    while (ptrStart < ptrEnd) {
        ptrStart++;  // Skip from left
        ptrEnd--;    // Skip from right
    }
    
    // When they meet, that's the median!
    std::cout << "Median using two-pointer: " << *ptrStart << "\n";
    
    return 0;
}