/**
 *  @file: 83. Remove Duplicates from Sorted List.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;

        while (curr != NULL && curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};