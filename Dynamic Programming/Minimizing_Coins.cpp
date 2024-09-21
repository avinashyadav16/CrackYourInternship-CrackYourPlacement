/**
*  @file: Minimizing_Coins.cpp
*  @author: Avinash Yadav
*  @link: https://cses.fi/problemset/task/1634
*  @date: 21-09-2024
*  @brief: Consider a money system consisting of n coins. Each coin has a positive integer value.
            Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

            For example:
                If the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

            Input:
                The first input line has two integers n and x: the number of coins and the desired sum of money.
                The second line has n distinct integers c_1,c_2, ... ,c_n: the value of each coin.

            Output:
                Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

            Constraints:
                1 <= n <= 100
                1 <= x <= 10^6
                1 <= c_i <= 10^6

            Example
            Input:
                3 11
                1 5 7

            Output:
                3
*/




#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n, x;
    cout << "Enter n and x: ";
    cin >> n >> x;

    vector<int> coins(n);
    cout << "Enter Coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // Create a dp array to store the minimum number of coins needed for each amount
    // Initialize the dp array with -1 (indicating that no solution exists for that amount yet)
    vector<int> dp(x + 1, -1);

    // Base case: To make the amount 0, you need 0 coins
    dp[0] = 0;

    // Fill the dp array for each amount from 1 to x
    for (int i = 1; i <= x; i++)
    {
        // Check all coin denominations
        for (int j = 0; j < n; j++)
        {
            // If the current coin can be used to form the amount i
            if (i >= coins[j] && dp[i - coins[j]] != -1)
            {
                // If the dp value for current amount 'i' is -1 (no solution yet) or we found a smaller solution
                if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
                {
                    // Update dp[i] with the minimum number of coins
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    cout << "Min Required Coins Are: " << dp[x];

    return 0;
}
