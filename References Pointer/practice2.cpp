//triple number using pointer
#include <iostream>

void triple(int* num) {
    // Your code here
    *num=*num*3;
}

// Test
int main() {
    int value = 7;
    triple(&value);
    std::cout << value;  // Should print: 21
    return 0;
}