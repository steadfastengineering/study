#include <iostream>
#include <string>
#include <stack>
#include <regex>
#include <map>

using namespace std;

class Solution {
public:

    bool is_valid_1(string s) {

        if (s.length() <= 1)
            return false;

        char first = s[0];
        char last = s[s.length() - 1];

        if (first == ')' || last == '(')
            return false;

        int track = 0;
        for (char c : s) {
            if (c == '(') {
                track++;
            } else if (c == ')') {
                track--;
            }
        }
        return track == 0;
    }
    
    bool is_valid_regex(string s)
    {
        //regex pattern = "\\((\\(\\))*\\)"
        regex pattern("\\((\\(*\\))*\\)");
        return regex_match(s, pattern);
    }

    bool is_valid(string s)
    {
        // optimizations
        int length = s.length();
        if(length % 2 != 0) return false;
        if (length <= 1) return false;
        

        stack<char> open_close_stack;
        for(int i=0; i<length;i++)
        {
            cout << "stack size: " << open_close_stack.size() << endl;
            if(s[i] == '('){ 
                open_close_stack.push(s[i]);
            }
            else
            {
                if(!open_close_stack.empty() && s[i] == ')')
                {
                        open_close_stack.pop();
                }
                else
                {
                        return false;
                }
            }
        }
        return open_close_stack.empty();
    }

    bool is_valid_counters(string s)
    {
        // optimizations
        int length = s.length();
        if(length % 2 != 0) return false;
        if (length <= 1) return false;
        
        int open_close_count = 0;
        for(int i=0; i<length;i++)
        {
            if(s[i] == '('){ 
                open_close_count++;
            }
            else
            {
                if(open_close_count != 0 && s[i] == ')')
                {
                        open_close_count--;
                }
                else
                {
                        return false;
                }
            }
        }
        return (open_close_count == 0);
    }

    bool is_valid_2(string s) {
        int length = s.length();
        if(length % 2 != 0) return false;
        if (length <= 1) return false;
        
        int open = 0;
        int close = 0;

        char first = s[0];
        char last = s[length - 1];
        if (first == ')' || last == '(') return false;

        for(int i = 0; i < length; i++)
        {
            char c = s[i]; 
            if(c == ')') close++; 
            if(c == '(') open++; 
            if(i < length-i && close > open) return false;
            if( open-close >= length-i) return false;
        }
        return (open == close);
    }

    
    int longestValidParentheses_inefficient(string s) 
    { 
        // check every possible substring for validity starting with longer strings
        int max = 0;
        for(int i = s.length(); i > 1; i--)
        {    
             for(int k = 0; k<i-1; k++)
             { 
                string ss = s.substr(k, i-k); 
                cout << ss << endl;

                bool valid = false;

                // skip strings that are shorter than the current longest
                if(ss.length() > max){
                     valid = is_valid_counters(ss);
                }
                
                if(valid)
                {
                    int length = ss.length();
                    if(length > max) max = length;
                }
             } 

        }
        return max;
    }

     int LongestValidParentheses(string s) {
        // Sliding window technique --> exemplary case
        // push the current index onto the stack if we encounter an open
        // if we encounter a closed and the stack is empty, then the current index is invalid
        // if we encounter a closed and the stack is not empty, pop the top of the stack 
        // and record the differce between the last invalid index the current index (if it is maximal)

        // BOOM this is O(N) 
        stack<int> index_stack;
        int max = 0;
        int last_invalid_index = -1;

        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == '(') 
            {
                index_stack.push(i);
            } else 
            {
                if (index_stack.size() == 0) 
                {
                    last_invalid_index = i;
                } 
                else 
                {
                    index_stack.pop();
                    if (index_stack.size() == 0) 
                    {
                        max = max > i - last_invalid_index ? max : i - last_invalid_index;
                    } else 
                    {
                        max = max > i - index_stack.top() ? max : i - index_stack.top();
                    }
                }
            }
        }
        return max;
    }
 
};


int main()
{
    Solution s;
    /*
    cout << s.longestValidParentheses("(((())))") << endl;
    cout << s.longestValidParentheses("()") << endl;
    cout << s.longestValidParentheses("()))") << endl;
    */

    cout <<  s.LongestValidParentheses("(((())))") << endl; // 8
    cout <<  s.LongestValidParentheses("()") << endl; // 2
    cout <<  s.LongestValidParentheses("()))") << endl; // 2
    cout <<  s.LongestValidParentheses("))))((()((") << endl; // 2
    cout <<  s.LongestValidParentheses("(())()(()((") << endl; // 6
    cout <<  s.LongestValidParentheses("()(()))(()") << endl; // 6

    // 106
    cout <<  s.LongestValidParentheses_test(")(()())())(((()))(()()()(()(()(())))(())()((()()(((()())()))(()()())())(())(()(()()()()))(((()())))(((()))))()()())))(()))))())(((()") << endl; // 106
    
    // 168?
    string worst = "((())())(()))(()()(()(()))(()((((()))))))((()())()))()()(()(((((()()()())))()())(()()))((((((())))((()))()()))))(()))())))()))()())((()()))))(()(((((())))))()((()(()(())((((())(())((()()(()())))())(()(())()()))())(()()()))()(((()())(((()()())))(((()()()))(()()))()))()))))))())()()((()(())(()))()((()()()((())))()(((()())(()))())())))(((()))))())))()(())))()())))())()((()))((()))()))(((())((()()()(()((()((())))((()()))())(()()(()))))())((())))(()))()))))))()(()))())(()())))))(()))((())(()((())(((((()()()(()()())))(()())()((()(()()))(()(())((()((()))))))))(()(())()())()(()(()(()))()()()(()()())))(())(()((((()()))())))(())((()(())())))))())()()))(((())))())((()(()))(()()))((())(())))))(()(()((()((()()))))))(()()()(()()()(()(())()))()))(((()(())()())(()))())))(((()))())(()((()))(()((()()()(())()(()())()(())(()(()((((())()))(((()()(((()())(()()()(())()())())(()(()()((()))))()(()))))(((())))()()))(()))((()))))()()))))((((()(())()()()((()))((()))())())(()((()()())))))))()))(((()))))))(()())))(((()))((()))())))(((()(((())))())(()))))(((()(((((((((((((())(((()))((((())())()))())((((())(((())))())(((()))))()())()(())())(()))))()))()()()))(((((())()()((()))())(()))()()(()()))(())(()()))()))))(((())))))((()()(()()()()((())((((())())))))((((((()((()((())())(()((()))(()())())())(()(())(())(()((())((())))(())())))(()()())((((()))))((()(())(()(()())))))))))((()())()()))((()(((()((()))(((((()()()()()(()(()((()(()))(()(()((()()))))()(()()((((((()((()())()))((())()()(((((()(()))))()()((()())((()())()(())((()))()()(()))";
    cout << s.LongestValidParentheses_test(worst);
    
    return 0;
}