/**
*  @file: 11. Container With Most Water.cpp
*  @author: Avinash Yadav
*  @brief: https://leetcode.com/problems/container-with-most-water/description
*  @brief: Medium
*  @date: 01-08-2024
*
*  @brief:  You are given an integer array height of length n.
            There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
            Find two lines that together with the x-axis form a container, such that the container contains the most water.
            Return the maximum amount of water a container can store.
            Notice that you may not slant the container.

            Example 1:                                                                                         Example 2:
            Input: height = [1,8,6,2,5,4,8,3,7]                                                                Input: height = [1,1]
            Output: 49                                                                                         Output: 1
            Explanation: The vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
                         In this case, the max area of water (8 - 7) the container can contain is 49.



*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1; 
        int max_area = 0;           

        while (left < right)
        {
            int currWidth = right - left;
            int current_area = min(height[left], height[right]) * currWidth;
            max_area = max(max_area, current_area);

            // Move the pointer that points to the shorter line inward for the case of max area:
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max_area;
    }
};