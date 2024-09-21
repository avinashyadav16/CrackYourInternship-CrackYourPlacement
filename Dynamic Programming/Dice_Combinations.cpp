/**
*  @file: Dice_Combinations.cpp
*  @author: Avinash Yadav
*  @date: 21-09-2024
*  @link: https://cses.fi/problemset/task/1633
*  @brief: Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
            Each throw produces an outcome between 1 and  6.
            For example:
                If n=3, there are 4 ways:
                    1+1+1
                    1+2
                    2+1
                    3

            Input: The only input line has an integer n.
            Output: Print the number of ways modulo 10^9+7.
            Constraints: 1 <= n <= 10^6

            Example
            Input:  3
            Output: 4
*/




#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cout << "Enter The Value of n: ";
    cin >> n;

    int mod = 1e9 + 7; 

    // Create a dp array to store the number of ways to get each sum from 0 to n
    // Initialize dp array of size n+1, all values set to 0
    vector<int> dp(n + 1, 0); 

    // Base case
    // There's exactly one way to achieve sum 0 (by not rolling any dice)
    dp[0] = 1; 


    // For each sum i from 1 to n, calculate how many ways we can achieve it
    for (int i = 1; i <= n; i++)
    {
        // For each possible dice roll j (1 to 6)
        // We check if we can use the previous dp values to form the current sum
        for (int j = 1; j <= 6 && j <= i; j++)
        {
            // Add the number of ways to get sum `i-j` to dp[i], because rolling j will add up to `i`
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }


    // dp[n] now contains the number of ways to achieve the sum n
    cout << "Number of ways: " << dp[n];

    return 0;
}
