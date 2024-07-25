/**
 *  @file: Product array puzzle.cpp
 *  @author: Avinash Yadav
 *  @brief: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
 *  @brief: Easy
 *  @date: 26-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        vector<ll> P(n, 1);

        // Calculate prefix products
        ll prefix = 1;
        for (int i = 0; i < n; i++)
        {
            P[i] = prefix;
            prefix *= nums[i];
        }

        // Calculate suffix products and combine with prefix products
        ll suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            P[i] *= suffix;
            suffix *= nums[i];
        }

        return P;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // size of the array
        int n;
        cin >> n;

        vector<long long int> arr(n), vec(n);

        // input the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n);

        for (int i = 0; i < n; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends