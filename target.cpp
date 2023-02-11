/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Candy
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
    int candy(vector<int> ratings){
        int num = ratings.size();
        if(num < 2) return num;
        vector<int> regard(num, 1);
        for(int i = 1; i < num; i++){
            if(ratings[i] > ratings[i - 1]){
                regard[i] = regard[i - 1] + 1;
            }
        }
        for(int i =  num - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && regard[i] <= regard[i + 1]){
                regard[i] = regard[i + 1] + 1;
            }
        }
        return accumulate(regard.begin(), regard.end(), 0);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> score = {1,0,1};
    int c = Solution().candy(score);
    cout<<c<<endl;
    return 0;
}
