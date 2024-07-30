/**
 *  @file: 739. Daily Temperatures.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/daily-temperatures/description
 *  @level: Medium
 *  @date: 30-07-2024

 *  @brief: Given an array of integers temperatures represents the daily temperatures,
            return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
            If there is no future day for which this is possible, keep answer[i] == 0 instead.

            Example 1:                                            Example 2:                                  Example 3:
            Input: temperatures = [73,74,75,71,69,72,76,73]       Input: temperatures = [30,40,50,60]         Input: temperatures = [30,60,90]
            Output: [1,1,4,2,1,1,0,0]                             Output: [1,1,1,0]                           Output: [1,1,0]
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int size = temperatures.size();
        vector<int> res(size);
        stack<int> st;

        for (int i = 0; i < size; i++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};