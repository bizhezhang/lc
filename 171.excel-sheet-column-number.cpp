/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    long long titleToNumber(string columnTitle) {
        long long res = 0;
        long long ex = 1;
        for(int i = columnTitle.length()-1; i >= 0; i--){
            res+=(long long)(columnTitle[i]-'A'+1)*ex;
            ex*=26;
        }
        return res;
    }
};
// @lc code=end

int main(){
    cout<<Solution().titleToNumber("ZY")<<endl;
    return 0;
}