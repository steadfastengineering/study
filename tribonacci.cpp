#include<iostream>
#include<map>

using namespace std;

/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/


class Solution {
public:

    map<int,int> cache;

    int tribonacci(int n) {
        if(!cache.count(n))
        {
            // compute T
            if(n == 0)
            {
                return 0;
            }
            if(n == 1 || n == 2)
            {
                return 1;
            }
            else
            { 
                int result = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
                cache[n] = result;
                return result;
            }

        }
        else
        {
            // return previous result
            return cache[n];
        }
    }
};


int main()
{
    Solution s;
    cout << s.tribonacci(37) << endl;
    return 0;
}