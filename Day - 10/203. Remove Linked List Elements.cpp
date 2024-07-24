/**
 *  @file: 203. Remove Linked List Elements.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/remove-linked-list-elements/description
 *  @level: Easy
 *  @date: 24-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

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
    ListNode *removeElements(ListNode *head, int val)
    {
        // head itself needs to be removed
        while (head != nullptr && head->val == val)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        // The list is now empty
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr != nullptr)
        {
            // If the current node needs to be removed
            if (curr->val == val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
