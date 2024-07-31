/**
 *  @file: 617. Merge Two Binary Trees.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/merge-two-binary-trees
 *  @level: Easy
 *  @date: 31-07-2024
 
 *  @brief: You are given two binary trees root1 and root2.
            Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. 
            You need to merge the two trees into a new binary tree. 
            The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
            Otherwise, the NOT null node will be used as the node of the new tree.
            
            Return the merged tree.
            
            Note: The merging process must start from the root nodes of both trees.

            Example 1:                                                                  Example 2:
            Input: root1 = [1,3,2,5],                                                   Input: root1 = [1],
                   root2 = [2,1,3,null,4,null,7]                                               root2 = [1,2]                                                
            Output: [3,4,5,5,4,null,7]                                                 Output: [2,2]                
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return 0;
        }

        if (root1 == NULL)
        {
            return root2;
        }
        else if (root2 == NULL)
        {
            return root1;
        }
        else
        {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }
        return root1;
    }
};