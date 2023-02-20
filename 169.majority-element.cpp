/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majoriry;
        for(int num: nums){
            if(!counter) majoriry = num;
            counter += (majoriry == num)? 1 : -1;
        }
        return majoriry;
    }
};
// @lc code=end
/*

*/
