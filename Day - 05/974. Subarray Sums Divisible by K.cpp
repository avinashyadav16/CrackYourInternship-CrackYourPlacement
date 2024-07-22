/**
 *  @file: 974. Subarray Sums Divisible by K.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/subarray-sums-divisible-by-k
 *  @level: Medium
 *  @date: 18-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int res = 0, sum = 0;
        map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int r = sum % k;

            if (r < 0)
                r = r + k;

            if (mp.find(r) == mp.end())
            {
                mp[r] = 1;
            }
            else
            {
                res += mp[r];
                mp[r]++;
            }
        }
        return res;
    }
};