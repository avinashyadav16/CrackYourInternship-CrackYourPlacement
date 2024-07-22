/**
 *  @file: 1290. Convert Binary Number in a Linked List to Integer.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
 *  @level: Easy
 *  @date: 22-07-2024
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
    int getDecimalValue(ListNode *head)
    {
        int num = 0;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            // Step 1: Left shift num by 1 bit to make room for the next bit.
            //         It doubles the current value of num and adds a 0 at the rightmost bit.
            // Step 2: Using the bitwise OR operator to add the current node's value (currentNode->val) to num.

            num = (num << 1) | curr->val;
            curr = curr->next;
        }

        return num;
    }
};
