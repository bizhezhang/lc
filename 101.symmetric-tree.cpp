/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool check1(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val &&
        check1(p->left, q->right) &&
        check1(p->right, q->left);
    }

    bool check2(TreeNode* p, TreeNode* q){
        queue<pair<TreeNode*, TreeNode*>> que;
        que.emplace(p, q);
        while(!que.empty()){
            TreeNode* p, *q;
            tie(p, q) = que.front();
            que.pop();
            if(!p && !q) continue;
            if((!p || !q) || (p->val != q->val)) return false;

            que.emplace(p->left, q->right);
            que.emplace(p->right, q->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check2(root, root);
    }
};
// @lc code=end

