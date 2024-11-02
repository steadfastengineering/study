#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution 
{
    public:
        bool is_prime_trial_division(int n)
        {
            if(n<2) return false;
            //int root = (int)sqrt(n); // inefficient!

            for(int k = 3; k*k <= n; k+=2)
            {
                if(n%k == 0) return false;
            }
            return true;
        }

        
        int countPrimes_(int n)
        {
            if(n <= 2) return 0;

            int count = 1;
             for(int i = 3; i < n; i+=2)
            {
                if(is_prime_trial_division(i))
                {
                     count++;
                }
            }
            return count;
        }

        map<int, bool> primes;
        bool is_prime(int n)
        {
            for(auto prime : primes)
            {
                if(n%prime.first == 0) return false;
            }
            
            return true;
        }

        int countPrimes_prime_division(int n)
        {
            if(n <= 2) return 0;

            int count = 1;
            primes[2]  = true;
            for(int i = 3; i < n; i+=2)
            {
                if(is_prime(i))
                {
                    primes[i] = true;
                    count++;
                }
            }
            return count;
        }

        int countPrimes(int n)
        {   
            if(n <= 2) return 0; 

            // gotta use the Siev of Eratosthenes
            vector<char> primes(n, 1); // vector of bools is SLOW!
            int count = n-2;
            primes[0] = 0;
            primes[1] = 0; 
             
            for(int factor = 1; factor*factor < n; factor++)
            {    
                if(primes[factor])
                {   
                    // for each possible factor up to the square root of n, mark them as composites!
                    for(int composite = factor*factor; composite < n; composite += factor)
                    { 
                        //cout << "marking " << composite << " as composite" << endl;
                        // if it is a prime, mark it as a composite.
                        // we have this check here so we only update our counter once for each compsite we have eliminated.
                        if(primes[composite]){
                            primes[composite] = 0;
                            count--;
                        }
                    }
                }
            }
            return count;
        }
};

int main()
{
    Solution s; 
    //cout << s.countPrimes(2) << endl; // 0
    cout << s.countPrimes(3) << endl; // 1
     cout << s.countPrimes(5) << endl; // 2
    cout << s.countPrimes(6) << endl; // 3
     cout << s.countPrimes(7) << endl; // 3
     cout << s.countPrimes(8) << endl; // 4
     cout << s.countPrimes(9) << endl; // 4
     cout << s.countPrimes(10) << endl; // 4
     cout << s.countPrimes(100) << endl;
     cout << s.countPrimes(1000) << endl;
    return 0;
}