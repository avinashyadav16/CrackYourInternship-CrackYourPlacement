/**
 *  @file: 122. Best Time to Buy and Sell Stock II.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 *  @level: Medium
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
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};