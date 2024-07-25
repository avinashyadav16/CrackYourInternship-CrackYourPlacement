/**
 *  @file: 680. Valid Palindrome II.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/valid-palindrome-ii
 *  @level: Easy
 *  @date: 26-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    bool palindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end)
        {
            if (s[start] != s[end])
                return (palindrome(s, start + 1, end) || palindrome(s, start, end - 1));

            start++;
            end--;
        }
        return true;
    }
};