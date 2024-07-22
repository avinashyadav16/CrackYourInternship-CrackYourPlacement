/**
 *  @file: 121. Best Time to Buy and Sell Stock.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 *  @level: Easy
 *  @date: 22-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        int start = 0, end = 1, ans = 0;

        while (end < prices.size())
        {
            if (prices[start] < prices[end])
            {
                ans = max((prices[end] - prices[start]), ans);
            }
            else
                start = end;

            end++;
        }
        return ans;
    }
};