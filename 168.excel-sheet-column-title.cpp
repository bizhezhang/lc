/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0){
            cout<<columnNumber<<endl;
            char ch = (char)('A' + (columnNumber - 1) % 26);
            res = ch + res;
            if (columnNumber > 26){
                columnNumber = (columnNumber - (int)(ch - 'A' + 1)) / 26;
            }else{
                break;
            }
        }
        return res;
    }
};
// @lc code=end

int main(){
    cout<<Solution().convertToTitle(79)<<endl;
    return 0;
}