/**
 *  @file: 234. Palindrome Linked List.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/palindrome-linked-list/description/
 *  @level: Easy
 *  @date: 21-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        stack<int> st;

        while (temp != NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (!st.empty())
        {
            if (st.top() != temp->val)
                return false;

            temp = temp->next;
            st.pop();
        }
        return true;
    }
};