/**
 *  @file: 206. Reverse Linked List.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/reverse-linked-list/
 *  @level: Easy
 *  @date: 15-07-2024
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
};