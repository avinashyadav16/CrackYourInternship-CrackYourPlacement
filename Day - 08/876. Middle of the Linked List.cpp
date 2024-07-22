/**
 *  @file: 876. Middle of the Linked List.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/middle-of-the-linked-list/description
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slowPtr = head, *fastPtr = head;
        while (fastPtr != nullptr && fastPtr->next != nullptr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr;
    }
};