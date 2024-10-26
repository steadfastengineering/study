#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        // loop
        // map
        // count
    }


    /*
        According to the Leet code problem description, this 
        solution is valid, but it's not what they are looking for. 

        The description does not define valid parentheses, however the 
        provided examples suggest (), ()() and ()()() etc constitude 
        valid substrings of parentheses. 
    */
    int longestValidParentheses_wrong(string s) {

        int count = 0;
        int max = 0;
        int first = 0;
        int second = 1;

        while(second < s.length())
        {
            if(s[first] == '(' && s[second] == ')')
            {
                count+=2;
                first+=2;
                second+=2;
            }
            else
            {
                first+=1;
                second+=1;
                count = 0;
            }
            if(count > max) max = count;
        }
 
        return max;
    }
};


int main()
{
    //TODO 
    return 0;
}