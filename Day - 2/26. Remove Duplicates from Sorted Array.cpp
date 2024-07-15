/**
 *  @file: 26. Remove Duplicates from Sorted Array.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *  @level:  Easy
 *  @date: 15-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int ind = 1;

        for (int start = 1; start < nums.size(); ++start)
        {
            if (nums[start] != nums[start - 1])
            {
                nums[ind++] = nums[start];
            }
        }
        return ind;
    }
};