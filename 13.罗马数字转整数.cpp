/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashmap={
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            int val = hashmap[s[i]];
            if(i+1<s.size()&&hashmap[s[i+1]]>val) res -= val;
            else res += val; 
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution solution;
    int result = solution.romanToInt("XIII");
    cout<<result<<endl;
}