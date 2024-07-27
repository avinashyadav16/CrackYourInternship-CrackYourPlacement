/**
 *  @file: 289. Game of Life.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/game-of-life/description
 *  @level: Medium
 *  @date: 26-07-2024
 *
 *  @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int rows;
    int cols;

    // init states: 0 (dead) OR 1 (alive)
    // end states: bit meaning (next state)(current state)
    // 00 -> dead then dead
    // 10 -> dead then alive
    // 01 -> alive then dead
    // 11 -> alive then alive

    void updateState(int i, int j, vector<vector<int>> &board)
    {
        int neighbors = 0;
        for (int x = max(i - 1, 0); x <= min(i + 1, rows - 1); ++x)
        {
            for (int y = max(j - 1, 0); y <= min(j + 1, cols - 1); ++y)
            {
                if (x == i && y == j)
                    continue;

                // Check current state
                neighbors += board[x][y] & 1;
            }
        }

        // Update the next state in the 2nd bit position
        // by default, when we bit shift the value will be 0 since our
        // init state is only 00 or 01

        if ((board[i][j] & 1) && (neighbors == 2 || neighbors == 3))
        {
            // Alive -> Alive
            board[i][j] |= 2;
        }
        else if (!(board[i][j] & 1) && neighbors == 3)
        {
            // Dead -> Alive
            board[i][j] |= 2;
        }
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                updateState(i, j, board);
            }
        }

        // Finalize the board by shifting the next state to the current state position
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                board[i][j] >>= 1;
            }
        }
    }
};