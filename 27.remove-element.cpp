/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val)
            {
                int alt = n-1;
                while(alt > i && nums[alt] == val){
                    alt--;
                    n--;
                }
                nums[i] = nums[alt];
                n--;
            }
            
        }
        return n;
    }
};
// @lc code=end

