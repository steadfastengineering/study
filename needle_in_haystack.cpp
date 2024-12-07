#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int index = -1;
    int current = 0;
    while (current + needle.length() -1 < haystack.length()) {
      for (int window_index = 0; window_index < needle.length(); window_index++) {
         
        if (haystack[current + window_index] != needle[window_index]) {
          break;
        } else if (window_index == needle.length() - 1) { 
          return current;
        } 
      }
      current++;
    }
    return index;
  }
};

int main() {
  Solution s = Solution();

  cout << s.strStr("leetcode", "leeto") << endl;
  cout << s.strStr("sadbutsad", "sad")<< endl;
  cout << s.strStr("sadbutsadd", "sadd") << endl;
  cout << s.strStr("sadbuadbtsadd", "adbt")<< endl;
  return 0;
}