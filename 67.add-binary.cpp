/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

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

