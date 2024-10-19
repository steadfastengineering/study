/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 10^6

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int iter : v)
    cout << iter << endl;
}

void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &merged) {
  for (auto iter : nums1)
    merged.push_back(iter);

  for (auto iter : nums2)
    merged.push_back(iter);
}

void bubblesort(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        bool swapped = false;
        for(int k = 0; k < v.size()-1; k++)
        {
            if(v[k] > v[k+1])
            {
                int temp = v[k];
                v[k] = v[k+1];
                v[k+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break; // if not swapping, no reason to continue making comparisons
    }
}

double find_median(vector<int> &v) {
  double median = 0;
  if (v.size() % 2 == 0) {
    median = (v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2.0;
  } else {
    median = v[v.size() / 2];
  }
  return median;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  vector<int> merged;
  merge(nums1, nums2, merged);
  bubblesort(merged);
  double median = find_median(merged);
  return median;
}

int main() {
  // TODO
  vector<int> nums1 = {1,3,5,7,9,10};
  vector<int> nums2 = {2,4};

  double median = findMedianSortedArrays(nums1, nums2);
  cout << "median: " << median << endl;
  return 0;
}