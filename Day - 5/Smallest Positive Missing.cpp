/**
 *  @file: Smallest Positive Missing.cpp
 *  @author: Avinash Yadav
 *  @brief: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
 *  @level: Medium
 *  @date: 18-07-2024
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        sort(arr, arr + n);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == ans)
            {
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends