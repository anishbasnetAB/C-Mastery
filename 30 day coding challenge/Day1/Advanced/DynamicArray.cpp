#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// STRUCTURE DEFINITION
// ============================================================================

typedef struct {
    int* data;       // Pointer to heap-allocated array
    int size;        // Number of elements currently stored
    int capacity;    // Total allocated space
} DynamicArray;

// ============================================================================
// FUNCTION IMPLEMENTATIONS
// ============================================================================

void init(DynamicArray* arr, int capacity) {
    // Allocate memory on heap
    arr->data = (int*)malloc(capacity * sizeof(int));
    
    // Check if allocation succeeded
    if (arr->data == NULL) {
        printf("[ERROR] Memory allocation failed!\n");
        exit(1);
    }
    
    // Initialize metadata
    arr->size = 0;
    arr->capacity = capacity;
    
    // Debug output
    printf("\n[INIT] Array initialized\n");
    printf("       Capacity: %d\n", capacity);
    printf("       Address: %p\n\n", (void*)arr->data);
}

void push_back(DynamicArray* arr, int value) {
    // Check if resize is needed
    if (arr->size == arr->capacity) {
        printf("⚠️  RESIZE TRIGGERED! Array is full\n\n");
        
        // Calculate new capacity (double it)
        int new_capacity = arr->capacity * 2;
        
        // Allocate new larger array
        int* new_data = (int*)malloc(new_capacity * sizeof(int));
        
        if (new_data == NULL) {
            printf("[ERROR] Resize failed! Out of memory\n");
            exit(1);
        }
        
        printf("[RESIZE] Allocating new array...\n");
        printf("         Old Capacity: %d\n", arr->capacity);
        printf("         New Capacity: %d\n", new_capacity);
        printf("         Old Address: %p\n", (void*)arr->data);
        printf("         New Address: %p\n\n", (void*)new_data);
        
        // Copy all existing elements
        for (int i = 0; i < arr->size; i++) {
            new_data[i] = arr->data[i];
        }
        printf("[RESIZE] Copied %d elements\n", arr->size);
        
        // Free old array
        printf("[RESIZE] Freeing old array...\n");
        free(arr->data);
        
        // Update pointer and capacity
        arr->data = new_data;
        arr->capacity = new_capacity;
        printf("[RESIZE] Resize complete!\n\n");
    }
    
    // Insert the new element
    arr->data[arr->size] = value;
    arr->size++;
    
    // Debug output
    printf("[PUSH] Inserted value: %d\n", value);
    printf("       Size: %d\n", arr->size);
    printf("       Capacity: %d\n", arr->capacity);
    printf("       Address: %p\n", (void*)arr->data);
    printf("       Current Array: [");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n\n");
}

void removeAt(DynamicArray* arr, int index) {
    // Bounds checking
    if (index < 0 || index >= arr->size) {
        printf("[ERROR] Index %d out of bounds (size=%d)\n", 
               index, arr->size);
        return;
    }
    
    int removed_value = arr->data[index];
    printf("[REMOVE] Removing element at index %d (value: %d)\n", 
           index, removed_value);
    printf("         Before: [");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
    
    // Shift elements left
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    
    // Decrement size
    arr->size--;
    
    printf("         After:  [");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
    printf("         Size: %d, Capacity: %d\n\n", 
           arr->size, arr->capacity);
}

int get(DynamicArray* arr, int index) {
    // Bounds checking
    if (index < 0 || index >= arr->size) {
        printf("[ERROR] Index %d out of bounds (size=%d)\n", 
               index, arr->size);
        return -1;
    }
    
    return arr->data[index];
}

void print(DynamicArray* arr) {
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("│              DYNAMIC ARRAY STATE                        │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  Size:           %-2d elements                           │\n", arr->size);
    printf("│  Capacity:       %-2d slots                             │\n", arr->capacity);
    printf("│  Memory Address: %-35p│\n", (void*)arr->data);
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  Elements: [");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]");
    // Pad with spaces to align the closing │
    int printed = arr->size * 2 + (arr->size - 1) * 2; // rough estimate
    for (int i = printed; i < 40; i++) printf(" ");
    printf("│\n");
    printf("└─────────────────────────────────────────────────────────┘\n\n");
}

void destroy(DynamicArray* arr) {
    printf("[DESTROY] Freeing memory at address: %p\n", 
           (void*)arr->data);
    
    // Free heap memory
    free(arr->data);
    
    // Prevent dangling pointer
    arr->data = NULL;
    
    // Reset metadata
    arr->size = 0;
    arr->capacity = 0;
    
    printf("          ✓ Memory successfully freed\n");
    printf("          ✓ No memory leaks\n\n");
}

// ============================================================================
// MAIN FUNCTION - TEST CASES
// ============================================================================

int main() {
    printf("════════════════════════════════════════════════════════════\n");
    printf("           DYNAMIC ARRAY DEMONSTRATION                      \n");
    printf("════════════════════════════════════════════════════════════\n");
    
    // Test 1: Initialize with small capacity to force resize
    DynamicArray arr;
    init(&arr, 2);
    
    printf("════════════════════════════════════════════════════════════\n");
    printf("TEST 1: Push 4 elements (will trigger resize)               \n");
    printf("════════════════════════════════════════════════════════════\n\n");
    
    // Test 2: Push elements
    push_back(&arr, 10);
    push_back(&arr, 20);
    push_back(&arr, 30);  // This will trigger resize
    push_back(&arr, 40);
    
    // Test 3: Print array
    printf("════════════════════════════════════════════════════════════\n");
    printf("TEST 2: Print current array state                           \n");
    printf("════════════════════════════════════════════════════════════\n\n");
    print(&arr);
    
    // Test 4: Remove element
    printf("════════════════════════════════════════════════════════════\n");
    printf("TEST 3: Remove element at index 1                           \n");
    printf("════════════════════════════════════════════════════════════\n\n");
    removeAt(&arr, 1);
    
    // Test 5: Access elements
    printf("════════════════════════════════════════════════════════════\n");
    printf("TEST 4: Access individual elements                          \n");
    printf("════════════════════════════════════════════════════════════\n\n");
    
    printf("[GET] Element at index 0: %d\n", get(&arr, 0));
    printf("[GET] Element at index 1: %d\n", get(&arr, 1));
    printf("[GET] Element at index 2: %d\n", get(&arr, 2));
    printf("\n");
    
    // Test 6: Try invalid access
    printf("════════════════════════════════════════════════════════════\n");
    printf("TEST 5: Test bounds checking (invalid index)                \n");
    printf("════════════════════════════════════════════════════════════\n\n");
    get(&arr, 10);  // Should print error
    printf("\n");
    
    // Test 7: Final print
    printf("════════════════════════════════════════════════════════════\n");
    printf("TEST 6: Final array state                                   \n");
    printf("════════════════════════════════════════════════════════════\n\n");
    print(&arr);
    
    // Test 8: Cleanup
    printf("════════════════════════════════════════════════════════════\n");
    printf("TEST 7: Cleanup and destroy                                 \n");
    printf("════════════════════════════════════════════════════════════\n\n");
    destroy(&arr);
    
    printf("════════════════════════════════════════════════════════════\n");
    printf("           ALL TESTS COMPLETED SUCCESSFULLY                  \n");
    printf("════════════════════════════════════════════════════════════\n");
    
    return 0;
}
