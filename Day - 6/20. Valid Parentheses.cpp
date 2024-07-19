/**
 *  @file: 20. Valid Parentheses.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/valid-parentheses
 *  @level: Easy
 *  @date: 19-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Vector Appraoch:
class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.length();
        if (size & 1)
            return false;
        else
        {
            vector<char> vec;
            int top = -1;
            for (int i = 0; i < size; i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    vec.push_back(s[i]);
                }
                else
                {
                    if (vec.empty())
                    {
                        return false;
                    }
                    char top = vec.back();
                    vec.pop_back();

                    if ((s[i] == ')' && top != '(') ||
                        (s[i] == ']' && top != '[') ||
                        (s[i] == '}' && top != '{'))
                    {
                        return false;
                    }
                }
            }
            return vec.empty();
        }
    }
};

// Stack Approach:
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (auto ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty() ||
                    (ch == ')' && st.top() != '(') ||
                    (ch == '}' && st.top() != '{') ||
                    (ch == ']' && st.top() != '['))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
