#include <iostream>
#include <map>
using namespace std;

/*
    Given n steps, you can climb 1, 2, or 3 steps at a time.
    How many ways can you climb the steps?
*/
map<int,int>cache;
int countWays(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;  

    // This is a dynamic programming solution.
    // We can use a cache to store the number of ways to climb up to the top
    // of the stairs.
    if(cache.find(n) != cache.end()){
        return cache[n];
    }

    int count1 = countWays(n-1);
    int count2 = countWays(n-2); 
    int count3 = countWays(n-3);
    int numberOfWays = count1 + count2 + count3;
    return numberOfWays;
}

int main()
{ 
    int steps = 30; 
    cout << "Number of ways to climb: " << countWays(steps) << endl;
}