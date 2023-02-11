/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // vector<int> getRow(int rowIndex) {
    //     vector<int> res(rowIndex + 1);
    //     res[0] = 1;
    //     for(int i = 1; i <= rowIndex; i++){
    //         for(int j = i; j > 0; j--){
    //             res[j] += res[j-1];
    //         }
    //     }
    //     return res;
    // }

    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; i++){
            res[i] = 1LL * res[i-1] * (rowIndex - i + 1)/i;
        }
        return res;
    }
};
// @lc code=end

/*
C_n^m = C_n^{m-1} * {n-m+1}/m
*/