// Write a function that swaps two integers using pointers.
#include <iostream>

void swap(int* a, int* b) {
    // Your code here
    int temp = *a;
    *a=*b;
    *b=temp;
}

// Test
int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    std::cout << x << " " << y;  // Should print: 10 5
    return 0;
}