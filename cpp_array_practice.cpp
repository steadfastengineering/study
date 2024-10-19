#include <iostream> 

using namespace std;

void printArray(int* arr, int length)
{
    for(int i = 0; i < length; i++)
     {
        cout << arr[i] << " ";
     }
     cout << endl;
}

int* removeElement(int* arr, int length, int n)
{
    int* newArr = new int[length-1];

    for(int i = 0; i < length; i++)
    {
        if(i == n)
        {
            continue;
        }
        else if(i > n)
        {
            newArr[i - 1] = arr[i];
        }
        else
        {
            newArr[i] = arr[i];
        }
    } 
    // This does not modify the data at which the original is pointing to because the pointer
    // variable is just that, a local variable!
    // arr = newArr;

    // We should return our new array reference!
    return newArr;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8};

    printArray(arr1, 5);
    int* arr3 = removeElement(arr1, 5, 1); // remove element at index 2
    printArray(arr3, 4);
     
    cout << arr3 << endl;
    delete [] arr3; // We use delete [] to delete an array that we allocated with new []
    cout << arr3 << endl;
    printArray(arr3, 4);

    return 0;
}