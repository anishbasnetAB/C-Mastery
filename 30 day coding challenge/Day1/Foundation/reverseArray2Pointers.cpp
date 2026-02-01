#include <iostream>

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int* ptrStart=arr;
    int* ptrEnd=arr+9;
    while(ptrStart<ptrEnd)
    {
        int temp=*ptrStart;
        *ptrStart=*ptrEnd;
        *ptrEnd=temp;

        ptrStart++;
        ptrEnd--;
    }

    std::cout << "Reversed array: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    

    return 0;
}