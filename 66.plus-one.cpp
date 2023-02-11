/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto ind = (int)digits.size() - 1;
        int res,ext = 0;
        res = (ext+digits[ind]+1) % 10;
        ext = (ext+digits[ind]+1) / 10;
        digits[ind--] = res;
        while (ind >= 0 && ext > 0)
        {
            res = (ext+digits[ind]) % 10;
            ext = (ext+digits[ind]) / 10;
            digits[ind--] = res;
        }
        if(ext > 0)
        {
            digits.insert(digits.begin(), ext);
        }
        return digits;
    }
};
// @lc code=end

