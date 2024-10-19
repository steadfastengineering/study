// Zigzag Conversion
// Medium
// Topics
// Companies

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows)
{
    vector<vector<char>> temp;
    int pos = 0;
    bool down = true;
    while(pos < s.length())
    {
        if(down)
        {
            for(int i = 0; i < numRows; i++)
            {
                if(temp.size() < numRows) 
                {
                    vector<char> row;
                    temp.push_back(row);
                }
                temp[i].push_back(s[pos]);
                pos++;
                if(pos >= s.length()) break;
            }
        }

        if(!down)
        {
            for(int i = numRows - 2; i > 0; i--)
            {
                temp[i].push_back(s[pos]);
                pos++;
                if(pos >= s.length()) break;
            }
        }

        down = !down;
    }

    // flatten out the 2d vector
    string result;
    for(int i = 0; i < temp.size(); i++)
    {
        vector<char> row = temp[i];
        for(int k = 0; k < row.size(); k++)
        {
            result += row[k];
        }
    }
    return result;
}

int main()
{
    //cout <<  convert("PAYPALISHIRING", 3) << endl;
    //cout <<  convert("P", 1) << endl;
    //cout <<  convert("PA", 2) << endl;
    cout <<  convert("PA", 3) << endl;
    return 0;
}