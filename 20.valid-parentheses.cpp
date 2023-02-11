/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++){
            int v = hashmap[s[i]];
            if(v > 0){
                st.push(v);
            }else{
                if(st.empty()) return false;
                if(st.top() + v != 0) return false;
                st.pop();
            }
        }
        return st.empty();
    }
private:
    unordered_map<char,int> hashmap = {
        {'(', 1}, {'{', 2}, {'[', 3},
        {')', -1}, {'}', -2}, {']', -3}
    };
};
// @lc code=end

