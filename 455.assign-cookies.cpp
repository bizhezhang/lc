/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while(child < g.size() && cookie < s.size())
            if(g[child] <= s[cookie++]) child++;
        return child;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    int a = Solution().findContentChildren(g, s);
    cout<<a<<endl;
    return 0;
}
