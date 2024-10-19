#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/
vector<int> twoSum(vector<int>& nums, int target)
{
  vector<int> solution;
  solution.push_back(-1);
  solution.push_back(-1);
  for(int i = 0; i < nums.size(); i++)
  {
      for(int k=0; k < nums.size(); k++)
      {
        if(k!=i)
        {
          if(nums[i] + nums[k] == target)
          {
            solution[0] = i;
            solution[1] = k;
            return solution;
          }
        }
      }
  }
  return solution;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(3);
    //v.push_back(15);
    int target = 6;

    vector<int> solution = twoSum(v, target);
    cout << solution[0] << "," << solution[1] << endl;

    return 0;
}
