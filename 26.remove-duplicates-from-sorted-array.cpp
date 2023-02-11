/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 1;
        for (int i = 1; i < nums.size(); i++)
            if(nums[i - 1] != nums[i]) nums[ind++] = nums[i];
        return ind;
    }
};
// @lc code=end

