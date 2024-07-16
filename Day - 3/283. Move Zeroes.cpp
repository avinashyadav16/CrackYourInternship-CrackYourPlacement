/**
 *  @file: 283. Move Zeroes.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/move-zeroes
 *  @level: Easy
 *  @date: 16-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;

        int start = 0, end = 0;
        while (end < nums.size())
        {
            if (nums[end] != 0)
            {
                swap(nums[start], nums[end]);
                start++;
            }
            end++;
        }
    }
};