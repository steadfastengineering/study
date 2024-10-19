#include <iostream>

using namespace std;

int problem(int n)
{
    int x = 53;
    if( n == 0) 
        throw n;
    return x/n; 
}


int main()
{
    int n = 0;
    try
    {
        int x = 53;
        if( n == 0) 
        {
            throw n;
        }
        cout << x/n << endl;
    }
    catch(int e)
    {
        cout << "We caught an error: " << e << endl;
    }
}