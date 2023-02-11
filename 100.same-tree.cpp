/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(!p && !q) return true;
    //     if(!p || !q) return false;
    //     return (p->val == q->val && 
    //     isSameTree(p->left, q->left) && 
    //     isSameTree(p->right, q->right));
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*,TreeNode*>> stk;
        stk.emplace(p, q);
        while (!stk.empty())
        {
            // auto [p, q] = stk.top();
            TreeNode *p, *q;
            tie(p, q) = stk.top();
            stk.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            stk.emplace(p->left, q->left);
            stk.emplace(p->right, q->right);
        }
        return true;
    }
};
// @lc code=end

