/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define digit(c) ((c)>='0' && (c)<='9')
#define lower(c) ((c)>='a' && (c)<='z')
#define upper(c) ((c)>='A' && (c)<='Z')
class Solution {
public:
    bool equal_char(char a, char b){
        if (a == b) return true;
        if (!digit(a) && !digit(b)){
            if(lower(a)) a -= ('a'-'A');
            if(lower(b)) b -= ('a'-'A');
            return a==b;
        }
        return false;
    }

    bool valid_char(char a){
        return digit(a) || lower(a) || upper(a);
    }

    bool isPalindrome(string s) {
        int i = 0, j = (int)s.length() - 1;
        while(i < j){
            if(!valid_char(s[i])){
                i++;
                continue;
            }
            if(!valid_char(s[j])){
                j--;
                continue;
            }
            if(!equal_char(s[i], s[j])){
                return false;
            }
            i++;j--;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    cout<<Solution().isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
