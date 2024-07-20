/**
 *  @file: 54. Spiral Matrix.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/spiral-matrix/description
 *  @level: Medium
 *  @date: 21-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            for (int j = left; j <= right; ++j)
            {
                res.push_back(matrix[top][j]);
            }

            ++top;

            for (int i = top; i <= bottom; ++i)
            {
                res.push_back(matrix[i][right]);
            }

            --right;

            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                {
                    res.push_back(matrix[bottom][j]);
                }

                --bottom;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    res.push_back(matrix[i][left]);
                }

                ++left;
            }
        }
        return res;
    }
};