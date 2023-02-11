/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].length();
        if (strs.size() <= 1) return strs[0];
        for (int i = 1; i < strs.size(); i++)
            len = min(len, (int)strs[i].length());
        if (len == 0) return "";
        else
        {
            int common_length = 0;
            while (common_length < len){
                int flag = 1;
                for (int i = 1; i < strs.size(); i++)
                {
                    if (strs[i-1][common_length]!= strs[i][common_length])
                    { 
                        flag = 0;
                        break;
                    }
                }
                if(!flag) break;
                common_length++;
            }
            return strs[0].substr(0, common_length);
        }
    }
};
// @lc code=end

