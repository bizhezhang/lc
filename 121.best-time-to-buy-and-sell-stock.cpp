/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int his_min = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > his_min){
                maxProfit = prices[i] - his_min > maxProfit ? (prices[i] - his_min) : maxProfit;
            } else {
                his_min = prices[i];
            }
        }
        return maxProfit;
    }
};
// @lc code=end

