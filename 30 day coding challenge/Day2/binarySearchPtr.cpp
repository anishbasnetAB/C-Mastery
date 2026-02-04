// Task: Implement binary search using ONLY pointer arithmetic (no array indexing with []).
// Function signature:
// int* binary_search(int* left, int* right, int target)
// Requirements:

// Return pointer to found element, or nullptr if not found
// Use pointer arithmetic to calculate middle
// Use (right - left) / 2 logic, not (left + right) / 2
// No array indexing - only pointer dereferencing
#include <stdio.h>

// Binary search using ONLY pointer arithmetic
int* binary_search(int* left, int* right, int target)
{
    while (left <= right) {
        // Calculate middle pointer
        int* mid = left + (right - left) / 2;
        
        // Check if target is at mid
        if (*mid == target) {
            return mid;  // Found! Return pointer to element
        }
        
        // If target is greater, search right half
        if (*mid < target) {
            left = mid + 1;
        }
        // If target is smaller, search left half
        else {
            right = mid - 1;
        }
    }
    
    // Not found
    return nullptr;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = 10;
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Test 1: Find 7 (exists in middle)
    printf("=== Test 1: Search for 7 ===\n");
    int* result = binary_search(arr, arr + size - 1, 7);
    if (result != nullptr) {
        printf("Found 7 at address %p, value: %d\n", (void*)result, *result);
        printf("Index in array: %ld\n", result - arr);  // Pointer arithmetic to get index
    } else {
        printf("7 not found\n");
    }
    
    // Test 2: Find 19 (last element)
    printf("\n=== Test 2: Search for 19 ===\n");
    result = binary_search(arr, arr + size - 1, 19);
    if (result != nullptr) {
        printf("Found 19 at address %p, value: %d\n", (void*)result, *result);
        printf("Index in array: %ld\n", result - arr);
    } else {
        printf("19 not found\n");
    }
    
    // Test 3: Find 1 (first element)
    printf("\n=== Test 3: Search for 1 ===\n");
    result = binary_search(arr, arr + size - 1, 1);
    if (result != nullptr) {
        printf("Found 1 at address %p, value: %d\n", (void*)result, *result);
        printf("Index in array: %ld\n", result - arr);
    } else {
        printf("1 not found\n");
    }
    
    // Test 4: Find 8 (doesn't exist)
    printf("\n=== Test 4: Search for 8 ===\n");
    result = binary_search(arr, arr + size - 1, 8);
    if (result != nullptr) {
        printf("Found 8 at address %p, value: %d\n", (void*)result, *result);
        printf("Index in array: %ld\n", result - arr);
    } else {
        printf("8 not found\n");
    }
    
    // Test 5: Find 25 (larger than all elements)
    printf("\n=== Test 5: Search for 25 ===\n");
    result = binary_search(arr, arr + size - 1, 25);
    if (result != nullptr) {
        printf("Found 25 at address %p, value: %d\n", (void*)result, *result);
        printf("Index in array: %ld\n", result - arr);
    } else {
        printf("25 not found\n");
    }
    
    // Test 6: Find 0 (smaller than all elements)
    printf("\n=== Test 6: Search for 0 ===\n");
    result = binary_search(arr, arr + size - 1, 0);
    if (result != nullptr) {
        printf("Found 0 at address %p, value: %d\n", (void*)result, *result);
        printf("Index in array: %ld\n", result - arr);
    } else {
        printf("0 not found\n");
    }
    
    return 0;
}