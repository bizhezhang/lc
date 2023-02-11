/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include<bits/stdc++.h>
using namespace std;

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


int main(){
    Solution solution;
    if(solution.isPalindrome(122323221)){
        cout<<"T"<<endl;
    }else{
        cout<<"F"<<endl;
    }
    return 0;
}