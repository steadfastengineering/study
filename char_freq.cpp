#include <iostream>
#include <map>
#include <string>

using namespace std;

void printmap(map<char, int> &map)
{
    for(auto it : map)
    {
        cout << it.first << " : " << it.second << endl;
    }
}

void populateFreq(map<char, int> &char_freq, string s)
{
      for (int i = 0; i < s.length(); i++)
    {
        char_freq[(char)s[i]]++;
    }
}

int getHighest(map<char, int> &char_freq)
{
    int highest = 0; 
    if(char_freq.empty()) return 0;

    for(auto it : char_freq)
    {
        if(it.second > highest) highest = it.second;
    }
    cout << "highest: " << highest << endl;
    return highest;
}

string buildFreqString(map<char, int> char_freq)
{
    string output = ""; 
    while( !char_freq.empty())
    {
        int count = getHighest(char_freq);
        for(auto it : char_freq)
        {
            if(it.second == count)
            {
                for(int i = 0; i < count; i++)
                {
                    output += it.first;
                }

                char_freq.erase(it.first);
                break;
            }
        }
    }
    return output;
}

int main()
{
    /*
    Given a string of characters, re-order the string by 1st character frequency, then 2nd character frequency, etc.
    "banana" will become "aaannb" because 'a' appears 3 times, 'n' appears 2 times, and 'b' appears 1 time.
    */

    map<char, int> char_freq;

    string s = "banana";
    populateFreq(char_freq, s);
    printmap(char_freq); 
    cout << buildFreqString(char_freq) << endl;


    return 0;
}