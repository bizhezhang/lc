/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode.cn/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.43%)
 * Likes:    1138
 * Dislikes: 0
 * Total Accepted:    577.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = [0]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

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


int main(int argc, char const *argv[])
{
    vector<int> dig = {1,9,9};
    dig = Solution().plusOne(dig);
    for (int i = 0; i < dig.size(); i++)
    {
        cout<<dig[i];
    }
    
    return 0;
}
