#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
        int romanValue(char c)
        {
            switch(c)
            {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
            }
            return -1;
        }

        int romanToInt(string s)
        {
            int sum=0;
            while(true)
            {
                if(s.length()==0)
                {
                    break;
                }
                else if(s.length() == 1)
                {
                    sum += romanValue(s[0]);
                    break;
                }
                else if( romanValue(s[0]) >= romanValue(s[1]) )
                {
                    sum += romanValue(s[0]);
                    s.erase(s.begin());
                }
                else if(romanValue(s[0]) < romanValue(s[1]) )
                {
                    sum += romanValue(s[1]) - romanValue(s[0]);
                    s.erase(s.begin());
                    s.erase(s.begin());
                }
            }
            return sum;
        }
};

int main()
{
    Solution s = Solution();
    cout << s.romanToInt("MMMDCCXXIV") << endl; // 3724
    cout << s.romanToInt("") << endl; // 0
    cout << s.romanToInt("LVIII") << endl; // 58
    cout << s.romanToInt("MCMXCIV") << endl; // 1994

    return 0;
}