/**
 *  @file: 628. Maximum Product of Three Numbers.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/maximum-product-of-three-numbers/description
 *  @level: Easy
 *  @date: 30-07-2024

 *  @brief: Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

                Example 1:                              Example 2:                         Example 3:
                Input: nums = [1,2,3]                   Input: nums = [1,2,3,4]            Input: nums = [-1,-2,-3]
                Output: 6                               Output: 24                         Output: -6
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;





// Method: 01
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        // Calculate the product of the three largest numbers
        int max1 = nums[size - 1] * nums[size - 2] * nums[size - 3];

        // Calculate the product of the two smallest and the largest number
        int max2 = nums[0] * nums[1] * nums[size - 1];

        return max(max1, max2);
    }
};



// Method: 02
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        // Initializing the three largest numbers to minimum possible values
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        // Initializing the two smallest numbers to maximum possible values
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int num : nums)
        {
            // Updating the largest numbers
            if (num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3)
            {
                max3 = num;
            }

            // Updating the smallest numbers
            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min2 = num;
            }
        }

        int product1 = max1 * max2 * max3;
        int product2 = min1 * min2 * max1;

        return max(product1, product2);
    }
};