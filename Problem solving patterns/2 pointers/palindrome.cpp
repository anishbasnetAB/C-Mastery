#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main()
{
    int number[5] = {1, 2, 3, 2, 1};
    int size = 5;
    
    if (isPalindrome(number, size)) {
        cout << "Array is a palindrome" << endl;
    } else {
        cout << "Array is not a palindrome" << endl;
    }
    
    // Test with non-palindrome
    int number2[5] = {1, 2, 3, 4, 5};
    if (isPalindrome(number2, 5)) {
        cout << "Array 2 is a palindrome" << endl;
    } else {
        cout << "Array 2 is not a palindrome" << endl;
    }
    
    return 0;
}