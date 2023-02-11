/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        auto ind = (int)s.length() - 1;
        int len = 0;
        while(s[ind] == ' ') ind--;
        while(ind >=0 && s[ind--] != ' ') len++;
        return len;
    }
};
// @lc code=end

