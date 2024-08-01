/**
*  @file: 442. Find All Duplicates in an Array.cpp
*  @author: Avinash Yadav
*  @brief: https://leetcode.com/problems/find-all-duplicates-in-an-array/description
*  @level: Medium
*  @date: 01-08-2024
*
*  @brief:  Given an integer array nums of length n where all the integers of nums are in the range [1, n] and
            each integer appears once or twice, return an array of all the integers that appears twice.
            You must write an algorithm that runs in O(n) time and uses only constant extra space.

            Example 1:                                      Example 2:                                     Example 3:
            Input: nums = [4,3,2,7,8,2,3,1]                 Input: nums = [1,1,2]                          Input: nums = [1]
            Output: [2,3]                                   Output: [1]                                    Output: []
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            // Mapping the nums value to index
            int index = abs(nums[i]) - 1;

            // If the value at that index is already negative,
            // it means we have seen this number before
            if (nums[index] < 0)
            {
                result.push_back(abs(nums[i]));
            }
            else
            {
                // Marking the number as seen by making the value at the corresponding index negative
                nums[index] = -nums[index];
            }
        }

        return result;
    }
};