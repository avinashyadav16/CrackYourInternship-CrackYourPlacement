/**
 *  @file: 48. Rotate Image.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/rotate-image
 *  @level: Medium
 *  @date: 02-08-2024
 *
 *  @brief: You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
            You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
            DO NOT allocate another 2D matrix and do the rotation.

            Example 1:                                        Example 2:
            Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]         Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
            Output: [[7,4,1],[8,5,2],[9,6,3]]                 Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            int left = 0, right = n - 1;

            while (left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                
                left++;
                right--;
            }
        }
    }
};