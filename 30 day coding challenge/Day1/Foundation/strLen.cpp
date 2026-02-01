// Task: Write a function my_strlen() that takes a C-style string and returns its length (not counting the null terminator).
// Requirements:

// Function signature: int my_strlen(const char* str)
// Use pointer arithmetic to traverse the string
// Count characters until you hit '\0'
// Return the count
// Test with "hello" (should return 5) and "C++" (should return 3)

#include <iostream>

int my_strlen(const char* str)
{
    const char* ptrStr = str;  // Start at beginning of string
    int count = 0;              // Initialize counter
    
    // Loop until we hit null terminator '\0'
    while (*ptrStr != '\0') {
        count++;                // Count this character
        ptrStr++;               // Move to next character
    }
    
    return count;               // Return total count
}

int main()
{
    // Test case 1: "Hello" should return 5
    int length1 = my_strlen("Hello");
    std::cout << "Length of 'Hello': " << length1 << "\n";
    
    // Test case 2: "C++" should return 3
    int length2 = my_strlen("C++");
    std::cout << "Length of 'C++': " << length2 << "\n";
    
    // Additional test cases
    std::cout << "Length of 'World': " << my_strlen("World") << "\n";
    std::cout << "Length of '': " << my_strlen("") << "\n";  // Empty string = 0
    
    return 0;
}