#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool negative = false;
        if(s[0] == '-') {
            negative = true;
            s.erase(s.begin());
        }

        ulong result = 0;
        for(int i = s.length()-1; i >= 0 ; i--)
        {
                ulong val = s[i] - '0';
                result += val*pow(10, (i));
            
        }

        if(result > INT_MAX) return 0;
        
        if(negative){
            return  ((int)result) * -1;
        }

int main()
{
    //TODO 
    return 0;
}