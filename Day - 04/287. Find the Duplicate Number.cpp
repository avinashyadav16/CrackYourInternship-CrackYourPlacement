/**
 *  @file: 287. Find the Duplicate Number.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/find-the-duplicate-number/
 *  @brief: Medium
 *  @date: 17-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int element = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if ((nums[i] ^ element) == 0)
            {
                break;
            }

            element = nums[i];
        }
        return element;
    }
};