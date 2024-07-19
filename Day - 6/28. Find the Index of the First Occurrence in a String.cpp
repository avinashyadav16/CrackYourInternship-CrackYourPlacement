/**
 *  @file: 28. Find the Index of the First Occurrence in a String.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
 *  @level: Easy
 *  @date: 19-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int hSize = haystack.size(), nSize = needle.size();
        if (hSize < nSize)
            return -1;

        int start = 0, end = 0, resultIndex = -1;
        string currentWindow = "";
        while (end < hSize)
        {
            currentWindow += haystack[end];
            if (end - start + 1 == nSize)
            {
                if (currentWindow == needle)
                {
                    resultIndex = start;
                    break;
                }
                else
                {
                    start++;
                    currentWindow.erase(currentWindow.begin() + 0);
                }
            }
            end++;
        }
        return resultIndex;
    }
};

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};