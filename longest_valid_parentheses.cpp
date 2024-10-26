#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    int is_valid(string s)
    {
        stack<char> ss;
        int count = 0;
        int max = 0;

        for(char c : s){
            if(c=='(')
            {
                stack.push('(')
                count++;
            }
            else
            {
                stack.pop();
            }
            
            if(stack.empty())
            {
                if(count > max) max = count;
                count = 0;
            }
        }
    }

    int longestValidParentheses(string s) 
    {
        // loop
        // map
        // count

        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {

            }
        }
    }


    /*
        According to the Leet code problem description, this 
        solution is valid, but it's not what they are looking for. 

        The description does not define valid parentheses, however the 
        provided examples suggest (), ()() and ()()() etc constitude 
        valid substrings of parentheses. A literal interpretation
        yeilds the result below.
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