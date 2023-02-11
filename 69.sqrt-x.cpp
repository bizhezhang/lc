/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
typedef long long ll;
class Solution {
public:
    int mySqrt(int x) {
        ll low = 0, high = (ll)x;
        ll mid = low + (high - low) / 2;
        while( low < high ){
            if ( mid * mid <= (ll)x && (mid + 1) * (mid + 1) > (ll)x ){
                return (int)mid;
            }
            if ( mid * mid < (ll)x ){
                low = mid + 1;
            }
            if ( mid * mid > (ll)x){
                high = mid - 1;
            }
            mid = low + ( high - low ) / 2;
        }
        return (int)mid;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution ax = Solution();
    for (int a = 0; a < 9; a++){
        int t = ax.mySqrt(a);
        cout<<t<<",";
    }
    return 0;
}
