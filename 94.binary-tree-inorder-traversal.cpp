/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> vis;
        while(!vis.empty() || root){
            while(root){
                vis.push(root);
                root = root->left;
            }
            root = vis.top();
            res.push_back(root->val);
            vis.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    TreeNode a(1), b(2), c(3);
    a.right = &b;
    b.left = &c;
    TreeNode *root = &a;
    vector<int> re = Solution().inorderTraversal(root);
    return 0;
}
