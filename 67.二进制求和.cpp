/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.41%)
 * Likes:    927
 * Dislikes: 0
 * Total Accepted:    293.7K
 * Total Submissions: 549.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:a = "11", b = "1"
 * 输出："100"
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = "1010", b = "1011"
 * 输出："10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a 和 b 仅由字符 '0' 或 '1' 组成
 * 字符串如果不是 "0" ，就不含前导零
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define B(c) ((c) - ('0'))
#define C(b) (char)(('0') + (b))
class Solution {
public:

    string addBinary(string a, string b) {
        int res,ext = 0;
        string ans = "";
        auto pa = a.end()-1, pb = b.end()-1;
        for (; pa >= a.begin() || pb >= b.begin(); pa--, pb--, res=0)
        {
            res += (pa >= a.begin()) ? B(*pa):0;
            res += (pb >= b.begin()) ? B(*pb):0;
            ans = C(( ext + res ) % 2) + ans;
            ext = ( ext + res ) / 2;
        }
        if(ext != 0)
            ans = C(ext) + ans;
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string a = "1010";
    string b = "101";
    string ans = Solution().addBinary(a, b);
    cout<<ans;
    return 0;
}
