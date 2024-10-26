#include <iostream>
#include <string>
#include <map>

using namespace std;

// fib: 1 1 2 3 5 8
// idx: 0 1 2 3 4 5
int fib(int n)
{
  if(n == 1)
  {
    return 1;
  }
  else if(n == 2)
  {
    return n;
  }
  else
  {
      return fib(n-1)+fib(n-2);
  }
}


map<int, int> fib_cache;

int fib_mem(int n)
{
  if(!fib_cache.count(n))
  {
    if(n == 1)
    {
      return 1;
    }
    else if(n == 2)
    {
      return n;
    }
    else
    {
        int result = fib(n-1)+fib(n-2);
        fib_cache[n] = result;
        return result;
    }
  }
  else
  {
    return fib_cache[n];
  }
}




/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum 
of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
*/
class Solution {
public:

    map<int, int> cache;

    int fib(int n) {
        if(!cache.count(n))
        {
          // compute fib
          if(n == 0 || n == 1) return n;

          int result = fib(n-1) + fib(n-2);
          cache[n] = result; 
          return result;
        }
        else{
          // return cached value
          return cache[n];
        }
    }

};


int main()
{
    cout << "Fibonacci 5th term:" << fib_mem(5) << endl;
    cout << "Fibonacci 25th term:" << fib_mem(25) << endl;
    cout << "Fibonacci 25th term:" << fib_mem(25) << endl;

    Solution s; 
    cout << s.fib(5) << endl;
    cout << s.fib(25) << endl;
    cout << s.fib(25) << endl;

    return 0;
}
