/**
 *  @file: 1. Two Sum.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/two-sum
 *  @level: Easy
 *  @date: 14-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Initialize a unordered map to store numbers and their indices
        unordered_map<int, int> mp;

        // Loop through the array 'nums'
        for (int i = 0; i < nums.size(); i++)
        {
            // Check if the complement (target - current number) is in the map
            if (mp.find(target - nums[i]) == mp.end())
            {
                // If not found, store the current number and its index in the map
                mp[nums[i]] = i;
            }
            else
            {
                // If found, return the indices of the complement and the current number
                return {mp[target - nums[i]], i};
            }
        }
        // If no solution is found
        return {-1, -1};
    }
};
