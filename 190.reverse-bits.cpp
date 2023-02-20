/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int dc = 0;
        while(++dc <= 32){
            res = res * 2 + n % 2;
            n /= 2;
        }
        return res;
    }
};
// @lc code=end

int main(){
    uint32_t n = 0b11111111111111111111111111111101;
    cout<<Solution().reverseBits(n);
    return 0;
}