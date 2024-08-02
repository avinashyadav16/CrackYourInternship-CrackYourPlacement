/**
*  @file: Maximum size rectangle binary sub-matrix with all 1s.cpp
*  @author: Avinash Yadav
*  @brief: https://geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s
*  @level: Medium
*  @date: 02-08-2024

*  @brief: Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

            Example: 01                                                     Example: 02

            Input:                                                          Input:
            0 1 1 0                                                         0 1 1
            1 1 1 1                                                         1 1 1
            1 1 1 1                                                         0 1 1
            1 1 0 0

            Output :                                                        Output:
            8                                                               6

            Explanation :                                                   Explanation :
            The largest rectangle with only 1's is from                     The largest rectangle with only 1's is from
            (1, 0) to (2, 3) which is                                       (0, 1) to (2, 2) which is
            1 1 1 1                                                         1 1
            1 1 1 1                                                         1 1
                                                                            1 1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return 0;
    }

    int row = matrix.size(), col = matrix[0].size();

    vector<int> left(col, 0);
    vector<int> right(col, col);
    vector<int> height(col, 0);

    int maxArea = 0;

    for (const auto &row : matrix)
    {
        int curLeft = 0, curRight = col;

        // Updating height array
        for (int j = 0; j < col; j++)
        {
            if (row[j] == '1')
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }

        // Updating left boundary array
        for (int j = 0; j < col; j++)
        {
            if (row[j] == '1')
            {
                left[j] = max(left[j], curLeft);
            }
            else
            {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        // Updating right boundary array
        for (int j = col - 1; j >= 0; j--)
        {
            if (row[j] == '1')
            {
                right[j] = min(right[j], curRight);
            }
            else
            {
                right[j] = col;
                curRight = j;
            }
        }

        // Maximum area for each cell
        for (int j = 0; j < col; j++)
        {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }

    return maxArea;
}

int main()
{
    vector<vector<char>> matrix1 = {
        {'0', '1', '1', '0'},
        {'1', '1', '1', '1'},
        {'1', '1', '1', '1'},
        {'1', '1', '0', '0'}};

    cout << maximalRectangle(matrix1) << endl;

    return 0;
}