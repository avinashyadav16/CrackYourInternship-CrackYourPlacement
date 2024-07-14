/**
 *  @file: 67. Add Binary.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/add-binary
 *  @level: Easy
 *  @date: 14-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        // Initialize the result string
        string result = ""; 
        
        // Initialize carry to 0
        int carry = 0;      

        // Get the last index of string a
        int n = a.size() - 1; 
        
        // Get the last index of string b
        int m = b.size() - 1; 

        // Loop until all bits are processed or there is no carry left
        while (n >= 0 || m >= 0 || carry > 0)
        {
            // Get the current bit of a or 0 if n is out of bounds
            int bitA = (n >= 0) ? a[n--] - '0' : 0;
            // Get the current bit of b or 0 if m is out of bounds
            int bitB = (m >= 0) ? b[m--] - '0' : 0;

            // Compute the sum of the current bits and carry
            int sum = bitA ^ bitB ^ carry;
            // Update the carry
            carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);

            // Append the current bit result to the result string
            result += (sum + '0');
        }

        // Reverse the result string to get the correct binary sum
        reverse(result.begin(), result.end());

        return result;
    }
};
