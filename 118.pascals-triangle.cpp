/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (size_t i = 0; i < numRows; i++){
            vector<int> t(i+1, 1);
            if(i>1){
                for (size_t j = 1; j < i; j++){
                    t[j] = res[i-1][j] + res[i-1][j-1];
                }
            }
            res.push_back(t);
        }
        return res;
    }
};
// @lc code=end

