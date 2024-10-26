#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    bool is_bit_high(uint32_t n, uint32_t position)
    {
        int left = (31-position);
        int right = 31;
        uint32_t temp = n;
        temp = temp << left;
        temp = temp >> right;
 
        if(temp == 1) return true; 

        return false;
    }

    uint32_t reverseBits(uint32_t n) 
    { 
        vector<bool> bits;
        for(int i = 31; i >= 0; i--)
        { 
            bits.push_back(is_bit_high(n, i));
        }

        uint32_t result = 0;
        for(int i = 0; i < 32; i++)
        {
            if(bits[i])
            {
                result |= (1 << i);
            }
        }
        return result;
    }
};

int main()
{
    //TODO 
    return 0;
}