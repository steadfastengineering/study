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

int main()
{
    cout << "Fibonacci 5th term:" << fib_mem(5) << endl;
    cout << "Fibonacci 10th term:" << fib_mem(25) << endl;
    cout << "Fibonacci 10th term:" << fib_mem(25) << endl;

    return 0;
}
