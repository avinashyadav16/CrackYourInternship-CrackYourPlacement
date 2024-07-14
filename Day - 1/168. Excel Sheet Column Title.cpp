/**
 *  @file: 168. Excel Sheet Column Title.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/excel-sheet-column-title/
 *  @level: Easy
 *  @date: 14-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res = "";
        while (columnNumber != 0)
        {
            --columnNumber;
            res += static_cast<int>((columnNumber % 26) + 'A');
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};