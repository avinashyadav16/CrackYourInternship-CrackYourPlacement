/**
 *  @file: Find the number of islands using DFS_Traverse.cpp
 *  @author: Avinash Yadav
 *  @brief:
 *  @level: Medium
 *  @date: 02-08-2024
 *
 *  @brief: Given a binary 2D matrix, find the number of islands. A group of connected 1s forms an island.
            For example, the below matrix contains 4 islands.

            Example:
            Input: mat[][] = {
                                {1, 1, 0, 0, 0},
                                {0, 1, 0, 0, 1},
                                {1, 0, 0, 1, 1},
                                {0, 0, 0, 0, 0},
                                {1, 0, 1, 0, 0}
                            }
            Output: 4
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to do DFS_Traverse for a 2D boolean matrix. 
// It only considers the 8 neighbours as adjacent vertices
void DFS_Traverse(vector<vector<int>> &mat, int i, int j, int row, int col)
{
    // Base condition
    // if i less than 0 or j less than 0 or i greater than row-1 or j greater than col-  or if mat[i][j] != 1 
    // then we will simply return
    if (i < 0 || j < 0 || i > (row - 1) || j > (col - 1) || mat[i][j] != 1)
    {
        return;
    }

    if (mat[i][j] == 1)
    {
        mat[i][j] = 0;
        
        // right side traversal
        DFS_Traverse(mat, i + 1, j, row, col); 
        
        // left side traversal
        DFS_Traverse(mat, i - 1, j, row, col); 
        
        // upward side traversal
        DFS_Traverse(mat, i, j + 1, row, col); 
        
        // downward side traversal
        DFS_Traverse(mat, i, j - 1, row, col); 
        
        // upward-right side traversal
        DFS_Traverse(mat, i + 1, j + 1, row, col); 
        
        // downward-left side traversal
        DFS_Traverse(mat, i - 1, j - 1, row, col); 
        
        // downward-right side traversal
        DFS_Traverse(mat, i + 1, j - 1, row, col); 
        
        // upward-left side traversal
        DFS_Traverse(mat, i - 1, j + 1, row, col); 
    }
}

int countIslands(vector<vector<int>> &mat)
{
    int row = mat.size(), col = mat[0].size(), count = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 1)
            {
                count++;
                DFS_Traverse(mat, i, j, row, col);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(mat);
    return 0;
}
