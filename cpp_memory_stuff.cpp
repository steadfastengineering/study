#include <iostream>

using namespace std;


int main()
{
    int var1 = 5;
    int* var1_ptr = &var1;

    // Size of prints the number of bytes stored by 
    cout << sizeof(var1) << endl;     // the int is 4 bytes because it is a 32 bit location in memory
    cout << sizeof(var1_ptr) << endl; // the pointer is 8 bytes because of our 64 bit system

    int i = 5;
    int j = i++; // j will be 5 because i is incremented afterwards
    int k = ++i; // k will be 7 because i is incremented beforehand

    int arrayLength = 4;

    int* x = (int*) malloc( arrayLength * sizeof(int)); // allocate memory for 4 integer array3 integer array
    for( int i = 0; i < arrayLength; i++){
        x[i] = (i*31)+7; // Malloc does not initialize memory, it comes with garbarge values, so we add them here.
    }
    cout << endl;
    for( int i = 0; i < arrayLength; i++){
        cout << x[i] << " ";
        
    }
    cout << endl;

    // unallocate our array from the heap. 
    free(x);

    // allocate and initialize using calloc()
    int* y = (int*) calloc( arrayLength, arrayLength*sizeof(int));
    for(int i = 0; i < arrayLength; i++)
    {
        cout << y[i] << " "; // Our array was initialized with zeros
    }
    
    // unallocate our array from the heap.
    free(y);

    cout << endl;


    unsigned char half_limit = 15;

    // What the heck is an unsigned char doing here? It's maximum 255, so it's not a good idea to use it as a variable. 
    for (unsigned char i = 0; i < 2 * half_limit; ++i)
    {
        cout << i << " "; // This is an infinite loop because "char" is only 8 bytes. 
        break; // just break out for runability purposes. 
    }

    return 0;
}