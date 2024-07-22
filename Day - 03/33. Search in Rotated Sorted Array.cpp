/**
 *  @file: 33. Search in Rotated Sorted Array.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/search-in-rotated-sorted-array
 *  @level: Medium
 *  @date: 16-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int numsSize = nums.size();
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) >> 1;
            if (target == nums[mid])
            {
                return mid;
            }

            if (nums[left] <= nums[mid])
            {
                if (target < nums[mid] && target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
