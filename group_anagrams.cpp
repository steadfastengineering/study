#include <string>
#include <iostream> 
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool is_anagram(string s1, string s2) {
    if (s1.length() != s2.length())
      return false;
    int s1_counts[256] = {0};
    int s2_counts[256] = {0};

    for (int i = 0; i < s1.length(); i++) {
      s1_counts[s1[i]]++;
      s2_counts[s2[i]]++;
    }

    for (int i = 0; i < 256; i++) {
      if (s1_counts[i] != s2_counts[i])
        return false;
    }

    return true;
  }

  vector<vector<string>> groupAnagrams_v1(vector<string> &strs) {
    vector<bool> used(strs.size(),
                      false); // lookup table for previously grouped strings
    vector<vector<string>> anagrams; // output

    for (int i = 0; i < strs.size(); i++) {
      if (!used[i]) {
        string s1 = strs[i];
        vector<string> s1_anagrams;
        s1_anagrams.push_back(s1);
        used[i] = true;

        for (int k = 0; k < strs.size(); k++) {
          if (!used[k]) {
            string s2 = strs[k];
            if (is_anagram(s1, s2)) {
              cout << s1 << " " << s2 << endl;
              s1_anagrams.push_back(s2);
              used[k] = true;
            }
          }
        }

        // add all the anagrams (if any, may just be s1 here) that we gathered
        anagrams.push_back(s1_anagrams);
      }
    }
    return anagrams;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> anagrams;
    unordered_map<string, vector<string>> groups;

    for(string s: strs){
        string key = s;
        sort(key.begin(), key.end());
        if(!groups.count(key)){
            groups[key] = {s};
            //groups[key].push_back(s);
        }
        else{
            groups[key].push_back(s);
        }
    }

    for(auto group : groups)
    {
        anagrams.push_back(group.second);
    }

    return anagrams;
  }
};

int main() {
  vector<string> input = {"nozzle", "punjabi", "waterlogged", "imprison", "impriosn", "ipmrison"};
  Solution s;
  auto anagrams = s.groupAnagrams(input);

  for (auto e : anagrams) {

    for (auto str : e)
      cout << str << " ";

    cout << endl;
  }
  return 0;
}