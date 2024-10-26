
#include <iostream>
#include <string>

using namespace std;

/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".
*/


class Solution {
public:
    string defangIPaddr(string address) {
        string result = ""; 
        char fang = '.';
        for(char c : address)
        {
            if(c != fang){
                result+=c;
            }
            else
            {
                result += '[';
                result += '.';
                result += ']';
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}