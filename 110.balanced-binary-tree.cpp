/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool symmetric_and_depth(TreeNode* root, int &depth){
        if (!root) return true;
        depth += 1;
        int d_left, d_right;
        d_left = d_right = depth;
        if(symmetric_and_depth(root->left, d_left) &&
        symmetric_and_depth(root->right, d_right)){
            depth = d_left > d_right ? d_left : d_right;
            return abs(d_left - d_right) <= 1;
        }else{
            // depth += a > b ? a : b;
            return false;
        }
    }

    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return symmetric_and_depth(root, depth);
    }
};
// @lc code=end

