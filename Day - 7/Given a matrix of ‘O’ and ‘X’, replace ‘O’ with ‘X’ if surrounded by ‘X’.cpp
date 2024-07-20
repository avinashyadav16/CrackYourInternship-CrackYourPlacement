/**
 *  @file: Given a matrix of ‘O’ and ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’.cpp
 *  @author: Avinash Yadav
 *  @brief: https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x
 *  @date: 21-07-2024
 */

// Input : mat[M][N] =
//              {
//                  {‘X’, ‘O’, ‘X’, ‘X’, ‘X’, ‘X’},
//                  {‘X’, ‘O’, ‘X’, ‘X’, ‘O’, ‘X’},
//                  {‘X’, ‘X’, ‘X’, ‘O’, ‘O’, ‘X’},
//                  {‘O’, ‘X’, ‘X’, ‘X’, ‘X’, ‘X’},
//                  {‘X’, ‘X’, ‘X’, ‘O’, ‘X’, ‘O’},
//                  {‘O’, ‘O’, ‘X’, ‘O’, ‘O’, ‘O’}
//              };

// Output : mat[M][N] =
//              {
//                  {‘X’, ‘O’, ‘X’, ‘X’, ‘X’, ‘X’},
//                  {‘X’, ‘O’, ‘X’, ‘X’, ‘X’, ‘X’},
//                  {‘X’, ‘X’, ‘X’, ‘X’, ‘X’, ‘X’},
//                  {‘O’, ‘X’, ‘X’, ‘X’, ‘X’, ‘X’},
//                  {‘X’, ‘X’, ‘X’, ‘O’, ‘X’, ‘O’},
//                  {‘O’, ‘O’, ‘X’, ‘O’, ‘O’, ‘O’}
//              };

// Approach: Using Flood-Fill Algorithm and DFS
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Size of given matrix is M X N
#define M 6
#define N 6

// A recursive function to replace previous value 'prevV' at '(x, y)'
// and all surrounding values of (x, y) with new value 'newV'.
void floodFillUtil(char mat[][N], int x, int y, char prevV, char newV)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (mat[x][y] != prevV)
        return;

    // Replace the color at (x, y)
    mat[x][y] = newV;

    // Recur for north, east, south and west
    floodFillUtil(mat, x + 1, y, prevV, newV);
    floodFillUtil(mat, x - 1, y, prevV, newV);
    floodFillUtil(mat, x, y + 1, prevV, newV);
    floodFillUtil(mat, x, y - 1, prevV, newV);
}

// Returns size of maximum size subsquare matrix surrounded by 'X'
int replaceSurrounded(char mat[][N])
{
    // Step 1: Replace all 'O' with '-'
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-';

    // Call floodFill for all '-' lying on edges

    // Left side
    for (int i = 0; i < M; i++)
        if (mat[i][0] == '-')
            floodFillUtil(mat, i, 0, '-', 'O');

    // Right side
    for (int i = 0; i < M; i++)
        if (mat[i][N - 1] == '-')
            floodFillUtil(mat, i, N - 1, '-', 'O');

    // Top side
    for (int i = 0; i < N; i++)
        if (mat[0][i] == '-')
            floodFillUtil(mat, 0, i, '-', 'O');

    // Bottom side
    for (int i = 0; i < N; i++)
        if (mat[M - 1][i] == '-')
            floodFillUtil(mat, M - 1, i, '-', 'O');

    // Step 3: Replace all '-' with 'X'
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
}

int main()
{
    char mat[][N] = {
        {'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
    };

    replaceSurrounded(mat);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
