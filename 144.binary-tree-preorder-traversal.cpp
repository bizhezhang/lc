/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

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
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> res;

    void pt(TreeNode* p){
        if(!p) return;
        res.push_back(p->val);
        pt(p->left);
        pt(p->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        pt(root);
        return res;
    }
};
// @lc code=end

int main(){
    TreeNode* pl = new TreeNode(3, new TreeNode(1), new TreeNode(2));
    TreeNode* pr = new TreeNode(5, nullptr, new TreeNode(6));
    TreeNode* h = new TreeNode(9, pl, pr);
    vector<int> rs = Solution().preorderTraversal(h);
    for(auto e:rs){
        cout<<e<<", ";
    }
    return 0;
}
