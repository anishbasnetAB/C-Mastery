Raw Arrays & Pointer Basics
Overview
Deep dive into the fundamental relationship between arrays and pointers in C++. This is where I stop relying on abstractions and understand how data actually lives in memory.
Core Concepts

Array-Pointer Duality: Arrays decay to pointers; arr[i] is syntactic sugar for *(arr + i)
Pointer Arithmetic: Navigate memory by incrementing/decrementing pointers
Manual Memory Management: Using malloc/free to understand what new/delete abstract away
Memory layout: Understanding contiguous storage and address calculations

What I'll Build

Pointer-Based Array Algorithms: Reversal, traversal, and string operations without using [] operator
Dynamic Array Class: From-scratch implementation with automatic resizing (no STL, no vector)
2D Array Memory Model: Visualizing row-major ordering and multi-dimensional pointer dereferencing

Key Exercises

Implement strlen() using only pointers and null-terminator detection
Two-pointer in-place array reversal
Dynamic memory allocation with capacity vs size tracking
Memory address visualization during reallocation
Multi-level pointer dereferencing for 2D arrays

Skills Gained

Navigate arrays using pointer arithmetic exclusively
Understand why ptr++ moves by sizeof(type) bytes automatically
Manually manage heap memory lifecycle
Visualize memory layout and predict address calculations
Debug memory issues by examining actual addresses