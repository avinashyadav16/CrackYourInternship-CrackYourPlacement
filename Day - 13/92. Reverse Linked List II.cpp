/**
 *  @file: 92. Reverse Linked List II.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/reverse-linked-list-ii/description
 *  @level: Medium
 *  @date: 30-07-2024

 *  @brief: Given the head of a singly linked list and two integers left and right where left <= right,
            reverse the nodes of the list from position left to position right, and return the reversed list.

            Example 1:                                                 Example 2:
            Input: head = [1,2,3,4,5], left = 2, right = 4             Input: head = [5], left = 1, right = 1
            Output: [1,4,3,2,5]                                        Output: [5]
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // Base case: 
        // If the LL is empty OR has only one node
        if (!head || left == right)
        {
            return head;
        }

        // Create a temp node to simplify edge cases where reversing starts from the head
        ListNode *temp = new ListNode(0);
        temp->next = head;
        
        // Initialize pointers to the nodes before the left position
        ListNode *prev = temp;

        for (int i = 1; i < left; ++i)
        {
            prev = prev->next;
        }

        // `start` will point to the first node to be reversed
        ListNode *start = prev->next;

        // `then` will point to the node that will be reversed
        ListNode *then = start->next;

        // Performing the reversal by adjusting pointers
        for (int i = 0; i < right - left; ++i)
        {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        // Return the new head of the list
        return temp->next;
    }
};