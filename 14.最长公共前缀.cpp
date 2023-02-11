/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include<bits/stdc++.h>
using namespace std;

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

int main()
{
    // vector<string> strs = {"hello", "", "hello world", "hello gays"};
    vector<string> strs = {"hello","helo", "hello world"};
    string s = Solution().longestCommonPrefix(strs);
    cout<<s<<endl;
    return 0;
}
