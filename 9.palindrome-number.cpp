/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        int t = x % 10;
        while ((x /= 10) > t){
            t = t * 10 + x % 10;
        }
        return t==x or t/10 == x;
    }
};
// @lc code=end

