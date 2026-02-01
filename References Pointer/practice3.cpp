//Given an array and its size, increment each element by 1 using pointers (no [] brackets allowed).

#include <iostream>
void incrementAll(int* arr, int size) {
    // Your code here - use pointer arithmetic only
    for(int i=0;i<=5;i++)
    {
        *(arr+i)=*(arr+i)+1;
    }
}

// Test
int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    incrementAll(numbers, 5);
    // numbers should now be {2, 3, 4, 5, 6}
    
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    return 0;
}