/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* helpper(vector<int>& nums, int idx1, int idx2){
        if (idx1 > idx2) return nullptr;
        int mid = (idx1 + idx2) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helpper(nums, idx1, mid - 1);
        root->right = helpper(nums, mid + 1, idx2);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helpper(nums, 0, nums.size() - 1ll);
    }
};
// @lc code=end
