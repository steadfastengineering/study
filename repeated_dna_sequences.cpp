#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long 
sequences (sequences) that occur more than once in a DNA molecule. You may return 
the answer in any order.
*/

class Solution {
public:


    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> sequences;

        // Sliding window 
        int i = 0; 
        while(i<s.length())
        {           
            // get 10 character window
            string current = "";
            for(int w = i; w < i+10; w++)
            {
                if(w > s.length()) break;
                current += s[w];
            }
            cout << current << endl;
            if(!sequences.count(current))
            {
                sequences[current] = 1;
            }
            else 
            {
                sequences[current] = sequences[current]+1;
            }
            i++;
        }   

        // Populate in any order
        vector<string> result;
        for(auto sequence : sequences)     
        {
            if(sequence.second > 1) result.push_back(sequence.first);
        }

        return result;
    }
};


int main()
{
    string t1 = "AAAAAAAAAAAAA";
    Solution s;
    vector<string> r = s.findRepeatedDnaSequences(t1);

    for(auto ss : r) cout << "result:" << ss << " ";

    cout << endl;
    return 0;
}