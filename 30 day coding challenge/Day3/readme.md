## 📚 Project 1: Dynamic Array Class (Vector Clone)

**Difficulty:** ⭐⭐☆☆☆  
**Time:** 2-3 days  
**Concepts:** Pointers, dynamic memory, basic RAII

### What to Build

A simplified version of `std::vector` with:

- Dynamic array that grows automatically
- Add/remove elements
- Access by index
- Memory management

### Implementation Requirements

```cpp
class DynamicArray {
private:
    int* data;           // Pointer to dynamic array
    size_t size;         // Current number of elements
    size_t capacity;     // Total allocated space
    
public:
    DynamicArray();                          // Default constructor
    ~DynamicArray();                         // Destructor
    DynamicArray(const DynamicArray& other); // Copy constructor
    DynamicArray(DynamicArray&& other);      // Move constructor
    
    void push_back(int value);
    void pop_back();
    int& operator[](size_t index);
    size_t getSize() const;
    void reserve(size_t newCapacity);
};
```

### Key Learning Points

✅ Dynamic allocation with `new[]` and `delete[]`  
✅ Growing array when capacity reached  
✅ Deep copy in copy constructor  
✅ Move constructor to steal resources  
✅ Destructor to prevent memory leaks  
✅ Pointer arithmetic for array access

### Test Cases to Write

```cpp
// Test 1: Basic operations
DynamicArray arr;
arr.push_back(10);
arr.push_back(20);
assert(arr[0] == 10);

// Test 2: Copy constructor (deep copy)
DynamicArray arr2 = arr;
arr2[0] = 999;
assert(arr[0] == 10);  // Original unchanged

// Test 3: Move constructor
DynamicArray arr3 = std::move(arr);
// arr should be in valid but empty state

// Test 4: Memory leak check (use valgrind)
{
    DynamicArray temp;
    temp.push_back(1);
}  // Should not leak
```

### Common Mistakes to Encounter & Fix

- Forgetting `delete[]` → memory leak
- Using `delete` instead of `delete[]` → undefined behavior
- Shallow copy in copy constructor → double delete
- Not nullifying pointers in move constructor → double delete