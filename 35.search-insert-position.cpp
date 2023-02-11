/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        int mid = (low + high) / 2;
        while(low < high){
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                high = mid - 1;
            if(nums[mid] < target)
                low = mid + 1;
            mid = (low + high) / 2;
        }
        return mid < nums.size() && nums[mid] < target ? mid + 1 : mid;
    }
};
// @lc code=end

