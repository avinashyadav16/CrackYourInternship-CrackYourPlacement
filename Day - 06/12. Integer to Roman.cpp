/**
 *  @file: 12. Integer to Roman.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/integer-to-roman
 *  @level: Medium
 *  @date: 19-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> mpp = {
            {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}, 
            {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"}, 
            {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"}, 
            {1000, "M"}, {2000, "MM"}, {3000, "MMM"}};

        string num2str = to_string(num);
        string str[num2str.size()];
        int digit = 0;

        for (int i = num2str.size() - 1; i >= 0; i--)
        {
            string temp = "";
            temp += num2str[i];
            int n = stoi(temp) * pow(10, digit++);
            str[i] += mpp[n];
        }

        string res = "";
        
        for (int i = 0; i < num2str.size(); i++)
        {
            res += str[i];
        }
        return res;
    }
};
