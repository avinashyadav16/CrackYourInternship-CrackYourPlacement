/**
 *  @file: 100. Same Tree.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/same-tree/description
 *  @level: Easy
 *  @date: 31-07-2024

 *  @brief: Given the roots of two binary trees p and q, write a function to check if they are the same or not.
            Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

        Example 1:                              Example 2:                                Example 3:
        Input: p = [1,2,3], q = [1,2,3]         Input: p = [1,2], q = [1,null,2]          Input: p = [1,2,1], q = [1,1,2]
        Output: true                            Output: false                             Output: false
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/**
 * Definition for a binary tree node.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
