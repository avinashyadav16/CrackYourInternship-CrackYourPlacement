/**
 *  @file: 75. Sort Colors.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/sort-colors/
 *  @brief: Medium
 *  @date: 17-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // METHOD - 01:
    //  void sortColors(vector<int>& nums) {
    //      sort(nums.begin(), nums.end());
    //  }

    // METHOD - 02:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};