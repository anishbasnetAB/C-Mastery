#include <iostream>

int bubbleSort(int arr[], int size)
{
    bool swapped;
    
    do {
        swapped = false;  // Reset flag at start of each pass
        
        for(int i = 0; i < size - 1; i++)
        {
            int j = i + 1;
            
            if(arr[i] > arr[j])
            {
                // Swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
                swapped = true;  // Mark that we did a swap
            }
        }
        
    } while(swapped);  // Keep going if we made any swaps
    
    // Print sorted array
    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}

int main()
{

    int arr[] ={3,2,1,5,1,6,10,50,7,1,100};
    int size = {sizeof(arr)/sizeof(arr[0])};
    bubbleSort(arr,size);
    
    return 0;
}