#include <iostream>
int main()
{
    // INITIALIZATION: Reserve space for 4 integers on the stack
    // {} syntax = zero-initialization (all elements set to 0)
    // Memory layout: [0][0][0][0] stored contiguously
    int arr[4]={}; 
    
    // CRITICAL OBSERVATION #1: What is 'arr' really?
    // &arr gives address of the entire array object
    // Note: This will print same address as first element (but different type!)
    std::cout<<&arr<<'\n'; 
    
    // Verify all elements are zero-initialized
    for(int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    } 

    // ARRAY DECAY: When you assign array to pointer, it "decays"
    // arr (type: int[4]) → ptrArr (type: int*)
    // This decay happens automatically - arr loses its size information
    // ptrArr now points to first element, just like arr does
    int* ptrArr = arr; 
    
    // CRITICAL OBSERVATION #2: arr IS a pointer to first element
    // When you use 'arr' without subscript, it's treated as &arr[0]
    // This proves: arr == &arr[0] (same address value)
    std::cout<<arr<<'\n';

    // Dereferencing: ptrArr+0 is same as ptrArr (points to arr[0])
    // *(ptrArr+0) would give the VALUE at that address (which is 0)
    std::cout<<(ptrArr+0)<<'\n'; 

    // KEY INSIGHT: arr, ptrArr, &arr[0] all have SAME ADDRESS VALUE
    // BUT different types: int[4], int*, int* respectively
    // Type matters for sizeof() and pointer arithmetic rules

    // POINTER ARITHMETIC IN ACTION:
    // ptrArr+i doesn't add 'i' to address - it adds i*sizeof(int) bytes
    // If ptrArr = 0x1000, then ptrArr+1 = 0x1004 (assuming 4-byte ints)
    // This is why you can treat memory as "array of ints" instead of "array of bytes"
    std::cout<<"Printing addresses of each element:\n";
    for(int i=0; i<4;i++)
    {
        std::cout<<" Element "<<*(ptrArr+i)<<" = address = "<<(ptrArr+i)<<'\n'; // Watch addresses increment by sizeof(int)
    }

    //using ptrArr++ ptrArr--
    std::cout<<++ptrArr<<" ";
    std::cout<<++ptrArr<<" ";
    std::cout<<--ptrArr<<" ";
    // FUNDAMENTAL TRUTH REVEALED:
    // - Array is contiguous block: [int][int][int][int] in sequential memory
    // - Array name holds address of first element (arr == &arr[0])
    // - Rest of elements found by: base_address + (index * sizeof(element))
    // - arr[i] is SYNTACTIC SUGAR for *(arr + i)
    // - Compiler automatically handles byte-offset math based on type
    
    // MENTAL MODEL:
    // arr is not a container - it's a LABEL for a memory address
    // The [4] tells compiler "reserve 4*sizeof(int) bytes here"
    // All array operations are pointer arithmetic under the hood

    return 0;
}