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

int main()
{
    // Simple variables
    int x = 5;
    int* y = &x; // this is a pointer to a variable. The pointer stores the address of x.
    cout << "Variable:" << x << endl;
    cout << "Pointer to variable:" << y << endl;
    cout << "Dereferenced pointer to variable:" << *y << endl;

    // Arrays
    int arr[] = {0,1,2,3}; // this is an array
    int* arr_ptr = arr; // this is a pointer to the first element of the array.
    
    printArray(arr, 4); // prints the array
    printArray(arr_ptr, 4); // prints the array
}